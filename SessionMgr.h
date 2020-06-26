#pragma once
#include "Singleton.h"
#include <vector>

class Server : public Singleton<Server>  {
public:
	void run(int listeningPort);
	int getEpollFd();
	//static int nEpollFd;
	std::vector<int> nlist;
private:
	int nEpollFd;
};


