#pragma once
#include "User.h"
#include "Packet.h"
#include "Connection.h"
#include "PacketProcessor.h"
#include <vector>
#include "LobbyLocal.h"


class Server  {
public:
	Server();
	void Run(int listeningPort);
	void OnPacket(Packet packet);
	Connection* GetConnection(int socket);
	Connection* NewConnection(int socket);

	//game logic
	UserPtr NewUser(Connection *con);
	LocalPtr GetLobby();
private:
	Connection userLogin;
	PacketProcessor _packetThread;
	std::vector<Connection*> _cons;
	std::vector<LobbyLocalPtr> _lobbys;
	std::vector<UserPtr> _users;
};


