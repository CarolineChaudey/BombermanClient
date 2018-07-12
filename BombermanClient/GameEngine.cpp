//
//  Game.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 07/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "GameEngine.hpp"

struct LobbyList {
    int size;
    Lobby *lobbies;
} LobbyList;


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
    ll.size = strRooms.size() - 1; // -1 because of the last ; in the splitted string
    return ll;
}

void GameEngine::launchGameEngine(sf::RenderWindow &window) {
    struct LobbyList lobbyList = this->getLobbies();
    IMenu* menu = new RoomMenu(window.getSize().x, window.getSize().y, resourcePath() + "sansation.ttf", lobbyList.lobbies, lobbyList.size);
    
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
                int itemPosition = menu->GetPressedItem();
                Lobby* lobbies = menu->getLobbies();
                Lobby choosenLobby = lobbies[itemPosition];
                std::cout << "Choosed : " << choosenLobby.getId() << "\n";
                bool serverAnswer = this->gameServer->chooseRoom(choosenLobby.getId());
                if (serverAnswer) {
                    menu->setInItemIndex(itemPosition);
                    // refresh data
                    struct LobbyList ll = this->getLobbies();
                    menu->refreshMenu(ll.lobbies, ll.size);
                }
                //this->state = WORKFLOW::GAMESCREEN;
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
    
    while (window.pollEvent(event))
    {
        KEYS key = controller->manageEvent(event);
        
        
        switch (key) {
            case KEYS::LEFT:
                player->setDirection(DIRECTION::LEFT);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) == (int)TILES::EMPTY
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX() + 32) / 32 , (player->getPosY()-32) / 32) == (int)TILES::GROUND){
                    player->setPosY(player->getPosY()-32);
                }
                break;
            case KEYS::RIGHT:
                player->setDirection(DIRECTION::RIGHT);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) == (int)TILES::EMPTY
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32) / 32 , (player->getPosY()+32) / 32) == (int)TILES::GROUND){
                    player->setPosY(player->getPosY()+32);
                }
                break;
            case KEYS::UP:
                player->setDirection(DIRECTION::UP);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) == (int)TILES::EMPTY
                    && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32-32) / 32 , (player->getPosY()) / 32) == (int)TILES::GROUND){
                    player->setPosX(player->getPosX()-32);
                }
                break;
            case KEYS::DOWN:
                player->setDirection(DIRECTION::DOWN);
                if ((levelManager->getMap())->getElementOnMap(LAYERS::LAYER1, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) == (int)TILES::EMPTY
                 && (levelManager->getMap())->getElementOnMap(LAYERS::LAYER2, (player->getPosX()+32+32) / 32 , (player->getPosY()) / 32) == (int)TILES::GROUND){
                    player->setPosX(player->getPosX()+32);
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



