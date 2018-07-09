//
//  GameServerService.cpp
//  BombermanClient
//
//  Created by Caroline Chaudey on 10/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "GameServerService.hpp"
#include <string>
#include <iostream>

std::string GameServerService::getRooms() {
    char recvline[100];
    char sendline[100];
    struct sockaddr_in servaddr;

    this->co_socket = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(serverPort);

    inet_pton(AF_INET, serverAddr, &(servaddr.sin_addr));

    connect(this->co_socket, (struct sockaddr *)&servaddr, sizeof(servaddr));

    bzero(sendline, 100);
    bzero(recvline, 100);

    write(this->co_socket, "get-rooms", 10);
    read(this->co_socket, recvline, 100);
    
    return recvline;
}

bool GameServerService::chooseRoom(int roomId) {
    write(this->co_socket, (void*) roomId, 1);
    printf("Choosen lobby sent.\n");
    char serverAnswer[5];
    read(this->co_socket, serverAnswer, 5);
    printf("Server says %s\n", serverAnswer);
    
    if (strcmp(serverAnswer, "NOK") == 0) {
        return false;
    }
    return true;
}
