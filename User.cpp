#include "User.h"

bool User::OnPacket(Packet& packet) {

	PacketHandlerPtr ptr = _localPtr.lock();
	if (ptr) {
		return ptr->OnPacket(packet);
	}

	return false;
}

void User::SetLocal(PacketHandlerWeakPtr local) {
	if (local.expired()) {
		_localPtr.reset();
	}

	_localPtr = local;
}
