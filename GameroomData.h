/**
 * Created by Josef Ginerman on 28/12/17.
 **/

#ifndef TCPSERVER_GAMEROOMDATA_H
#define TCPSERVER_GAMEROOMDATA_H


#include <iostream>

using namespace std;

/**
 * The struct keeps the data of the game room
 */
struct GameroomData {
    int socket1;
    int socket2;
    string name;
};

#endif //TCPSERVER_GAMEROOMDATA_H
