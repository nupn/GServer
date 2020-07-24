#pragma once
#include "Packet.h"
#include <memory>

class PacketHandler {
public:
	virtual bool OnPacket(Packet& packet) = 0;
};

using PacketHandlerPtr=std::shared_ptr<PacketHandler>;
using PacketHandlerWeakPtr=std::weak_ptr<PacketHandler>;
