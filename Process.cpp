#include "Process.h"
#include "protocol.h"
#include "Macro.h"

Process::Process(){
	
}

Process::~Process(){
	
}

void Process::Init(Server *server){
	printf("set server %p\n", server);
	_server = server;
}

bool Process::OnPacket(Packet& packet, UserPtr user)
{
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

bool Process::JoinUser(UserPtr joinUser) {
	if (!joinUser) {
		return false;
	}

	for (UserPtr user : _users) {
		if (user == joinUser) {
			return false;
		}
	}	

	_users.push_back(joinUser);
	return true;
}

bool Process::LeaveUser(UserPtr user) {
	if (!user) {
		return false;
	}

	auto iter = remove(begin(_users), end(_users), user);
	_users.erase(iter);
	return true;
}

bool Process::CanJoin()
{
	if (_users.size() > 100) {
		return false;
	}

	return true;
}

Server *Process::server()
{
	return _server;
}

void Processor::Init(Server *server)
{
	_server = server;
}

bool Processor::JoinUser(UserPtr user) {
	for (auto process : _process) {
		if (process->CanJoin()) {
			process->JoinUser(user);
			return true;
		}
	}

	return false;
}

bool Processor::LeaveUser(UserPtr user) {
	/*
	ProcessPtr *process = user->GetProcess();
	if (!process) {
		return false;
	}

	process->LeaveUser(user);
	*/
}
