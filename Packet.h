#pragma once
#include <memory>
#include <string>

class Packet  {
public:
	int GetType() {
		return _type;
	}

	void SetType(int type){
		_type = type;
	}

	void SetData(void *data) {
		_data = data;
	}

	void * GetData() {
		return _data;
	}

/*
	std::shared_ptr<User> GetUser() {
		return _user;
	}
	
	void SetUser(std::shared_ptr<User> user) {
		_user = user;
	}
*/
private:
	//std::shared_ptr<User> _user;
	void *_data;
	int _type;
};


