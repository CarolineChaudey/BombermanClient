//
//  RoomMenu.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 21/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef RoomMenu_hpp
#define RoomMenu_hpp
#include <SFML/Graphics.hpp>
#include <iostream>
#include <stdio.h>
#include "IMenu.hpp"
#include "GameServerService.hpp"
#include "Lobby.cpp"

using namespace std;

class RoomMenu : public IMenu {
    
public:
    RoomMenu(float width, float height, string fontname);
    ~RoomMenu();
    
     void refresh();
     void UpSelection();
     void DownSelection();
     void drawMenu(sf::RenderWindow &window);   
     void GetPressedItem();

private:
    GameServerService *serverService = new GameServerService();
    Lobby* lobbies;
    float width;
    float height;
};

#endif /* RoomMenu_hpp */
