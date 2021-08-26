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
	_Init();
}

void Server::_Init() {
	_users.reserve(USER_SIZE);
	_loginProcessor.Init(this);
	_tetrisProcessor.Init(this);
}

void setnonblockingmode(int fd) {
	int flag=fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flag|O_NONBLOCK);
}

void Server::Run(int listeningPort) {
	
	int listenSocket = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in listenAddr;
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

	_epollFileDescrtion = epoll_create(EPOLL_SIZE);
	_AddEpoll(NULL); // NULL mean ConnectSocket

	struct epoll_event *epEvents = (struct epoll_event*) malloc(sizeof(struct epoll_event) * EPOLL_SIZE);
	
	while(1)
	{
		int eventCnt = epoll_wait(_epollFileDescrtion, epEvents, EPOLL_SIZE, -1);
		printf("New Epoll%d\n", eventCnt);

		if (eventCnt == -1) {
			if (errno == EINTR) {
				continue;
			}

			printf("onError epoll");
			break;
		}

		for (int i =0; i < eventCnt; ++i) {
			if (epEvents[i].data.ptr == NULL) {
				_AcceptConnection(listenSocket);
			} else {
				User *user = (User *)epEvents[i].data.ptr;
				CompletionQue::GetInstance()->Add(user->GetSharedPtr());
			}

		}
	}

	close(listenSocket);
	close(_epollFileDescrtion);
}

UserPtr Server::_GetUser(int socket) {
	for (UserPtr user : _users) {
		if (user->GetSocket() == socket) {
			return user;
		}
	}

	return nullptr;
}

UserPtr Server::_CreateUser(int socket){
	if (_GetUser(socket) != nullptr) {
		printf("already exist : %d\n", socket);
		return nullptr;
	}

	UserPtr user = std::make_shared<User>(socket);
	_users.push_back(user);

	printf("new User");
	return user;
}

void Server::_AddEpoll(UserPtr user) {
	struct epoll_event stEvent;
	stEvent.events = EPOLLIN|EPOLLET;
	stEvent.data.ptr = user.get();
	epoll_ctl(_epollFileDescrtion, EPOLL_CTL_ADD, user->GetSocket(), &stEvent);
}

int Server::_AcceptSocket(int socket) {
	struct sockaddr_in connectedAddr;
	socklen_t addrSize = sizeof(connectedAddr);
	int connectedSocket = accept(socket, (struct sockaddr*)&connectedAddr, &addrSize);
	setnonblockingmode(connectedSocket);

	printf("connected client socket: %d\n", connectedSocket);
	return connectedSocket;
}

void Server::_AcceptConnection(int socket) {
	int connectSocket = _AcceptSocket(socket);
	UserPtr user = _CreateUser(connectSocket);
	if (!user) {
		return;
	}

	ChangeProcess(nullptr, ProcessType::PROCESS_LOGIN, {user});
	_AddEpoll(user);
}

bool Server::ChangeProcess(ProcessPtr prevProcess, int changeProcessType, UserList users)
{
	if (prevProcess) {
		//prevProcess->LeaveUser(users);
	}

	switch (changeProcessType) {
		case ProcessType::PROCESS_LOGIN:
			//return _loginProcessor.JoinUser(users);
		case ProcessType::PROCESS_LOBBY:
			break;
		case ProcessType::PROCESS_GAME:
			//return _tetrisProcessor.JoinUser(users);
		default:
			break;
	}

	return false;
}
