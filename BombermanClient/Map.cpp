#include "Map.hpp"


Map::Map() {
    tileset_id = 0;
    level_id = 0;
    
    layer_1 = *new vector <vector <int>>;
    layer_2 = *new vector <vector <int>>;
    layer_3 = *new vector <vector <int>>;
    
    start_x = start_y = 0;
    max_x = max_y = 0;
    size_x = size_y = 0;
    
    tileset_texture = new Texture();
    tileset = new Sprite();

}

Map::Map(int size_x, int size_y) {
    tileset_id = 0;
    level_id = 0;
    
    
    start_x = start_y = 0;
    max_x = max_y = 0;
    this->size_x = size_x;
    this->size_y = size_y;
    
    initLayers();
    
    tileset_texture = new Texture();
    tileset = new Sprite();
    
}

int Map::getTilesetId() const {
    return this->tileset_id;
}

int Map::getLevelId() const {
    return this->level_id;
}

vector <vector <int>> Map::getLayer1() {
    return this->layer_1;
}

vector <vector <int>> Map::getLayer2() {
    return this->layer_2;
}

vector <vector <int>> Map::getLayer3() {
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
            return this->layer_1[y][x];
        case LAYERS::LAYER2:
            return this->layer_2[y][x];
        case LAYERS::LAYER3:
            return this->layer_3[y][x];
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

void Map::setLayer1(vector <vector <int>> layer) {
    this->layer_1 = layer;
}

void Map::setLayer2(vector <vector <int>> layer) {
    this->layer_2 = layer;
}

void Map::setLayer3(vector <vector <int>> layer) {
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
            layer_1[y][x] = value;
        case LAYERS::LAYER2:
            layer_2[y][x] = value;
        case LAYERS::LAYER3:
            layer_3[y][x] = value;
        default:
            return;
    };
}

sf::Texture& Map::getTilesetTexture() {
    return *this->tileset_texture;
}

sf::Sprite& Map::getTileset() {
    return *this->tileset;
}

void Map::setTilesetTexture(sf::Texture *texture) {
    this->tileset_texture = texture;
}

void Map::setTileset(sf::Sprite *sprite) {
    this->tileset = sprite;
}

void Map::setTilesetTexturePath(std::string path) { 
    this->tileset_texture_path = path;
}

void Map::setTilesetPath(std::string path) { 
    this->tileset_path = path;
}

std::string Map::getTilesetTexturePath() const { 
    return this->tileset_texture_path;
}

std::string Map::getTilesetPath() const { 
    return this->tileset_path;
}

void Map::initLayers() {
    
    for(int i = 0; i < this->size_x; i++)
    {
        layer_1.push_back(*new vector<int>(this->size_y));
        layer_2.push_back(*new vector<int>(this->size_y));
        layer_3.push_back(*new vector<int>(this->size_y));
        
        for(int j = 0; j < this->size_y; j++)
        {
            layer_1[i][j] = layer_2[i][j] = layer_3[i][j] = 0;
        }
    }
}

void Map::printLayers() { 
    for(int i = 0; i < this->size_x; i++)
    {
        for(int j = 0; j < this->size_y; j++)
        {
            cout << layer_1[i][j];
            cout << " ";
            cout << layer_2[i][j];
            cout << " ";
            cout << layer_3[i][j];
            cout << " ";
        }
        cout << endl;
    }
}






