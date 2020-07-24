#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <string.h>
#include "CompletionQue.h"
#include <errno.h>
#include "protocol.h"
#include "Server.h"
#define EPOLL_SIZE 50
#define USER_SIZE 20
using namespace std;

Server::Server() {
	_cons.reserve(USER_SIZE);
}

Connection* Server::GetConnection(int socket){
	for (Connection* con : _cons) {
		if (con->GetSocket() == socket) {
			return con;
		}
	}

	return nullptr;
}


Connection* Server::NewConnection(int socket){
	if (GetConnection(socket) != nullptr) {
		return nullptr;
	}

	Connection* con = new Connection;
	con->SetSocket(socket);
	_cons.push_back(con);
	return con;
}

void setnonblockingmode(int fd) {
	int flag=fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flag|O_NONBLOCK);
}

void Server::OnPacket(Packet packet) {
	auto con = packet.GetConnection();
	switch(packet.GetType()) {
		case C_LOGIN:
			{
				UserPtr user = con->GetUser(); 
				if (!user)
				{
					user = NewUser(con);
					LocalPtr lobby = GetLobby();
					if (lobby) {
						lobby->Enter(user);
					}

					game::s_login loginPacket;
					loginPacket.set_id(0);
					loginPacket.set_name("temp");

					con->SendPacket<game::s_login>(S_LOGIN, &loginPacket);
				}
				return;
			}
			break;
	}

	UserPtr user = con->GetUser();
	if (user) {
		if (user->OnPacket(packet)) {
			return;
		}
	}
}

UserPtr Server::NewUser(Connection *con) {
	return UserPtr(new User());
}
void Server::Run(int listeningPort) {

	int listenSocket;
	int connectedSocket;

	struct sockaddr_in listenAddr;
	struct sockaddr_in connectedAddr;

	listenSocket = socket(PF_INET, SOCK_STREAM, 0);
	memset(&listenAddr, 0, sizeof(listenAddr));
	listenAddr.sin_family =AF_INET;
	listenAddr.sin_addr.s_addr= htonl(INADDR_ANY);
	listenAddr.sin_port = htons(listeningPort);

	if (bind(listenSocket, (struct sockaddr*)&listenAddr, sizeof(listenAddr)) == -1)
	{
		printf("error Bind : %d", listeningPort);
		return;
	}

	if (listen(listenSocket,5)==1)
	{
		printf("error Handling");
		return;
	}

	_packetThread.Run(2, std::bind(&Server::OnPacket, this, std::placeholders::_1));
	setnonblockingmode(listenSocket);

	struct epoll_event stEvent;
	stEvent.events = EPOLLIN;
	stEvent.data.ptr = &userLogin;

	int epfd = epoll_create(EPOLL_SIZE);
	epoll_ctl(epfd, EPOLL_CTL_ADD, listenSocket, &stEvent);

	char buf[BUF_SIZE];
	int eventCnt = 0;
	struct epoll_event *epEvents=(struct epoll_event*)malloc(sizeof(struct epoll_event) * EPOLL_SIZE);
	
	while(1)
	{
		printf("OnWiat%d\n", errno);
		eventCnt = epoll_wait(epfd, epEvents, EPOLL_SIZE, -1);
		printf("New Epoll%d\n", eventCnt);
		if (eventCnt == -1) {
			printf("onError epoll");
			break;
		}

		for (int i =0; i < eventCnt; ++i) {
			if (epEvents[i].data.ptr == &userLogin) {

				socklen_t addrSize = sizeof(connectedAddr);
				connectedSocket = accept(listenSocket, (struct sockaddr*)&connectedAddr, &addrSize);
				setnonblockingmode(connectedSocket);

				Connection* con = NewConnection(connectedSocket);
				if (!con) {
					printf("already exist : %d\n", connectedSocket);
					continue;
				}

				struct epoll_event stEvent;
				stEvent.events = EPOLLIN|EPOLLET;
				stEvent.data.ptr = con;

				printf("connected client socket: %d\n", con->GetSocket());
				epoll_ctl(epfd, EPOLL_CTL_ADD, connectedSocket, &stEvent);

			} else {
				printf("%d\n", ((Connection *)epEvents[i].data.ptr)->GetSocket());
				CompletionQue::GetInstance()->Add((Connection *)epEvents[i].data.ptr);
			}

		}
	}

	close(listenSocket);
	close(epfd);
}

LocalPtr Server::GetLobby(){
	return LocalPtr();
}
