#include "Socket.h"

Socket::Socket() {
	_socket = -1;
}

int Socket::GetSocketNum() {
	return _socket;
}

Socket::Socket(int nSocket) {
	_socket = nSocket;
}


