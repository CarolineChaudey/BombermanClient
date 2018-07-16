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

GameServerService::GameServerService() {
    struct sockaddr_in servaddr;
    
    this->co_socket = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&servaddr, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(serverPort);
    
    inet_pton(AF_INET, serverAddr, &(servaddr.sin_addr));
    
    connect(this->co_socket, (struct sockaddr *)&servaddr, sizeof(servaddr));
}

std::string GameServerService::getRooms() {
    char recvline[100];
    bzero(recvline, 100);

    write(this->co_socket, "get-rooms", 10);
    read(this->co_socket, recvline, 100);
    
    return recvline;
}

bool GameServerService::chooseRoom(int roomId) {
    char strId[10];
    sprintf(strId, "%d", roomId);
    write(this->co_socket, strId, 10);
    printf("Choosen lobby sent.\n");
    char serverAnswer[5];
    read(this->co_socket, serverAnswer, 5);
    printf("Server says %s\n", serverAnswer);
    
    if (strcmp(serverAnswer, "NOK") == 0) {
        return false;
    }
    return true;
}

void GameServerService::checkPlayerJoin() {

    //Fonction qui récupère du serveur qu'un joueur à rejoin
    //char playersInfo[50];
    //read(this->co_socket, playersInfo, 50);
    
    //cout << "Player joined " << playersInfo << endl;

    //id du joueur

    //Id recupéré du serveur
  /*  int id = 0;
    Player* playerX = new Player();
    playerX->setTilesetTexturePath(resourcePath() + "fermie01rSpriteSheet.gif");
    playerX->setPv(1);
    playerX->setPosX(32);
    playerX->setPosY(32);
    playerX->setSpeed(10);
    playerX->setNumero(id);
    playerX->setDirection(DIRECTION::DOWN);
    playerX->setBombsCapacity(2);
    playerX->setNumero();
    return playerX;*/

    
}

sf::String GameServerService::checkServerCommand() {
    
   // String serverCommand = "NOP";
    
    //if(ser)
    
}


