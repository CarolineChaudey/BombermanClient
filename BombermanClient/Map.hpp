//
//  Map.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef Map_h
#define Map_h

#include <stdio.h>

class Map{

public:
    Map();
    Map(int size_x, int size_y);
    
    int getSize_X();
    int getSize_Y();
    int** getMap();
    int getElementOnMap(int x, int y);
    
    void setSize_X(int size_x);
    void setSize_Y(int size_y);
    void setMap(int** map);
    void setElementOnMap(int x, int y, int value);
    
private:
    int size_x;
    int size_y;
    int** map;
    
    
    
};

#endif /* Map_h */
