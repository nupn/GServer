#pragma once
#include "PacketHandler.h"
#include "User.h"
#include "Packet.h"
#include "Connection.h"
#include "PacketProcessor.h"
#include "Local.h"
#include <vector>

enum class LocalType{
	LOCAL_TYPE_LOGIN,
	LOCAL_TYPE_LOBBY
};

class Server {
public:
	Server();
	void Run(int listeningPort);

	Connection* GetConnection(int socket);
	Connection* NewConnection(int socket);

	//game logic
	UserPtr NewUser(Connection *con);

	void LocalChange(LocalType localType, UserPtr user);
private:
	Connection userLogin;
	PacketProcessor _packetThread;
	LocalPtr _login;

	std::vector<Connection*> _cons;
	std::vector<LocalPtr> _lobbys;
	std::vector<UserPtr> _users;
};


