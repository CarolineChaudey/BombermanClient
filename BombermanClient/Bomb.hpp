//
//  Bomb.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef Bomb_hpp
#define Bomb_hpp

#include <stdio.h>

class Bomb{
public:
    Bomb();
    Bomb(int distance, int degats, int delay);
    
    int getDistance();
    int getDegats();
    int getDelay();
    
    void setDistance(int d);
    void setDegats(int d);
    void setDelay(int d);
    
private:
    int distance;
    int degats;
    int delay;
};
#endif /* Bomb_hpp */
