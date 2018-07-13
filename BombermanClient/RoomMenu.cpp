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

    GameServerService* serverService = new GameServerService();
    std::string rawResults = serverService->getRooms();
    std::vector<std::string> strRooms = split(rawResults, ';');
    int nbRooms = (int) strRooms.size() - 1; // -1 because of the last ;
    Lobby* lobbies = convertToLobbies(strRooms);
    this->menu = *new vector<sf::Text>(nbRooms);
    this-> width = width;
    this->height = height;


    if (!this->font.loadFromFile(fontname)) {
        cout << "Impossible de charger la font" << endl;
    }
    
    selectedItemIndex = 0;
    
    if (lobbies != nullptr) {
        this->lobbies = lobbies;
        IMenu::setNbLobbies(nbLobbies);
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
        this->menu[i].setPosition(width / 5, height / (menu.size() + 1.5) * (i+1));
        if (IMenu::getInItemIndex() == i) {
            this->menu[i].setFillColor(sf::Color::Yellow);
        } else if (this->GetPressedItem() == i) {
            this->menu[i].setFillColor(sf::Color::Red);
        } else {
            this->menu[i].setFillColor(sf::Color::White);
        }
    }
    //this->menu[0].setFillColor(sf::Color::Red);
}

void RoomMenu::refreshMenu(Lobby *lobbies, int nbLobbies) {
    std::cout << "refresh menu \n";
    this->lobbies = lobbies;
    IMenu::setNbLobbies(nbLobbies);
    this->buildMenu(nbLobbies);
}

void RoomMenu::UpSelection(){
    if(this->selectedItemIndex > 0){
        if (!isCurrentLobby(selectedItemIndex)) { // priority on showing it is the room we are currently waiting in
            this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        }
        this->selectedItemIndex--;
        if (!isCurrentLobby(selectedItemIndex)) { // priority on showing it is the room we are currently waiting in
            this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }
}

void RoomMenu::DownSelection(){
    if((this->selectedItemIndex + 1) < IMenu::getNbLobbies()){
        if (!isCurrentLobby(selectedItemIndex)) { // priority on showing it is the room we are currently waiting in
            this->menu[selectedItemIndex].setFillColor(sf::Color::White);
        }
        this->selectedItemIndex++;
        if (!isCurrentLobby(selectedItemIndex)) { // priority on showing it is the room we are currently waiting in
            this->menu[selectedItemIndex].setFillColor(sf::Color::Red);
        }
    }
}

bool RoomMenu::isCurrentLobby(int index) {
    return index == IMenu::getInItemIndex();
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

int IMenu::getInItemIndex() const {
    return this->inItemIndex;
}

void IMenu::setInItemIndex(int index) {
    this->inItemIndex = index;
}

int IMenu::getNbLobbies() {
    return this->nbLobbies;
}

void IMenu::setNbLobbies(int nb) {
    this->nbLobbies = nb;
}
