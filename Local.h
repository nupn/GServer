#pragma once
#include <vector>
#include <memory>
#include "PacketHandler.h"
#include "Packet.h"
#include "User.h"

class Server;
class Local : public PacketHandler {
public:
	virtual bool OnPacket(Packet& packet) override;
	virtual bool Enter(UserPtr user);
	virtual bool IsFull();

	void SetServer(Server *pServer);
protected:
	std::vector<UserWeakPtr> _users;
	int _maxSize = 100;
	Server *server;
};

using LocalPtr=std::shared_ptr<Local>;
using LocalWeakPtr=std::weak_ptr<Local>;


