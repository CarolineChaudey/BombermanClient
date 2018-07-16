//
//  KeyboardController.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 18/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "KeyboardController.hpp"


KEYS KeyboardController::manageEvent(sf::Event event) {
 
    switch (event.type)
    {
        case sf::Event::KeyReleased:
            switch(event.key.code){
                case sf::Keyboard::Up:
                    return KEYS::UP;
                case sf::Keyboard::Down:
                    return KEYS::DOWN;
                case sf::Keyboard::Left:
                    return KEYS::LEFT;
                case sf::Keyboard::Right:
                    return KEYS::RIGHT;
                //case sf::Keyboard::Enter:
                case sf::Keyboard::Space:
                    return KEYS::ENTER;
                case sf::Keyboard::Return:
                    return KEYS::RETURN;
                case sf::Keyboard::B:
                    return KEYS::BOMB;
                default:
                    return KEYS::NOKEY;
                    
            }
            break;
        case sf::Event::Closed:
            return KEYS::EXIT;
            break;
            
        default:
            return KEYS::NOKEY;
            
    }

}
