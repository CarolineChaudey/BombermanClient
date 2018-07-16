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

enum class KEYS {NOKEY, BOMB, UP, LEFT, RIGHT, DOWN, BOMB2, UP2, LEFT2, RIGHT2, DOWN2, EXIT, ENTER, RETURN};

class IController{
    
public:
    virtual ~IController() {};
    virtual KEYS manageEvent(sf::Event event) = 0;

    
};

#endif /* IController_hpp */
