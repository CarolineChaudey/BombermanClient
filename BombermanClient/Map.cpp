#include "Map.hpp"


Map::Map() {
    tileset_id = 0;
    level_id = 0;
    
    layer_1 = NULL;
    layer_2 = NULL;
    layer_3 = NULL;
    
    start_x = start_y = 0;
    max_x = max_y = 0;
    size_x = size_y = 0;
    
    tileset_texture = *new Texture();
    tileset = *new Sprite();

}

Map::Map(int size_x, int size_y) {
    tileset_id = 0;
    level_id = 0;
    
    layer_1 = NULL;
    layer_2 = NULL;
    layer_3 = NULL;
    
    start_x = start_y = 0;
    max_x = max_y = 0;
    this->size_x = size_x;
    this->size_y = size_y;
    
    tileset_texture = *new Texture();
    tileset = *new Sprite();
    
}

int Map::getTilesetId() const {
    return this->tileset_id;
}

int Map::getLevelId() const {
    return this->level_id;
}

int **Map::getLayer1() {
    return this->layer_1;
}

int **Map::getLayer2() {
    return this->layer_2;
}

int **Map::getLayer3() {
    return this->layer_3;
}

int Map::getSizeX() const {
    return this->size_x;
}

int Map::getSizeY() const {
    return this->size_y;
}

int Map::getStartX() const {
    return this->start_x;
}

int Map::getStartY() const {
    return this->start_y;
}

int Map::getMaxX() const {
    return this->max_x;
}

int Map::getMaxY() const {
    return this->max_y;
}

int Map::getElementOnMap(LAYERS layer, int x, int y) {
    switch(layer){
        case LAYERS::LAYER1:
            return this->layer_1[x][y];
        case LAYERS::LAYER2:
            return this->layer_2[x][y];
        case LAYERS::LAYER3:
            return this->layer_3[x][y];
        default:
            return 0;
    };
}

void Map::setTilesetId(int id) {
    this->tileset_id = id;
}

void Map::setLevelId(int id) {
    this->level_id = id;
}

void Map::setLayer1(int **layer) {
    this->layer_1 = layer;
}

void Map::setLayer2(int **layer) {
    this->layer_2 = layer;
}

void Map::setLayer3(int **layer) {
    this->layer_3 = layer;
}

void Map::setSizeX(int sizeX) {
    this->size_x = sizeX;
}

void Map::setSizeY(int sizeY) {
    this->size_y = sizeY;
}

void Map::setStartX(int x) {
    this->start_x = x;
}

void Map::setStartY(int y) {
    this->start_y = y;
}

void Map::setMaxX(int maxX) {
    this->max_x = maxX;
}

void Map::setMaxY(int maxY) {
    this->max_y = maxY;
}

void Map::setElementOnMap(LAYERS layer, int x, int y, int value) {
    switch(layer){
        case LAYERS::LAYER1:
            this->layer_1[x][y] = value;
        case LAYERS::LAYER2:
            this->layer_2[x][y] = value;
        case LAYERS::LAYER3:
            this->layer_3[x][y] = value;
        default:
            return;
    };
}

sf::Texture Map::getTilesetTexture() const { 
    return this->tileset_texture;
}

sf::Sprite Map::getTileset() const { 
    return this->tileset;
}

