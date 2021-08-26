#pragma once
#include "PacketHandler.h"
#include "User.h"
#include "PacketProcessThread.h"
#include "LoginProcess.h"
#include "TetrisProcess.h"
#include <vector>


enum ProcessType {
	PROCESS_LOGIN,
	PROCESS_LOBBY,
	PROCESS_GAME
};

class Server : public PacketHandler {
public:
	Server();
	void Run(int listeningPort);
	bool ChangeProcess(ProcessPtr prevProcess, int changeProcessType, UserList users);
private:
	UserPtr _GetUser(int socket);
	UserPtr _CreateUser(int socket);
	void _AddEpoll(UserPtr data);
	int _AcceptSocket(int socket);
	void _AcceptConnection(int socket);
	void _Init();

private:
	PacketProcessThread _packetThread;
	LoginProcessor _loginProcessor;
	TetrisProcessor _tetrisProcessor;

	std::vector<UserPtr> _users;
	int _epollFileDescrtion;
};


