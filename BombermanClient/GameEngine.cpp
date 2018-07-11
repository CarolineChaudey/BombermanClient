		//
//  Game.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 07/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "GameEngine.hpp"



GameEngine::GameEngine(LevelManager* levelManager, IController* controller) {
    this->levelManager = levelManager;
    this->controller = controller;
    this->state = WORKFLOW::ROOMSSCREEN;
    
    this->bonbList = *new vector <Bomb>;
}


GameEngine::GameEngine(LevelManager *levelManager, IController *controller, WORKFLOW state) {
    this->levelManager = levelManager;
    this->controller = controller;
    this->state = state;
}

GameEngine::~GameEngine() { 
    
}

void GameEngine::launchGameEngine(sf::RenderWindow &window) {
    
    IMenu* menu = new RoomMenu(window.getSize().x, window.getSize().y, resourcePath() + "sansation.ttf");
    
    while (window.isOpen())
    {
        switch (this->state) {
            case WORKFLOW::TITLESCREEN:
                break;
            case WORKFLOW::ROOMSSCREEN:
                launchRoomScreen(window, menu);
                break;
                
            case WORKFLOW::GAMESCREEN:
                launchGameScreen(window);
                break;
            default:
                break;
        }
        
    }
    
}

void GameEngine::launchTitleScreen(sf::RenderWindow &window, IMenu* menu) {
    
}

void GameEngine::launchRoomScreen(sf::RenderWindow &window, IMenu* menu) {
    // Process events
    sf::Event event;
    
    
    
    while (window.pollEvent(event))
    {
        KEYS key = controller->manageEvent(event);
        
        switch (key) {
            case KEYS::LEFT:
            case KEYS::UP:
                menu->UpSelection();
                break;
            case KEYS::RIGHT:
            case KEYS::DOWN:
                menu->DownSelection();
                break;
            case KEYS::EXIT:
                window.close();
                break;
            case KEYS::ENTER:
                this->state = WORKFLOW::GAMESCREEN;
                break;
            default:
                break;
        }
        
    }
    
    window.clear();
    menu->drawMenu(window);
    
    
    window.display();
}

void GameEngine::launchGameScreen(sf::RenderWindow &window) { 
    // Process events
    sf::Event event;
    Player* player = this->levelManager->getPlayerAt(0);
    
    while (window.pollEvent(event))
    {
        KEYS key = controller->manageEvent(event);
        
        
        switch (key) {
            case KEYS::LEFT:
                player->setDirection(DIRECTION::LEFT);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) == (int)TILES::EMPTY
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) == (int)TILES::GROUND
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) != (int)TILES::BUTTER){
                    player->setPosY(player->getPosY()-32);
                }
                break;
            case KEYS::RIGHT:
                player->setDirection(DIRECTION::RIGHT);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) == (int)TILES::EMPTY
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) == (int)TILES::GROUND
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) != (int)TILES::BUTTER){
                    player->setPosY(player->getPosY()+32);
                }
                break;
            case KEYS::UP:
                player->setDirection(DIRECTION::UP);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) == (int)TILES::EMPTY
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) == (int)TILES::GROUND
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) != (int)TILES::BUTTER){
                    player->setPosX(player->getPosX()-32);
                }
                break;
            case KEYS::DOWN:
                bombTick();
                player->setDirection(DIRECTION::DOWN);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) == (int)TILES::EMPTY
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) == (int)TILES::GROUND
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) != (int)TILES::BUTTER){
                    player->setPosX(player->getPosX()+32);
                }
                break;
            case KEYS::BOMB:
                if (player->useBomb((player->getPosX() + 32) / 32, (player->getPosY()) / 32)) {
                    (levelManager->getMap())->setElementOnMap(LAYERS::LAYER3, (player->getPosX() + 32) / 32, (player->getPosY()) / 32, (int)TILES::BUTTER);
                }
                break;
            case KEYS::EXIT:
                window.close();
                break;
            case KEYS::RETURN:
                this->state = WORKFLOW::ROOMSSCREEN;
                break;
        }
        
    }
    
    window.clear();
    
    this->levelManager->drawMap(window);
    this->levelManager->drawPlayers(window);

    //Fonction pour ajouter une image sur la map
    //lManager.addTile( (int)TILES::BUTTER, 6, 6, window);
    
    window.display();
}

void GameEngine::bombTick() {
    for (int i = 0; i < (this->levelManager)->getAllPlayer().size(); i++) {
        Player* currentPlayer = (this->levelManager)->getPlayerAt(i);
        Bomb* playerBombList = currentPlayer->bombs;
        for (int j = 0; j < currentPlayer->getBombsCapacity(); j++) {
            if (playerBombList[j].getActived() == 1) {
                playerBombList[j].setDelay(playerBombList[j].getDelay() - 1);
                if (playerBombList[j].getDelay() <= 0) {
                    (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER3,playerBombList[j].getX(), playerBombList[j].getY(), 0);
                    
                    currentPlayer->deleteBombAt(j);
                }
            }
        }
        
        //this->bonbList[i].setDelay(this->bonbList[i].getDelay() - 1);
        //if (this->bonbList[i].getDelay() <= 0) {
        //    (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER3,this->bonbList[i].getX(), this->bonbList[i].getY(), 0);
            
        //}
    }
}



