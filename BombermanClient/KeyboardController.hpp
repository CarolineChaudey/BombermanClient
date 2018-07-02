//
//  KeyboardController.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 18/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef KeyboardController_hpp
#define KeyboardController_hpp

#include <stdio.h>
#include "IController.hpp"



class KeyboardController : public IController{
public:
    virtual KEYS manageEvent(sf::Event event);
    
};

#endif /* KeyboardController_hpp */
