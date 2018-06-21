//
//  RoomMenu.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 21/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "RoomMenu.hpp"


RoomMenu::RoomMenu(float width, float height, int nb_room, string fontname) {
    
    this->menu = *new vector<sf::Text>(nb_room);
    
    
    if (!this->font.loadFromFile(fontname)) {
        cout << "Impossible de charger la font" << endl;
        
    }
    
    for(int i = 0; i < nb_room; i++){
        this->menu[i].setString("Room : " + std::to_string(i));
        this->menu[i].setFont(this->font);
        this->menu[i].setCharacterSize(50);
        this->menu[i].setFillColor(sf::Color::White);
        this->menu[i].setPosition(width / 3, height / (menu.size() + 1) * (i+1));
    }
    selectedItemIndex = 0;
    
    
}

RoomMenu::~RoomMenu() noexcept {
    
}


void RoomMenu::UpSelection(){
    this->selectedItemIndex++;
}

void RoomMenu::DownSelection(){
    this->selectedItemIndex--;
}

void RoomMenu::drawMenu(sf::RenderWindow &window) {
    for (int i = 0; i < this->menu.size(); i++)
    {
        window.draw(this->menu[i]);
    }
}

int RoomMenu::GetPressedItem() {
    return this->selectedItemIndex;
}

