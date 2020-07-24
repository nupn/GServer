#include "LobbyLocal.h"

void LobbyLocal::OnPacket(int type, int size, char* buf) {
	/*
	switch(packet.GetType()) {
		case C_CHAT:
			{
				game::chat_message* receivePacket = (game::chat_message *)packet.GetData();

				game::chat_message sendPacket;
				sendPacket.set_id(0);
				sendPacket.set_name(receivePacket->name().c_str());
				sendPacket.set_msg(receivePacket->msg().c_str());
				auto con = packet.GetConnection();
				con->SendPacket<game::chat_message>(S_CHAT, &sendPacket);
			}
	}
*/
}
