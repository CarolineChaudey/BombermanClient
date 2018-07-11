//
//  LevelManager.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 11/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef LevelManager_hpp
#define LevelManager_hpp

#include <stdio.h>

#include "Map.hpp"
#include "Player.hpp"


class LevelManager{
 
public:

    LevelManager();
    LevelManager(Map map);
    
    void loadMap(std::string filename);
    void drawMap(sf::RenderWindow &window);
    void addTile(int tile, int position_x, int position_y, sf::RenderWindow &windows);
    void changeMapSize(int sizeX, int sizeY);
    void addPlayer(Player player);
    void drawPlayers(sf::RenderWindow &window);
    Player* getPlayerAt(int i);
    vector<Player*> getAllPlayer();
    Map* getMap();
    
    
private:
    
    //Map to manage
    Map map;
    
    //Players on the battlefield
    Player* players[4];
    
};

#endif /* LevelManager_hpp */
