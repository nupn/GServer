#include "LoginProcess.h"
#include "protocol.h"
#include "User.h"
#include "Server.h"

bool LoginProcess::OnPacket(Packet& packet, UserPtr user) {
	switch(packet.GetType()) {
		case C_LOGIN:
			{
				//UserPtr user = server->NewUser(con);
				ProcessPtr process = std::dynamic_pointer_cast<Process>(GetSelfPtr());
				if (server()->ChangeProcess(process, PROCESS_LOGIN, {user})) {

					game::s_login loginPacket;
					loginPacket.set_id(0);
					loginPacket.set_name("temp");
					user->SendPacket<game::s_login>(S_LOGIN, &loginPacket);
					printf("onLogin");
				}

				//con->SetSubHandler(std::dynamic_pointer_cast<PacketHandler>(user));
				return true;
			}
			break;
	}
	return false;
}

LoginProcessPtr LoginProcess::GetSelfPtr() {
	return shared_from_this();
}


