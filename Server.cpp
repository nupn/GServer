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
#include "Macro.h"
#include "LoginLocal.h"
#include "LobbyLocal.h"

#define EPOLL_SIZE 50
#define USER_SIZE 20
using namespace std;

Server::Server() {
	_cons.reserve(USER_SIZE);
	_login = std::dynamic_pointer_cast<Local>(std::make_shared<LoginLocal>());

	const int lobbySize = 5;
	for (int i = 0; i < lobbySize; ++i ) {
		auto lobby = std::dynamic_pointer_cast<Local>(std::make_shared<LobbyLocal>());
		lobby->SetServer(this);
		_lobbys.push_back(lobby);
	}
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
	//localChanget(LocalType::LOCAL_TYPE_LOGIN);
	con->SetSubHandler(_login);
	_cons.push_back(con);

	printf("new Connection");
	return con;
}

void setnonblockingmode(int fd) {
	int flag=fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flag|O_NONBLOCK);
}

UserPtr Server::NewUser(Connection *con) {
	return UserPtr(new User());
}

void Server::Run(int listeningPort) {

	_login->SetServer(this);
	
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

	//_packetThread.Run(2, std::bind(&Server::OnPacket, this, std::placeholders::_1));
	_packetThread.Run(2);
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
		printf("OnWait%d\n", errno);
		eventCnt = epoll_wait(epfd, epEvents, EPOLL_SIZE, -1);
		
		int err = errno;
		printf("errono %d\n", err);
		printf("New Epoll%d\n", eventCnt);
		if (eventCnt == -1) {
			if (err == EINTR) {
				continue;
			}

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

void Server::LocalChange(LocalType localType, UserPtr user) {
	switch(localType) {
		case LocalType::LOCAL_TYPE_LOGIN:
			{
				_login->Enter(user);
			}
			break;
		case LocalType::LOCAL_TYPE_LOBBY:
			{
				VEC_FOR(_lobbys) {
					if (!(*iter)->IsFull()) {
						(*iter)->Enter(user);
					}
				}
			}
			break;
		default:
			break;
	}	
}
