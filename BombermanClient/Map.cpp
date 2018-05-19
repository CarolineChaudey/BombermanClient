//
//  Map.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//


#include "Map.hpp"

Map::Map(){
    this->map = new int*[20];
    for(int i = 0; i < 20; i++){
        this->map[i] = new int [20];
    }
    
    this->size_x = 20;
    this->size_y = 20;
}
Map::Map(int size_x, int size_y){
    this->map = new int*[size_x];
    for(int i = 0; i < size_x; i++){
        this->map[i] = new int [size_y];
    }
    
    this->size_x = size_x;
    this->size_y = size_y;
}
int Map::getSize_X(){
    return this->size_x;
}

int Map::getSize_Y(){
    return this->size_y;
}
int** Map::getMap(){
    return this->map;
}
int Map::getElementOnMap(int x, int y){
    return this->map[x][y];
}
void Map::setSize_X(int size_x){
    this->size_x = size_x;
}
void Map::setSize_Y(int size_y){
    this->size_y = size_y;
}
void Map::setMap(int **map){
    this->map = map;
}
void Map::setElementOnMap(int x, int y, int value){
    this->map[x][y] = value;
}


