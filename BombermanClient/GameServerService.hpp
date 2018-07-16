//
//  GameServerService.hpp
//  BombermanClient
//
//  Created by Caroline Chaudey on 10/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef GameServerService_hpp
#define GameServerService_hpp

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <string>
#include <arpa/inet.h>
#include <unistd.h>
#include "Player.hpp"


class GameServerService {
public:
    GameServerService();
    std::string getRooms();
    bool chooseRoom(int roomId);
    void checkPlayerJoin();
    String checkServerCommand();
    
    
private:
    char serverAddr[15] = "127.0.0.1";
    int serverPort = 8081;
    int co_socket;
};

#endif /* GameServerService_hpp */
