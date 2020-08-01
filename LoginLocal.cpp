#include "LoginLocal.h"
#include "protocol.h"
#include "Connection.h"
#include "Server.h"

bool LoginLocal::OnPacket(Packet& packet) {
	auto con = packet.GetConnection();
	if (!con) {
		printf("invalid packet");
		return false;
	}
	switch(packet.GetType()) {
		case C_LOGIN:
			{
				if (!server) {
					printf("not server on Login");
					return false;
				}

				UserPtr user = server->NewUser(con);

				game::s_login loginPacket;
				loginPacket.set_id(0);
				loginPacket.set_name("temp");
				
				server->LocalChange(LocalType::LOCAL_TYPE_LOBBY, user);
				con->SetSubHandler(std::dynamic_pointer_cast<PacketHandler>(user));
				con->SendPacket<game::s_login>(S_LOGIN, &loginPacket);
				printf("onLogin");
				return true;
			}
			break;
	}
	return false;
}
