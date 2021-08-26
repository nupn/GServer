#include "TetrisProcess.h"
#include "protocol.h"

bool TetrisProcesss::OnPacket(Packet& packet, UserPtr user)
{
	switch(packet.GetType()) {
		case C_CHAT:
			{
				printf("on chat message \n");
				game::chat_message* receivePacket = (game::chat_message *)packet.GetData();

				game::chat_message sendPacket;
				sendPacket.set_id(0);
				sendPacket.set_name(receivePacket->name().c_str());
				sendPacket.set_msg(receivePacket->msg().c_str());

				user->SendPacket<game::chat_message>(S_CHAT, &sendPacket);
			}
	}

	return false;
}
