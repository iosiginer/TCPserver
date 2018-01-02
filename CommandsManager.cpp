/**
 * Created by Josef Ginerman on 25/12/17.
 **/

#include "CommandsManager.h"
#include "PlayCommand.h"
#include "PrintCommand.h"
#include "JoinCommand.h"
#include "CloseCommand.h"
#include "StartCommand.h"


CommandsManager::CommandsManager() {
    openGames = new map<string,int>();
    lobbyMap = new map<string, GameroomData *>();
    commandsMap["play"] = new PlayCommand();
    commandsMap["list_games"] = new PrintCommand(openGames);
    commandsMap["join"] = new JoinCommand(openGames, lobbyMap);
    commandsMap["close"] = new CloseCommand(openGames, lobbyMap);
    commandsMap["start"] = new StartCommand(openGames);
}
void CommandsManager::executeCommand(string command, vector<string> args, int clientSocket1, int clientSocket2) {
    Command *commandObj = commandsMap[command];
    // lock it so only one gets access to the commands at a time
    commandObj->execute(args, clientSocket1, clientSocket2);
}
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    map<string, GameroomData *>::iterator it2;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
    delete(openGames);
    for (it2 = lobbyMap->begin(); it2 != lobbyMap->end(); it2++) {
        delete it->second;
    }
    delete lobbyMap;
}



