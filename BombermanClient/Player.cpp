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
    this->pv = 0;
    this->speed = 0;
    this->bombs = NULL;
    this->bombsCapacity = 0;
    this->bombsRefreshDelay = 0;
    tileset_texture = new Texture();
    tileset = new Sprite();
}


Player::Player(int numero, int pv, int speed, int bombsCapacity, int bombsRefreshDelay) {
    this->numero = numero;
    this->pv = pv;
    this->speed = speed;
    this->bombsCapacity = bombsCapacity;
    this->bombsRefreshDelay = bombsRefreshDelay;
    
    this->bombs = new Bomb[bombsCapacity];
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

int Player::getBombsRefreshDelay() { 
    return this->bombsRefreshDelay;
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

void Player::setBombsCapacity(int bombsCapacity) { 
    this->bombsCapacity = bombsCapacity;
}

void Player::setBombsRefreshDelay(int bombsRefreshDelay) { 
    this->bombsRefreshDelay = bombsRefreshDelay;
}

Bomb Player::useBomb() { 
    Bomb bombUsed = Bomb();
    for(int i = 0; i < bombsCapacity; i++){
        if(this->bombs != NULL){
            bombUsed = this->bombs[i];
            //Supprimer la bombe du tableau
        }
    }
    //Lancer le timer de récuperaition
    return bombUsed;
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









