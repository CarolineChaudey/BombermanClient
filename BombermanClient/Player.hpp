//
//  Player.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef Player_hpp
#define Player_hpp

#include <stdio.h>
#include "Bomb.hpp"

class Player{
public:
    Player();
    Player(int numero, int pv, int speed, int bombsCapacity, int bombsRefreshDelay);
    
    int getNumero();
    int getPv();
    int getSpeed();
    Bomb* getBombs();
    Bomb getBombAt(int i);
    int getBombsCapacity();
    int getBombsRefreshDelay();
    
    void setNumero(int numero);
    void setPv(int pv);
    void setSpeed(int speed);
    void setBombs(Bomb* bombs);
    void setBombAt(int i, Bomb bomb);
    void setBombsCapacity(int bombsCapacity);
    void setBombsRefreshDelay(int bombsRefreshDelay);
    
    Bomb useBomb();
    
private:
    int numero;
    int pv;
    int speed;
    Bomb* bombs;
    int bombsCapacity;
    int bombsRefreshDelay;
    
};
#endif /* Player_hpp */
