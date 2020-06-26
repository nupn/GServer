#pragma once
#include <memory>
#include "Local.h"

class LobbyLocal : public Local {
public:
	void OnPacket(int type, int size, char* buf) {
	}
private:
};

using LobbyLocalPtr=std::shared_ptr<LobbyLocal>;


