//
//  Game.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 07/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef GameEngine_hpp
#define GameEngine_hpp

#include <stdio.h>
#include "LevelManager.hpp"
#include "IController.hpp"
#include "IMenu.hpp"
#include "RoomMenu.hpp"
#include "GameServerService.hpp"
#include "StringUtil.hpp"


enum class WORKFLOW {TITLESCREEN, ROOMSSCREEN, GAMESCREEN};

class GameEngine{
  
public:
    GameEngine(LevelManager* levelManager, IController* controller);
    GameEngine(LevelManager* levelManager, IController* controller, WORKFLOW state);
    ~GameEngine();

    void launchGameEngine(sf::RenderWindow &window);
    struct LobbyList getLobbies();
    bool isYourTurn = false;
    
    void checkCollide(DIRECTION direction, Player* player);

    
    
private:
    LevelManager* levelManager;
    IController* controller;
    WORKFLOW state;
    vector <Bomb> bonbList;
    GameServerService* gameServer = new GameServerService();


    void launchTitleScreen(sf::RenderWindow &window, IMenu* menu);
    void launchRoomScreen(sf::RenderWindow &window, IMenu* menu);
    void launchGameScreen(sf::RenderWindow &window);
    void bombTick();
    void bombExplosion(Bomb bomb);
    
    
    
};


#endif /* Game_hpp */
