#pragma once
#include <memory>
#include "Local.h"

class LoginLocal : public Local {
public:
	bool OnPacket(Packet& packet) override;
};


using LoginLocalPtr = std::shared_ptr<LoginLocal>;
