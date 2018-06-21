//
//  IController.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 18/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef IController_hpp
#define IController_hpp

#include <SFML/Graphics.hpp>
#include <stdio.h>

enum class KEYS { UP, LEFT, RIGHT, DOWN };

class IController{
    
public:
    virtual ~IController() {};
    virtual KEYS manageEvent(sf::RenderWindow &window, sf::Event event) = 0;

    
};

#endif /* IController_hpp */
