#pragma once
#include <memory>

class Local {
public:
	void OnPacket(int type, int size, char* buf);
private:
	std::vector<Connection*> _cons;
};

using LocalPtr=std::shared_ptr<Local>;


