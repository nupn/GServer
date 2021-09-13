#include "LoginProcess.h"
#include "protocol.h"
#include "User.h"
#include "Server.h"

bool LoginProcess::OnPacket(Packet& packet, UserPtr user) {

	printf("LoginProcess packet %d\n", packet.GetType());
	switch(packet.GetType()) {
		case C_LOGIN:
			{
				ProcessPtr process = GetSharedPtr();
				if (server()->ChangeProcess(process, PROCESS_LOBBY, user)) {
					++_id;
					char userName[50];
					sprintf(userName, "temp%d", _id);
					user->SetName(userName);

					game::s_login loginPacket;
					loginPacket.set_id(_id);
					loginPacket.set_name(userName);
					user->SendPacket<game::s_login>(S_LOGIN, &loginPacket);
					printf("onLogin\n");
				}

				return true;
			}
			break;
	}
	return false;
}

void LoginProcessor::Init(Server *server)
{
	Processor::Init(server);
	LoginProcessPtr process = std::make_shared<LoginProcess>();
	process->Init(server);
	_process.push_back(process);
}
