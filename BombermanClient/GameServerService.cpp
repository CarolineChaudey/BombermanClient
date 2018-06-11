//
//  GameServerService.cpp
//  BombermanClient
//
//  Created by Caroline Chaudey on 10/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "GameServerService.hpp"

void GameServerService::getRooms(char* recvline) {
    int sockfd;
    char sendline[100];
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof servaddr);
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(serverPort);

    inet_pton(AF_INET, serverAddr, &(servaddr.sin_addr));

    connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

    bzero(sendline, 100);
    bzero(recvline, 100);

    write(sockfd, "get-rooms", 10);
    read(sockfd, recvline, 100);
}
