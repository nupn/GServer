#include "Connection.h"

using namespace std;


void Connection::SetSocket(int socket){
		_socket = socket;
}

int Connection::GetSocket(){
		return _socket;
}

void Connection::SetUser(User user){
		_player = user;	
}

User* Connection::GetUser(){
		return &_player;
}

void Connection::Close() {
}

