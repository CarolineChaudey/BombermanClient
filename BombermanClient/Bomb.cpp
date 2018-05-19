//
//  Bomb.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "Bomb.hpp"


Bomb::Bomb() { 
    this->degats = 0;
    this->distance = 0;
    this->delay = 0;
}

Bomb::Bomb(int distance, int degats, int delay) {
    this->distance = distance;
    this->degats = degats;
    this->delay = delay;
}

int Bomb::getDistance() { 
    return this->distance;
}

int Bomb::getDegats() { 
    return this->degats;
}

int Bomb::getDelay(){
    return this->delay;
}
void Bomb::setDistance(int d) { 
    this->distance = d;
}

void Bomb::setDegats(int d) { 
    this->degats = d;
}
void Bomb::setDelay(int d){
    this->delay = d;
}
