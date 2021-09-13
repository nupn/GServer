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
	_loginProcessor.Init(this);
	_tetrisProcessor.Init(this);
	_lobbyProcessor.Init(this);
}

void setnonblockingmode(int fd) {
	int flag=fcntl(fd, F_GETFL, 0);
	fcntl(fd, F_SETFL, flag|O_NONBLOCK);
}

void Server::Run(int listeningPort) {


	//_packetThread.Run(2, std::bind(&Server::OnPacket, this, std::placeholders::_1));
	_packetThread.Run(2);

	_listeningPort = listeningPort;
	_epollFileDescrtion = epoll_create(EPOLL_SIZE);
	
	/*
	struct epoll_event stEvent;
	stEvent.events = EPOLLIN|EPOLLET;
	stEvent.data.ptr = NULL;
	epoll_ctl(_epollFileDescrtion, EPOLL_CTL_ADD, listenSocket, &stEvent);
	*/
	struct epoll_event *epEvents = (struct epoll_event*) malloc(sizeof(struct epoll_event) * EPOLL_SIZE);

	thread listenThread(&Server::Listening, this);

	while(1)
	{
		int eventCnt = epoll_wait(_epollFileDescrtion, epEvents, EPOLL_SIZE, -1);
		printf("New Epoll%d\n", eventCnt);

		if (eventCnt == -1) {
			if (errno == EINTR) {
				continue;
			}

			printf("onError epoll\n");
			break;
		}

		for (int i =0; i < eventCnt; ++i) {
			if (epEvents[i].data.ptr == NULL) {
			} else {
				User *user = (User *)epEvents[i].data.ptr;
				CompletionQue::GetInstance()->Add(user->GetSharedPtr());
			}

		}
	}

	close(_epollFileDescrtion);
	listenThread.join();
}

void Server::Listening() {	
	printf("listening to %d\n", _listeningPort);	
	int listenSocket = socket(PF_INET, SOCK_STREAM, 0);

	struct sockaddr_in listenAddr;
	memset(&listenAddr, 0, sizeof(listenAddr));
	listenAddr.sin_family =AF_INET;
	listenAddr.sin_addr.s_addr= htonl(INADDR_ANY);
	listenAddr.sin_port = htons(_listeningPort);

	if (bind(listenSocket, (struct sockaddr*)&listenAddr, sizeof(listenAddr)) == -1)
	{
		printf("error Bind : %d", _listeningPort);
		return;
	}

	if (listen(listenSocket,5)==1)
	{
		printf("error Handling");
		return;
	}
	
	setnonblockingmode(listenSocket);

	struct sockaddr_in clientAddr;
	socklen_t clientAddrSize = sizeof(clientAddr);
	while(1)
	{
		_CloseUnuseConnection();

		int clientSocket = accept(listenSocket, (struct sockaddr*)&clientAddr, &clientAddrSize);
		if (clientSocket != -1) {
			_NewConnection(clientSocket);
		}

		this_thread::sleep_for(chrono::milliseconds(10));
	}
	
	close(listenSocket);
}

void Server::_CloseUnuseConnection() {
	for (auto i = begin(_users); i != end(_users);) {
		auto user = *i;
		if (user->CloseReserved()) { 
			int clientSocket = user->GetSocket();
			user->CloseConnection();
			auto processSharePtr = user->GetProcess().lock();
			processSharePtr->LeaveUser(user);
			printf("close User socket(%d)\n", user->GetSocket());
			i = _users.erase(i);
			close(clientSocket);
			epoll_ctl(_epollFileDescrtion, EPOLL_CTL_DEL, user->GetSocket(), NULL);//
		} else {
		   i++;
		}
	}

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

void Server::_NewConnection(int clientSocket) {
	UserPtr user = _CreateUser(clientSocket);
	if (!user) {
		return;
	}

	printf("connected client socket: %d\n", clientSocket);
	setnonblockingmode(clientSocket);
	ChangeProcess(nullptr, ProcessType::PROCESS_LOGIN, user);
	_AddEpoll(user);
}

bool Server::ChangeProcess(ProcessPtr prevProcess, int changeProcessType, UserPtr users) {
	if (prevProcess) {
		prevProcess->LeaveUser(users);
	}

	switch (changeProcessType) {
		case ProcessType::PROCESS_LOGIN:
			return _loginProcessor.JoinUser(users);
		case ProcessType::PROCESS_LOBBY:
			return _lobbyProcessor.JoinUser(users);
			break;
		case ProcessType::PROCESS_GAME:
			return _tetrisProcessor.JoinUser(users);
		default:
			break;
	}

	return false;
}
