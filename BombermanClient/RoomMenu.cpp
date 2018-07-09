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
#include "Lobby.cpp"
#include <string>


Lobby* convertToLobbies(std::vector<std::string> raw) {
    Lobby* lobbies = new Lobby[raw.size()];
    for (int i = 0; i < raw.size(); i++) {
        std::string room = raw[i];
        lobbies[i].setId(room[0] - '0');
        lobbies[i].setNbPlayers(room[2] - '0');
        lobbies[i].setMaxPlayers(room[4] - '0');
    }
    return lobbies;
}

RoomMenu::RoomMenu(float width, float height, string fontname) {
    // la fenêtre ne s'affiche pas tant que la connexion n'est pas établie
    // TODO écran de chargement
    GameServerService* serverService = new GameServerService();
    std::string rawResults = serverService->getRooms();
    std::vector<std::string> strRooms = split(rawResults, ';');
    int nbRooms = strRooms.size() - 1; // -1 because of the last ;
    Lobby* lobbies = convertToLobbies(strRooms);

    this->menu = *new vector<sf::Text>(nbRooms);

    if (!this->font.loadFromFile(fontname)) {
        cout << "Impossible de charger la font" << endl;
        
    }
    
    for(int i = 0; i < nbRooms; i++){
        Lobby lobby = lobbies[i];
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
    selectedItemIndex = 0;
}

RoomMenu::~RoomMenu() noexcept {
    
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

