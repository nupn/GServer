#pragma once
#include "User.h"
#include "Packet.h"
#include "Connection.h"
#include "PacketProcessor.h"
#include <vector>
#include "Local.h"

struct epoll_custom {
	int socket;
	void *ptr;
};



class Server  {
public:
	Server();
	void Run(int listeningPort);
	void OnPacket(Packet packet);
	Connection* GetConnection(int socket);
	Connection* NewConnection(int socket);
private:
	std::vector<Connection*> _cons;
	PacketProcessor _packetThread;
	
	std::vector<LobbyLocalPtr> _lobbys;
};


