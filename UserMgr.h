#pragma once
#include "Singleton.h"
#include "User.h"
#include <vector>

class UserMgr : public Singleton<UserMgr>  {
public:
	User();
	User* GetUser(int socket);
	User* NewUser(int socket);
private:
	std::vector<User> _users;
};


