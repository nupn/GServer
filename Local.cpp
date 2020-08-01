#include "Local.h"
#include "protocol.h"
#include "Connection.h"
#include "Macro.h"

bool Local::OnPacket(Packet& packet) {
	/*
	auto con = packet.GetConnection();
	switch(packet.GetType()) {
		case C_CHAT:
			{
				game::chat_message* receivePacket = (game::chat_message *)packet.GetData();

				game::chat_message sendPacket;
				sendPacket.set_id(0);
				sendPacket.set_name(receivePacket->name().c_str());
				sendPacket.set_msg(receivePacket->msg().c_str());
				con->SendPacket<game::chat_message>(S_CHAT, &sendPacket);
				return true;
			}
	}
	*/

	return false;
}

bool Local::IsFull() {
	if (_users.size() >= _maxSize) {
		return true;
	}

	return false;
}

bool Local::Enter(UserPtr user) {
	VEC_FOR(_users) {
		if (iter->lock() == user) {
			return false;
		}
	}	


	_users.push_back(user);
	return true;
}

void Local::SetServer(Server *pServer){
	printf("set server %p\n", pServer);
	server = pServer;
}
