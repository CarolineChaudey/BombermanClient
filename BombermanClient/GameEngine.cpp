		//
//  Game.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 07/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "GameEngine.hpp"
#include <thread>

struct LobbyList {
    int size;
    Lobby *lobbies;
} LobbyList;


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

Lobby* convertToLobbies(std::vector<std::string> raw) {
    Lobby* lobbies = new Lobby[raw.size()];
    for (int i = 0; i < raw.size(); i++) {
        std::string room = raw[i];
        lobbies[i].setId(room[0] - '0');
        lobbies[i].setNbPlayers(room[2] - '0');
        lobbies[i].setMaxPlayers(room[4] - '0');
    }
    return lobbies;
}

struct LobbyList GameEngine::getLobbies() {
    struct LobbyList ll;
    // get rooms from server
    std::string rawResults = this->gameServer->getRooms();
    std::vector<std::string> strRooms = split(rawResults, ';');
    ll.lobbies = convertToLobbies(strRooms);
    ll.size = strRooms.size() - 1;
    return ll;
}

void GameEngine::launchGameEngine(sf::RenderWindow &window) {
  //  struct LobbyList lobbyList = this->getLobbies();
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
            {
 
                
                this->state = WORKFLOW::GAMESCREEN;
                break;
            }
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
    Player* player2 = this->levelManager->getPlayerAt(2);
    
 
    while (window.pollEvent(event))
    {
      //  KEYS key = controller->manageEvent(event);
            
        if(player->getPv() > 0){
            switch (event.key.code) {
                case Keyboard::Left:
                    player->setDirection(DIRECTION::LEFT);
                    checkCollide(player->getDirection(), player);
                    break;
                case Keyboard::Right:
                    player->setDirection(DIRECTION::RIGHT);
                    checkCollide(player->getDirection(), player);
                    break;
                case Keyboard::Up:
                    player->setDirection(DIRECTION::UP);
                    checkCollide(player->getDirection(), player);
                    break;
                case Keyboard::Down:
                    player->setDirection(DIRECTION::DOWN);
                    checkCollide(player->getDirection(), player);
                    break;
                case Keyboard::Slash:
                    if (player->useBomb((player->getPosX() + 32) / 32, (player->getPosY()) / 32)) {
                        (levelManager->getMap())->setElementOnMap(LAYERS::LAYER3, (player->getPosX() + 32) / 32, (player->getPosY()) / 32, (int)TILES::BUTTER);
                    }
                    break;
                    
                case Keyboard::Q:
                    player2->setDirection(DIRECTION::LEFT);
                    checkCollide(player2->getDirection(), player2);
                    break;
                case Keyboard::D:
                    player2->setDirection(DIRECTION::RIGHT);
                    checkCollide(player2->getDirection(), player2);
                    break;
                case Keyboard::Z:
                    player2->setDirection(DIRECTION::UP);
                    checkCollide(player2->getDirection(), player2);
                    break;
                case Keyboard::S:
                    player2->setDirection(DIRECTION::DOWN);
                    checkCollide(player2->getDirection(), player2);
                    break;
                case Keyboard::E:
                    if (player2->useBomb((player2->getPosX() + 32) / 32, (player2->getPosY()) / 32)) {
                        (levelManager->getMap())->setElementOnMap(LAYERS::LAYER3, (player2->getPosX() + 32) / 32, (player2->getPosY()) / 32, (int)TILES::BUTTER);
                    }
                    break;
            }
        }

        
        
        
        
        switch(event.key.code){
                
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Keyboard::X:
                this->state = WORKFLOW::ROOMSSCREEN;
                break;
        }
        
    }
    
    
    window.clear();
    
    
    bombTick();
    
    this->levelManager->drawMap(window);
    this->levelManager->drawPlayers(window);
    
    

    //Fonction pour ajouter une image sur la map
    //lManager.addTile( (int)TILES::BUTTER, 6, 6, window);
    
    window.display();
}

void GameEngine::checkCollide(DIRECTION direction, Player* player){
    
    switch(direction){
        case DIRECTION::UP:
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) == (int)TILES::EMPTY
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) == (int)TILES::GROUND
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) != (int)TILES::BUTTER){
                player->setPosX(player->getPosX()-32);
            }
            break;
        case DIRECTION::DOWN:
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) == (int)TILES::EMPTY
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) == (int)TILES::GROUND
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) != (int)TILES::BUTTER){
                player->setPosX(player->getPosX()+32);
            }
            break;
        case DIRECTION::LEFT:
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) == (int)TILES::EMPTY
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) == (int)TILES::GROUND
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) != (int)TILES::BUTTER){
                player->setPosY(player->getPosY()-32);
            }
            break;
        case DIRECTION::RIGHT:
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) == (int)TILES::EMPTY
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) == (int)TILES::GROUND
                && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER3, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) != (int)TILES::BUTTER){
                player->setPosY(player->getPosY()+32);
            }
            break;
    }
    
}

void GameEngine::bombTick() {
    for (int i = 0; i < (this->levelManager)->getAllPlayer().size(); i++) {
        Player* currentPlayer = (this->levelManager)->getPlayerAt(i);
        Bomb* playerBombList = currentPlayer->bombs;
        for (int j = 0; j < currentPlayer->getBombsCapacity(); j++) {
            if (playerBombList[j].getActived() == 1) {
                playerBombList[j].setDelay(playerBombList[j].getDelay() - 1);
                if (playerBombList[j].getDelay() <= 0) {
                    this->bombExplosion(playerBombList[j]);
                    (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER3,playerBombList[j].getX(), playerBombList[j].getY(), (int)TILES::EMPTY);
                    currentPlayer->deleteBombAt(j);
                }
            }
        }
    }
}
/**
 * x up down
 * y left right
 */
void GameEngine::bombExplosion(Bomb bomb) {
    // up
    for (int i = 1; i <= bomb.getDistance(); i++) {
        if (bomb.getX() - i > 0) {
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX() - i, bomb.getY()) == (int)TILES::HAY) {
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER1,bomb.getX() - i, bomb.getY(), (int)TILES::EMPTY);
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER2,bomb.getX() - i, bomb.getY(), (int)TILES::GROUND);
                break;
            } else if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX() - i, bomb.getY()) == (int)TILES::PILLAER) {
                break;
            }
        } else {
            break;
        }
    }
    // down
    for (int i = 1; i <= bomb.getDistance(); i++) {
        if (bomb.getX() + i < (levelManager->getMap())->getSizeX() - 1) {
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX() + i, bomb.getY()) == (int)TILES::HAY) {
            
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER1,bomb.getX() + i, bomb.getY(), (int)TILES::EMPTY);
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER2,bomb.getX() + i, bomb.getY(), (int)TILES::GROUND);
                break;
            } else if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX() + i, bomb.getY()) == (int)TILES::PILLAER) {
                    break;
            }
        } else {
            break;
        }
    }
    // left
    for (int i = 1; i <= bomb.getDistance(); i++) {
        if (bomb.getY() - i > 0) {
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX(), bomb.getY() - i) == (int)TILES::HAY) {
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER1,bomb.getX(), bomb.getY() - i, (int)TILES::EMPTY);
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER2,bomb.getX(), bomb.getY() - i, (int)TILES::GROUND);
                break;
            } else if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX(), bomb.getY() - i) == (int)TILES::PILLAER) {
                break;
            }
        } else {
            break;
        }
    }
    // right
    for (int i = 1; i <= bomb.getDistance(); i++) {
        if (bomb.getY() + i < (levelManager->getMap())->getSizeY() - 1) {
            if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX(), bomb.getY() + i) == (int)TILES::HAY) {
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER1,bomb.getX(), bomb.getY() + i, (int)TILES::EMPTY);
                (this->levelManager->getMap())->setElementOnMap(LAYERS::LAYER2,bomb.getX(), bomb.getY() + i, (int)TILES::GROUND);
                break;
            } else if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, bomb.getX(), bomb.getY() + i) == (int)TILES::PILLAER) {
                break;
            }
        } else {
            break;
        }
    }
}









