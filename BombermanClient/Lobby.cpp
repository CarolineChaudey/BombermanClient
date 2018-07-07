//
//  Lobby.cpp
//  BombermanClient
//
//  Created by Caroline Chaudey on 06/07/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include <stdio.h>
#include <string>

class Lobby {
public:
    Lobby() {
        
    }
    Lobby(int id, int nbPlayers, int maxPlayers) {
        this->id = id;
        this->nbPlayers = nbPlayers;
        this->maxPlayers = maxPlayers;
    }
    int getId() const {
        return this->id;
    }
    int getNbPlayers() const {
        return this->nbPlayers;
    }
    int getMaxPlayers() const {
        return this->maxPlayers;
    }
    void setId(int id) {
        this->id = id;
    }
    void setNbPlayers(int nbPlayers) {
        this->nbPlayers = nbPlayers;
    }
    void setMaxPlayers(int maxPlayers) {
        this->maxPlayers = maxPlayers;
    }
    std::string toString() {
        return "id: " + std::to_string(id) + ", nb players: " + std::to_string(nbPlayers) + ", max players: " + std::to_string(maxPlayers);
    }
private:
    int id;
    int nbPlayers;
    int maxPlayers;
};
