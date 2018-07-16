//
//  LevelManager.cpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 11/06/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#include "LevelManager.hpp"


LevelManager::LevelManager(Map map) {
    this->map = map;
    if(map.getTilesetTexture().loadFromFile(map.getTilesetTexturePath())){
        this->map.getTileset().setTexture(map.getTilesetTexture());
        this->map.hasTileset = true;
        for(int i = 0; i < 4; i++){
            this->players[i] = NULL;
        }

    } else {
        cout << "Erreur durant le chargement de l'image du tileset." << endl;
    }
}

void LevelManager::loadMap(string filename) {
    int x, y;
    
    //flux de lecture du fichier
    fstream fin;
    
    //On crée un stringstream pour gérer nos chaînes
    stringstream iostr;
    
    //Chaine de caractère temp
    string strBuf, strTmp;
    
    //On ouvre le fichier
    fin.open(filename, fstream::in);
    
    //Si on échoue, on fait une erreur
    if (!fin.is_open())
    {
        cerr << "Erreur de chargement du fichier.\n";
        exit(1);
    }
    
    //De quoi contenir notre map
    vector < vector <string> > MapString;
    vector < string > lignes;
    
    //On lit notre fichier jusqu'à la fin (eof = end of file)
    while (!fin.eof())
    {
        //On récupère la ligne dans la chaîne strBuf
        getline(fin, strBuf);
        
        //Si la ligne est vide, on continue la boucle
        if (!strBuf.size())
            continue;
        
        //Sinon on poursuit et on réinitialise notre stringstream
        iostr.clear();
        
        //On y envoie le contenu du buffer strBuf
        iostr.str(strBuf);
        
        //On réinitialise le vecteur ligne
        lignes.clear();
        
        //On boucle pour lire chaque numéro de tile du fichier map
        while (true)
        {
            //Pour chaque ligne on récupère le numéro de la tile, en
            //les parsant grâce aux espaces qui les séparent (' ')
            getline(iostr, strTmp, ' ');
            
            //On récupère ce numéro dans dans notre vecteur ligne
            lignes.push_back(strTmp.c_str());
            
            //Si on a fini, on quitte la boucle
            if (!iostr.good()) break;
        }
        
        //Si le vecteur ligne n'est pas vide, on l'envoie dans notre vecteur à 2 dimensions
        if (lignes.size())
            MapString.push_back(lignes);
        
    }
    
    fin.close();
    
    map.setStartX(stoi(MapString[0][1]));
    map.setStartY(stoi(MapString[0][2]));
    changeMapSize(stoi(MapString[0][3]), stoi(MapString[0][4]));
    
    for (y = 1; y <= map.getSizeY(); y++) //On commence a 1 car la premiere ligne contient des valeur d'option
    {
        
        for (x = 0; x < map.getSizeX(); x++)
        {
            //On copie la valeur de notre Tableau
            //dans notre tableau tile à deux dimensions
            map.setElementOnMap(LAYERS::LAYER1, y-1, x, stoi(MapString[y][x]));
        }
        
    }
    
    for (y = 0; y < map.getSizeY(); y++)
    {
        for (x = 0; x < map.getSizeX(); x++)
        {
            map.setElementOnMap(LAYERS::LAYER2, y, x, stoi(MapString[(y+1) + map.getSizeY()][x]));
        }
    }
    
    //Puis pour la troisième :
    for (y = 0; y < map.getSizeY(); y++)
    {
        for (x = 0; x < map.getSizeX(); x++)
        {
            map.setElementOnMap(LAYERS::LAYER3, y, x, stoi(MapString[(y+1) + map.getSizeY() * 2][x]));
            
        }
    }
    
}

void LevelManager::drawMap(sf::RenderWindow &window) {
    
    if(this->map.hasTileset)
    {
        //Le max en X
        int x2 = this->map.getSizeX() * 32;
        
        //Le max en Y
        int y2 = this->map.getSizeY() * 32;
        
        //la ou le dessin doit commencer en X et en Y
        int mapX = 0, mapY = 0;
        
        //La tuile a dessiner à l'instant T en fonction de sa couche
        int tileFromLayer[3];
        
        
        
        //On va dessiner en Y
        for (int y = 0; y < y2; y += 32)
        {
            
            /* A chaque colonne de tile, on dessine la bonne tile en allant
             de x = 0 à x = 640 */
            for (int x = 0; x < x2; x += 32)
            {
                tileFromLayer[0] = this->map.getLayer2()[mapY][mapX];
                tileFromLayer[1] = this->map.getLayer1()[mapY][mapX];
                tileFromLayer[2] = this->map.getLayer3()[mapY][mapX];
                
                for(int i = 0; i < 3; i++)
                {
                    if(tileFromLayer[i] != 0)
                    {
                        /* Calcul pour obtenir son y (pour un tileset de 10 tiles
                         par ligne, d'où le 10 */
                        int ysource = 0;
                        
                        /* Et son x */
                        int xsource = tileFromLayer[i] * 32;
                        
                        map.getTileset().setPosition(y, x);
                        map.getTileset().setTextureRect(sf::IntRect(xsource, ysource, 32, 32));
                        window.draw(map.getTileset());
                        
                    }
                }
                mapX++;
            }
            mapX = 0;
            mapY++;
        }
        mapY = 0;
    }
}

void LevelManager::changeMapSize(int sizeX, int sizeY) {
    
    map.setSizeX(sizeX);
    map.setSizeY(sizeY);
    
    map.initLayers();
    
    
}

void LevelManager::addTile(int tile, int position_x, int position_y, sf::RenderWindow &window) {
    
    map.getTileset().setPosition(position_y*32, position_x*32);
    map.getTileset().setTextureRect(sf::IntRect(tile*32, 0, 32, 32));
    window.draw(map.getTileset());
    
}

void LevelManager::addPlayer(Player player) {
    
    if(player.getTilesetTexture().loadFromFile(player.getTilesetTexturePath())){
        player.getTileset().setTexture(player.getTilesetTexture());
        
        for(int i = 0; i < 4; i++){
            if(this->players[i] == NULL){
                this->players[i] = &player;
                return;
            }
        }
        
    } else {
       // cout << "Erreur durant le chargement de l'image du player." << endl;
    }
    
}

void LevelManager::drawPlayers(sf::RenderWindow &window) {

    
    for(int i = 0; i < 4; i++){
        if(this->players[i] != NULL && this->players[i]->getPv() > 0){
            float JPosX = this->players[i]->getPosX();
            float JPosY = this->players[i]->getPosY();
            int directionValue = (int) this->players[i]->getDirection();
            int timer = this->players[i]->timerAnimation;
            
            int tilePos = directionValue+(28*timer);
            
            players[i]->getTileset().setPosition(JPosY, JPosX);
           
            players[i]->getTileset().setTextureRect(sf::IntRect(tilePos, 0, 28, 47));
            window.draw(players[i]->getTileset());
        }
    }
    
}

Player *LevelManager::getPlayerAt(int i) {
    return this->players[i];
}
vector<Player*> LevelManager::getAllPlayer() {
    vector<Player*> listPlayer = *new vector<Player*>;
    for(int i = 0; i < 4; i++){
        if(this->players[i] != NULL){
            listPlayer.push_back(this->players[i]);
        } else {
            break;
        }
    }
    return listPlayer;
    
}

Map *LevelManager::getMap() {
    return &this->map;
}







