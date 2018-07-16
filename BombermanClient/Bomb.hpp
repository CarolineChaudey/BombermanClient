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
#include <SFML/Graphics.hpp>

using namespace sf;
class Bomb{
public:
    Bomb();
    Bomb(int distance, int degats, int delay);
    
    int getDistance();
    int getDelay();
    int getActived();
    int getX();
    int getY();
    
    void setDistance(int d);
    void setDelay(int d);
    
    void activateBomb(int x, int y);
private:
    int actived;
    int distance;
    int delay;
    int x;
    int y;
    sf::Texture bombTexture;
    sf::Sprite bombSprite;
};
#endif /* Bomb_hpp */
