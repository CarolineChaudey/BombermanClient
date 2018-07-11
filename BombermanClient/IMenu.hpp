//
//  IMenu.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 21/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef IMenu_hpp
#define IMenu_hpp

#include <stdio.h>
#include "Lobby.hpp"

using namespace std;

class IMenu{
    
public:
    
    virtual ~IMenu() {};
    virtual void UpSelection() = 0;
    virtual void DownSelection() = 0;
    virtual void drawMenu(sf::RenderWindow &window) = 0;
    virtual int GetPressedItem() = 0;
    virtual Lobby* getLobbies();
    virtual void refreshMenu(Lobby *lobbies, int nbLobbies) = 0;
    virtual int getInItemIndex() const;
    virtual void setInItemIndex(int index);
    virtual int getNbLobbies();
    virtual void setNbLobbies(int nb);
    
protected:
    Lobby* lobbies;
    int nbLobbies = 0;
    int inItemIndex = -1; // the room we are in
    int selectedItemIndex; // the room the cursor is on
    sf::Font font;
    vector<sf::Text> menu;
};

#endif /* IMenu_hpp */
