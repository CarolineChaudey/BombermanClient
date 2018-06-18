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

class LevelManager{
  
public:
    
    LevelManager();
    LevelManager(Map map);
    
    void loadMap(std::string filename);
    void drawMap(sf::RenderWindow &window);

    void changeMapSize(int sizeX, int sizeY);
    
    
private:
    
    //Map to manage
    Map map;
    
    
};

#endif /* LevelManager_hpp */
