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

using namespace std;

class IMenu{
    
public:
    
    virtual ~IMenu() {};
    virtual void UpSelection() = 0;
    virtual void DownSelection() = 0;
    virtual void drawMenu(sf::RenderWindow &window) = 0;
    virtual void GetPressedItem() = 0;
    
protected:
    int selectedItemIndex;
    sf::Font font;
    vector<sf::Text> menu;
};

#endif /* IMenu_hpp */
