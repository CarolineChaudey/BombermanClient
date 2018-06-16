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
        map.getTileset().setTexture(map.getTilesetTexture());
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
            map.setElementOnMap(LAYERS::LAYER1, y, x, stoi(MapString[y][x]));
        }
        
        
    }
    for (y = 0; y < map.getSizeY(); y++)
    {
        for (x = 0; x < map.getSizeX(); x++)
        {
            
            map.setElementOnMap(LAYERS::LAYER2, x, y, stoi(MapString[y + map.getSizeY()][x]));
        }
    }
    //Puis pour la troisième :
    for (y = 0; y < map.getSizeY(); y++)
    {
        for (x = 0; x < map.getSizeX(); x++)
        {
            map.setElementOnMap(LAYERS::LAYER3, x, y, stoi(MapString[y + map.getSizeY() * 2][x]));
            
        }
    }
    
    map.printLayers();
   /*if(map->TilesetTexture.isNull())
    {
        ChargerTileset();
        drawMap();
        drawGrill();
    }*/
    
}

void LevelManager::drawMap(int layer, sf::RenderWindow &window) { 
    
}

void LevelManager::changeMapSize(int sizeX, int sizeY) {
    
    map.setSizeX(sizeX);
    map.setSizeY(sizeY);
    
    map.initLayers();
    
    
}



