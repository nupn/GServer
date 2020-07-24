#pragma once
#include <vector>
#include <memory>
#include "PacketHandler.cpp"
#include "Packet.h"
#include "User.h"

class Local : public PacketHandler {
public:
	virtual bool OnPacket(Packet& packet) override;
	bool Enter(UserPtr user);
private:
	std::vector<UserWeakPtr> _users;
};

using LocalPtr=std::shared_ptr<Local>;
using LocalWeakPtr=std::weak_ptr<Local>;


