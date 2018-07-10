//
//  RoomMenu.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 21/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "RoomMenu.hpp"
#include "GameServerService.hpp"
#include "StringUtil.hpp"
#include <string>


RoomMenu::RoomMenu(float width, float height, string fontname, Lobby* lobbies, int nbLobbies) {
    // la fenêtre ne s'affiche pas tant que la connexion n'est pas établie
    // TODO écran de chargement
   
    this-> width = width;
    this->height = height;

    if (!this->font.loadFromFile(fontname)) {
        cout << "Impossible de charger la font" << endl;
    }
    
    selectedItemIndex = 0;
    
    if (lobbies != nullptr) {
        this->lobbies = lobbies;
        buildMenu(nbLobbies);
    }
}

RoomMenu::~RoomMenu() noexcept {
    
}

void RoomMenu::buildMenu(int nbLobbies) {
    this->menu = *new vector<sf::Text>(nbLobbies);
    
    for(int i = 0; i < nbLobbies; i++){
        Lobby lobby = this->lobbies[i];
        string room = "Room " + std::to_string(lobby.getId())
        + " : " + std::to_string(lobby.getNbPlayers())
        + " / " + std::to_string(lobby.getMaxPlayers()) + " players";
        this->menu[i].setString(room);
        this->menu[i].setFont(this->font);
        this->menu[i].setCharacterSize(50);
        this->menu[i].setFillColor(sf::Color::White);
        this->menu[i].setPosition(width / 5, height / (menu.size() + 1.5) * (i+1));
    }
    this->menu[0].setFillColor(sf::Color::Red);
}

void RoomMenu::refreshMenu(Lobby *lobbies, int nbLobbies) {
    std::cout << "refresh menu \n";
    this->lobbies = lobbies;
    this->buildMenu(nbLobbies);
}

void RoomMenu::UpSelection(){
    if(this->selectedItemIndex > 0){
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex--;
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
}

void RoomMenu::DownSelection(){
    if(this->selectedItemIndex < 3){
        this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        this->selectedItemIndex++;
        this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
    }
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

Lobby* IMenu::getLobbies() {
    return this->lobbies;
}

void IMenu::inLobby(int i) {
    this->menu[i].setFillColor(sf::Color::Yellow);
}

