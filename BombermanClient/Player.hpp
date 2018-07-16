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
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace sf;

enum class DIRECTION {DOWN = 0, LEFT = 84, RIGHT = 168, UP = 252};

class Player{
    
public:
    Player();
    Player(int numero, int pv, int speed, int bombsCapacity);
    
    
    int timerAnimation = 2;
    
    Bomb* bombs;
    int getNumero();
    int getPv();
    int getSpeed();
    Bomb* getBombs();
    Bomb getBombAt(int i);
    int getBombsCapacity();
    string getTilesetTexturePath()const;
    string getTilesetPath()const;
    sf::Texture& getTilesetTexture();
    sf::Sprite&  getTileset();
    
    int getPosX();
    int getPosY();
    DIRECTION getDirection();
    
    
    
    
    void setNumero(int numero);
    void setPv(int pv);
    void setSpeed(int speed);
    void setBombs(Bomb* bombs);
    void setBombAt(int i, Bomb bomb);
    void deleteBombAt(int i);
    void setBombsCapacity(int bombsCapacity);
    bool useBomb(int x, int y);
    void setTilesetTexturePath(string path);
    void setTilesetPath(string path);
    void setTilesetTexture(sf::Texture *texture);
    void setTileset(sf::Sprite *sprite);
    void setPosX(int x);
    void setPosY(int y);
    void setDirection(DIRECTION direction);
    
   
    
private:
    
    string tileset_texture_path;
    string tileset_path;
    
    sf::Texture* tileset_texture;
    sf::Sprite* tileset;
    int numero;
    int pv;
    int speed;
    int bombsCapacity;
    int bombsRefreshDelay;
    DIRECTION direction;
    float posX;
    float posY;
    
    
    
};
#endif /* Player_hpp */
