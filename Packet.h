#pragma once
#include <string>
class Connection;
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
	
	Connection* GetConnection() {
		return _con;
	}
	
	void SetConnection(Connection *con) {
		_con = con;
	}

private:
	Connection *_con;
	void *_data;
	int _type;
};


