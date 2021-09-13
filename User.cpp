#include "User.h"
#include "Process.h"

User::User(int socket) {
	_socket = socket;
	_toBeClose = false;
}

/*
bool User::OnPacket(Packet& packet) {

	PacketHandlerPtr ptr = _localPtr.lock();
	if (ptr) {
		return ptr->OnPacket(packet);
	}

	return false;
}
*/
bool User::OnPacket(Packet& packet) {
	if (!_process.expired()) {
		auto process = _process.lock();
		process->OnPacket(packet, GetSharedPtr());
		printf("user::onPacket success\n");
		return true;
	}

	return false;
}

void User::SetProcess(std::weak_ptr<Process> process) {
	if (_process.expired()) {
		_process.reset();
	}

	_process = process;
}

void User::ResetProcess()
{
	_process.reset();
}

std::weak_ptr<Process> User::GetProcess() {
	return _process;
}

int User::MatchValue() {
	return _matchValue;
}

bool User::Equal(const MatchSeedWeakPtr matchUser) {
	auto weakUser = matchUser.lock();
	if (!weakUser) {
		return false;
	}

	auto user = std::dynamic_pointer_cast<User>(weakUser);
	if (!user) {
		return false;
	}

	if (user->MatchValue() != this->MatchValue()) {
		return false;
	}

	return true;
}

bool User::Greater(const MatchSeedWeakPtr matchSeed) {
	MatchSeedPtr matchUser = matchSeed.lock();
	if (!matchUser) {
		return false;
	}

	UserPtr user = std::dynamic_pointer_cast<User>(matchUser);
	if (!user) {
		return false;
	}

	if (user->MatchValue() <= this->MatchValue()) {
		return false;
	}

	return false;
}

UserPtr User::GetSharedPtr() {
	return shared_from_this();
}


void User::CloseConnection(){
	_toBeClose = true;
}

bool User::CloseReserved(){
	return _toBeClose;
}

void User::SetName(const char *name) {
	_name = std::string(name);
}

std::string User::GetName() {
	return _name;
}

