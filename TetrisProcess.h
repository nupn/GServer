#pragma once
#include <memory>
#include "Process.h"

class TetrisProcesss : public Process {
public:
	bool OnPacket(Packet& packet, UserPtr user) override;
private:

};

class TetrisProcessor : public Processor
{
public:
};

using TetrisProcesssPtr=std::shared_ptr<TetrisProcesss>;


