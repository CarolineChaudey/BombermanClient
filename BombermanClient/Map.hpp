//
//  Map.hpp
//  BombermanClient
//
//  Created by Benjamin Metaut on 19/05/2018.
//  Copyright © 2018 Caroline Chaudey. All rights reserved.
//

#ifndef Map_h
#define Map_h

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

#include "ResourcePath.hpp"

using namespace std;
using namespace sf;

enum class LAYERS { LAYER1, LAYER2, LAYER3 };

class Map{

public:
    //CONSTRUCTOR
    Map();
    Map(int size_x, int size_y);

    //GETTERS
    int getTilesetId()const;
    int getLevelId()const;
    
    vector <vector <int>> getLayer1();
    vector <vector <int>> getLayer2();
    vector <vector <int>> getLayer3();
    
    int getSizeX()const;
    int getSizeY()const;
    
    int getStartX()const;
    int getStartY()const;
    
    int getMaxX()const;
    int getMaxY()const;
    
    string getTilesetTexturePath()const;
    string getTilesetPath()const;
    
    sf::Texture getTilesetTexture()const;
    sf::Sprite getTileset()const;
    
    int getElementOnMap(LAYERS layer, int x, int y);
    
    //SETTERS
    void setTilesetId(int id);
    
    void setLevelId(int id);
    
    void setLayer1(vector <vector <int>> layer);
    void setLayer2(vector <vector <int>> layer);
    void setLayer3(vector <vector <int>> layer);
    
    void setSizeX(int sizeX);
    void setSizeY(int sizeY);
    
    void setStartX(int x);
    void setStartY(int y);
    
    void setMaxX(int maxX);
    void setMaxY(int maxY);
    
    void setTilesetTexturePath(string path);
    void setTilesetPath(string path);
    
    void setTilesetTexture(sf::Texture texture);
    void setTileset(sf::Sprite sprite);
    
    void setElementOnMap(LAYERS layer, int y, int x, int value);
    
    void initLayers();
    
    void printLayers();
    
private:
    //Numéro du tileset à utiliser pour dessiner la map
    int tileset_id;
    
    //Numéro du level en cours
    int level_id;
    
    //Map representé en 3 plan
    vector <vector <int>> layer_1;
    vector <vector <int>> layer_2;
    vector <vector <int>> layer_3;
    
    //Coordonnées de démarrage pour le dessin de la map
    int start_x;
    int start_y;
    
    //Coordonnées de fin pour le dessin de la map
    int max_x;
    int max_y;
    
    //Taille de la map
    int size_x;
    int size_y;
    
    //TilesetsPath
    string tileset_texture_path;
    string tileset_path;
    
    //Tilesets
    sf::Texture tileset_texture;
    sf::Sprite tileset;
    
    
};

#endif /* Map_h */
