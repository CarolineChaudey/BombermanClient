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

using namespace std;

class RoomMenu : public IMenu {
    
public:
    RoomMenu(float width, float height, int nb_room, string fontname);
  //  RoomMenu(float width, float height, string fontname, Lobby* lobbies = nullptr, int nbLobbies = 0);
    ~RoomMenu();
    
     void buildMenu(int nbLobbies);
     void UpSelection();
     void DownSelection();
     void drawMenu(sf::RenderWindow &window);   
     int GetPressedItem();
     void refreshMenu(Lobby *lobbies, int nbLobbies);

private:
    sf::Texture background;
    sf::Sprite sbackground;
    bool isCurrentLobby(int index);
    
    float width;
    float height;
};

#endif /* RoomMenu_hpp */
