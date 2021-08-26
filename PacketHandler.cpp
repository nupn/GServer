#include "PacketHandler.h"



bool PacketHandler::OnPacket(Packet& packet)
{
	if (!_sub.expired()) {
		auto sub = _sub.lock();
		if (sub) {
			return sub->OnPacket(packet);
		}
	}
	return false;
}
	
void PacketHandler::SetSubHandler(PacketHandlerPtr sub) {
	_sub = sub;
}

PacketHandlerPtr PacketHandler::GetSubHandler() {
	return _sub.lock();
}

