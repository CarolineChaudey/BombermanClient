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
}


GameEngine::GameEngine(LevelManager *levelManager, IController *controller, WORKFLOW state) {
    this->levelManager = levelManager;
    this->controller = controller;
    this->state = state;
}

GameEngine::~GameEngine() { 
    
}

void GameEngine::launchGameEngine(sf::RenderWindow &window) {
    
    IMenu* menu = new RoomMenu(window.getSize().x, window.getSize().y, 4, resourcePath() + "sansation.ttf");
    
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
                menu->UpSelection();
                break;
            case KEYS::RIGHT:
                menu->DownSelection();
                break;
            case KEYS::EXIT:
                window.close();
                break;
            case KEYS::ENTER:
                this->state = WORKFLOW::GAMESCREEN;
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
                player->setPosY(player->getPosY()-32);
                break;
            case KEYS::RIGHT:
                player->setDirection(DIRECTION::RIGHT);
                player->setPosY(player->getPosY()+32);
                break;
            case KEYS::UP:
                player->setDirection(DIRECTION::UP);
                player->setPosX(player->getPosX()-32);
                break;
            case KEYS::DOWN:
                player->setDirection(DIRECTION::DOWN);
                player->setPosX(player->getPosX()+32);
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



