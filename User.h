#pragma once
#include <string>

class User  {
public:
	User(){};
	int Socket() {
		return _socket;
	};

	void OnPacket(int type, int size, char* buf);

private:
	int _id;
	std::string _name;
	int _socket;
};


