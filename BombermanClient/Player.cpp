//
//  Player.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "Player.hpp"


Player::Player() { 
    this->numero = 0;
    this->pv = 1;
    this->speed = 1;
    this->bombs = NULL;
    this->bombsCapacity = 2;
    tileset_texture = new Texture();
    tileset = new Sprite();
    
    this->bombs = new Bomb[bombsCapacity];
    for(int i = 0; i < bombsCapacity; i++){
        this->bombs[i] = *new Bomb(1,1,3);
    }
}


Player::Player(int numero, int pv, int speed, int bombsCapacity) {
    this->numero = numero;
    this->pv = pv;
    this->speed = speed;
    this->bombsCapacity = bombsCapacity;
    
    this->bombs = new Bomb[bombsCapacity];
    for(int i = 0; i < bombsCapacity; i++){
        this->bombs[i] = *new Bomb(1,1,3);
    }
    
    tileset_texture = new Texture();
    tileset = new Sprite();
}

int Player::getNumero() { 
    return this->numero;
}

int Player::getPv() { 
    return this->pv;
}

int Player::getSpeed() { 
    return this->speed;
}

Bomb *Player::getBombs() { 
    return this->bombs;
}

Bomb Player::getBombAt(int i) { 
    return this->bombs[i];
}

int Player::getBombsCapacity() { 
    return this->bombsCapacity;
}

void Player::setNumero(int numero) { 
    this->numero = numero;
}

void Player::setPv(int pv) { 
    this->pv = pv;
}

void Player::setSpeed(int speed) { 
    this->speed = speed;
}

void Player::setBombs(Bomb *bombs) { 
    this->bombs = bombs;
}

void Player::setBombAt(int i, Bomb bomb) {
    this->bombs[i] = bomb;
}
void Player::deleteBombAt(int i) {
    this->setBombAt(i, *new Bomb(1,1,3));
}

void Player::setBombsCapacity(int bombsCapacity) { 
    this->bombsCapacity = bombsCapacity;
}

bool Player::useBomb(int x, int y) {
    for(int i = 0; i < bombsCapacity; i++){
        if(this->bombs[i].getActived() == 0){
            this->bombs[i].activateBomb(x, y);
            return true;
        }
    }
    return false;
}

sf::Texture& Player::getTilesetTexture() {
    return *this->tileset_texture;
}

sf::Sprite& Player::getTileset() {
    return *this->tileset;
}

void Player::setTilesetTexture(sf::Texture *texture) {
    this->tileset_texture = texture;
}

void Player::setTileset(sf::Sprite *sprite) {
    this->tileset = sprite;
}

void Player::setTilesetTexturePath(std::string path) {
    this->tileset_texture_path = path;
}

void Player::setTilesetPath(std::string path) {
    this->tileset_path = path;
}

std::string Player::getTilesetTexturePath() const {
    return this->tileset_texture_path;
}

std::string Player::getTilesetPath() const {
    return this->tileset_path;
}

int Player::getPosX() { 
    return this->posX;
}

int Player::getPosY() { 
    return this->posY;
}

void Player::setPosX(int x) {
    
    this->posX = x;
}

void Player::setPosY(int y) { 
    this->posY = y;
}

DIRECTION Player::getDirection() { 
    return this->direction;
}

void Player::setDirection(DIRECTION direction) { 
    this->direction = direction;
}











