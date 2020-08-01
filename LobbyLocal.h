#pragma once
#include <memory>
#include "Local.h"

class LobbyLocal : public Local {
public:
	bool OnPacket(Packet& packet) override;
private:

};

using LobbyLocalPtr=std::shared_ptr<LobbyLocal>;


