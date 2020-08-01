#pragma once
#include <memory>
#include <string>
#include "PacketHandler.h"

class User : public PacketHandler  {
public:
	User(){};
	int Socket() {
		return _socket;
	};

	bool OnPacket(Packet& packet);
	void SetLocal(PacketHandlerWeakPtr local);

private:
	PacketHandlerWeakPtr _localPtr;
	int _socket;
	int _id;
	std::string _name;
};

using UserPtr=std::shared_ptr<User>;
using UserWeakPtr=std::weak_ptr<User>;
