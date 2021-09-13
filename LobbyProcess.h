#pragma once
#include <memory>
#include "Process.h"
#include "Match.h"

class LobbyProcess : public Process {
public:
	bool OnPacket(Packet& packet, UserPtr user);
	void MatchGame(UserPtr user);
	virtual bool LeaveUser(UserPtr user);
	virtual bool JoinUser(UserPtr user);
private:
	Match _match;
};

using LobbyProcessPtr=std::shared_ptr<LobbyProcess>;

class LobbyProcessor : public Processor
{
public:
	void Init(Server *server);
private:
};

