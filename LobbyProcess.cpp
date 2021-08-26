#include "LobbyProcess.h"
#include "protocol.h"

bool LobbyProcess::OnPacket(Packet& packet, UserPtr user)
{	
	/*
	switch(packet.GetType()) {
		case C_CHAT:
			{
				printf("on chat message \n");
				game::chat_message* receivePacket = (game::chat_message *)packet.GetData();

				game::chat_message sendPacket;
				sendPacket.set_id(0);
				sendPacket.set_name(receivePacket->name().c_str());
				sendPacket.set_msg(receivePacket->msg().c_str());
				auto con = packet.GetConnection();

				auto user = con->GetUser();
				user->SendPacket<game::chat_message>(S_CHAT, &sendPacket);
			}
			return true;
		case C_MATCH:
			{
				auto con = packet.GetConnection();
				auto user = con->GetUser();
				this->Match(user);
			}
			return true;
	}
*/
	return false;
}

bool LobbyProcess::LeaveUser(UserPtr user)
{
	MatchSeedPtr matchUser = std::dynamic_pointer_cast<MatchSeed>(user);
	if (!matchUser) {
		printf("AddMatchUser fail");
		return false;
	}

	_match.RemoveSeed(matchUser);
	return Process::LeaveUser(user);
}

void LobbyProcess::MatchGame(UserPtr user)
{
	MatchSeedPtr matchUser = std::dynamic_pointer_cast<MatchSeed>(user);
	if (!matchUser) {
		printf("AddMatchUser fail");
		return;
	}
	_match.AddSeed(matchUser);
}
