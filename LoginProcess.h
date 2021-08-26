#pragma once
#include <memory>
#include "Process.h"

class LoginProcess;
using LoginProcessPtr = std::shared_ptr<LoginProcess>;
class LoginProcess : public Process, std::enable_shared_from_this<LoginProcess> {
public:
	bool OnPacket(Packet& packet, UserPtr user) override;
	LoginProcessPtr GetSelfPtr();
};

class LoginProcessor : public Processor
{
public:
};

