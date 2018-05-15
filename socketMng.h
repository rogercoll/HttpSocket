/*
 * http_server.h
 *
 *  Created on: 2017-5-15
 *      Author: root
 */

#ifndef SOCKETMNG_H_
#define SOCKETMNG_H_

	int createServerSocket(int port);
	int acceptNewConnections(int socket_fd);
	int clientConnection (char *host_name, int port);
	int deleteSocket(int socket_fd);

#endif 

