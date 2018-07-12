//
//  Lobby.hpp
//  BombermanClient
//
//  Created by Caroline Chaudey on 10/07/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef Lobby_hpp
#define Lobby_hpp

#include <stdio.h>
#include <string>

class Lobby {
public:
    Lobby();
    Lobby(int id, int nbPlayers, int maxPlayers);
    int getId() const;
    int getNbPlayers() const;
    int getMaxPlayers() const;
    void setId(int id);
    void setNbPlayers(int nbPlayers);
    void setMaxPlayers(int maxPlayers);
    std::string toString();
private:
    int id;
    int nbPlayers;
    int maxPlayers;
};

#endif /* Lobby_hpp */
