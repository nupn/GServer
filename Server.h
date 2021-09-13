#pragma once
#include "PacketHandler.h"
#include "User.h"
#include "PacketProcessThread.h"
#include "LoginProcess.h"
#include "LobbyProcess.h"
#include "TetrisProcess.h"
#include <list>


enum ProcessType {
	PROCESS_LOGIN,
	PROCESS_LOBBY,
	PROCESS_GAME
};

class Server : public PacketHandler {
public:
	Server();
	void Run(int listeningPort);
	bool ChangeProcess(ProcessPtr prevProcess, int changeProcessType, UserPtr users);
	void Listening();
private:
	UserPtr _GetUser(int socket);
	UserPtr _CreateUser(int socket);
	void _AddEpoll(UserPtr data);
	void _NewConnection(int socket);
	void _Init();
	void _CloseUnuseConnection();

private:
	PacketProcessThread _packetThread;
	LoginProcessor _loginProcessor;
	TetrisProcessor _tetrisProcessor;
	LobbyProcessor _lobbyProcessor;

	std::list<UserPtr> _users;
	int _epollFileDescrtion;
	int _listeningPort;
};


