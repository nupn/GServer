#pragma once
#include "Packet.h"
#include <memory>

class PacketHandler;
using PacketHandlerPtr=std::shared_ptr<PacketHandler>;
using PacketHandlerWeakPtr=std::weak_ptr<PacketHandler>;

class PacketHandler {
public:
	virtual bool OnPacket(Packet& packet);
	
	void SetSubHandler(PacketHandlerPtr user);
	PacketHandlerPtr GetSubHandler();

	//PacketHandlerPtr GetSelfSharedPtr();

private:
	PacketHandlerWeakPtr _sub;

};

