#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#define ERROR -1
#define VALID 1
#define DISCONNECT 0
#define MAX_CONNECTED_CLIENTS 2
#define MAX_LENGTH 30

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstring>
#include <pthread.h>

using namespace std;

#include "CommandsManager.h"

class Server {
public:
    Server(int port);
    void start();
    void stop();


    int getPort() { return this->port; }

    int getServerSocket() { return this->serverSocket; }

    vector<pthread_t*> getThreadList() {return this->threadsList;}

    CommandsManager* getCommandsManager() { return this->commandsManager;}
private:
    int port;
    int serverSocket; // the socket's file descriptor
    CommandsManager *commandsManager;
    vector<pthread_t*>threadsList;

    /**
     * The method initializing the server
     */
    void initializeServer();

    /**
     * Function that deals with closing all the remaining threads before closing the server.
     */
    void closeAllThreads();

};


#endif //SERVER_SERVER_H
