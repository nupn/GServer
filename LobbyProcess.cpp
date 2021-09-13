#include "LobbyProcess.h"
#include "protocol.h"

bool LobbyProcess::OnPacket(Packet& packet, UserPtr user)
{	
	switch(packet.GetType()) {
		case C_CHAT:
			{
				printf("on chat message \n");
				game::chat_message* receivePacket = (game::chat_message *)packet.GetData();

				BroadcastMessage(user->GetName(), receivePacket->msg());
				/*
				game::chat_message sendPacket;
				sendPacket.set_id(0);
				sendPacket.set_name(user->GameName().c_str());
				sendPacket.set_msg(receivePacket->msg().c_str());

				BroadcastPacket<game::chat_message>(S_CHAT, &sendPacket);
				*/
			}
			return true;
		case C_MATCH:
			{
				//auto con = packet.GetConnection();
				//auto user = con->GetUser();
				//this->Match(user);
			}
			return true;
	}

	return false;
}

bool LobbyProcess::LeaveUser(UserPtr user)
{
	MatchSeedPtr matchUser = std::dynamic_pointer_cast<MatchSeed>(user);
	if (!matchUser) {
		printf("AddMatchUser fail");
		return false;
	}
	
	char message[512];
	sprintf(message, "%s is Leave" , user->GetName().c_str());

	BroadcastMessage("sysmessage", message);

	_match.RemoveSeed(matchUser);
	return Process::LeaveUser(user);
}

bool LobbyProcess::JoinUser(UserPtr user) {
	
	char message[512];
	sprintf(message, "%s is Join" , user->GetName().c_str());
	
	BroadcastMessage("sysmessage", message);

	return Process::JoinUser(user);
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

void LobbyProcessor::Init(Server *server)
{
	Processor::Init(server);
	LobbyProcessPtr process = std::make_shared<LobbyProcess>();
	process->Init(server);
	_process.push_back(process);
}
