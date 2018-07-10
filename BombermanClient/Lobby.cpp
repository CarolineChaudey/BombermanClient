//
//  Lobby.cpp
//  BombermanClient
//
//  Created by Caroline Chaudey on 10/07/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "Lobby.hpp"

Lobby::Lobby() {
    
}
Lobby::Lobby(int id, int nbPlayers, int maxPlayers) {
    this->id = id;
    this->nbPlayers = nbPlayers;
    this->maxPlayers = maxPlayers;
}
int Lobby::getId() const {
    return this->id;
}
int Lobby::getNbPlayers() const {
    return this->nbPlayers;
}
int Lobby::getMaxPlayers() const {
    return this->maxPlayers;
}
void Lobby::setId(int id) {
    this->id = id;
}
void Lobby::setNbPlayers(int nbPlayers) {
    this->nbPlayers = nbPlayers;
}
void Lobby::setMaxPlayers(int maxPlayers) {
    this->maxPlayers = maxPlayers;
}
std::string Lobby::toString() {
    return "id: " + std::to_string(this->id) + ", nb players: " + std::to_string(this->nbPlayers) + ", max players: " + std::to_string(this->maxPlayers);
    }
