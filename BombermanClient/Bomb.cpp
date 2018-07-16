//
//  Bomb.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "Bomb.hpp"


Bomb::Bomb() {
    this->actived = 0;
    this->distance = 0;
    this->delay = 100;
    this->x = 0;
    this->y = 0;
}

Bomb::Bomb(int distance, int degats, int delay) {
    this->actived = 0;
    this->distance = distance;
    this->delay = 100;
    this->x = -1;
    this->y = -1;
}

int Bomb::getDistance() { 
    return this->distance;
}

int Bomb::getDelay(){
    return this->delay;
}
int Bomb::getActived(){
    return this->actived;
}
int Bomb::getX(){
    return this->x;
}
int Bomb::getY(){
    return this->y;
}

void Bomb::setDistance(int d) { 
    this->distance = d;
}


void Bomb::setDelay(int d){
    this->delay = d;
}
void Bomb::activateBomb(int x, int y){
    this->actived = 1;
    this->x = x;
    this->y = y;
}
