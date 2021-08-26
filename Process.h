#pragma once
#include <vector>
#include <memory>
#include "PacketHandler.h"
#include "Packet.h"
#include "User.h"


class Server;
class Process;
using ProcessPtr=std::shared_ptr<Process>;
using ProcessWeakPtr=std::weak_ptr<Process>;

class Process : public PacketHandler {
public:
	Process();
	~Process();
	void Init(Server *server);
	virtual bool OnPacket(Packet& packet, UserPtr user);
	virtual bool JoinUser(UserPtr user);
	virtual bool LeaveUser(UserPtr user);
	virtual bool CanJoin();
	Server *server();

protected:
	Server *_server;
	std::vector<UserPtr> _users;
};

class Processor
{
public:
	void Init(Server *server);
	virtual bool JoinUser(UserPtr user);
	virtual bool LeaveUser(UserPtr user);

protected:
	Server *_server;
	std::vector<ProcessPtr> _process;
};

