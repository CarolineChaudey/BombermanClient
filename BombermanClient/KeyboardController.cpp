//
//  KeyboardController.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 18/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "KeyboardController.hpp"


KEYS KeyboardController::manageEvent(sf::RenderWindow &window, sf::Event event) {
 
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
            }
            break;
        case sf::Event::Closed:
            window.close();
            break;
            
    }

}
