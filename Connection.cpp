#include "Connection.h"

using namespace std;


void Connection::SetSocket(int socket){
		_socket = socket;
}

int Connection::GetSocket(){
		return _socket;
}

void Connection::SetUser(UserPtr user){
		_player = user;	
}

UserPtr Connection::GetUser(){
		return _player.lock();
}

void Connection::Close() {
}

