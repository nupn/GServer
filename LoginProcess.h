#pragma once
#include <memory>
#include "Process.h"

class LoginProcess;
using LoginProcessPtr = std::shared_ptr<LoginProcess>;
class LoginProcess : public Process {
public:
	bool OnPacket(Packet& packet, UserPtr user) override;
private:
	int _id;
};

class LoginProcessor : public Processor
{
public:
	void Init(Server *server);
private:
};

