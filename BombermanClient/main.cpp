
//
// Disclaimer:
// ----------
//
// This code will work only if you selected window, graphics and audio.
//
// Note that the "Run Script" build phase will copy the required frameworks
// or dylibs to your application bundle so you can execute it on any OS X
// computer.
//
// Your resource files (images, sounds, fonts, ...) are also copied to your
// application bundle. To get the path to these resources, use the helper
// function `resourcePath()` from ResourcePath.hpp
//


//Main s'occupe de lancer menu
//Menu s'occupe de lancer game
//Game s'occupe de lancer une map avec son manager
//Le manager fait l'échange entre la map et le réseau
//il y'a un manager pour chaque chose ( menu, options, game ...)


#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

// Here is a small helper for you! Have a look.
#include "ResourcePath.hpp"
#include "GameServerService.hpp"
#include "LevelManager.hpp"
#include "Map.hpp"
#include "IController.hpp"
#include "KeyboardController.hpp"
#include "GameEngine.hpp"

void getRoomsFromServer() {
    GameServerService* gameServerService = new GameServerService();
    char recvline[100] = "";
    gameServerService->getRooms(recvline);
    printf("%s\n", recvline);
}

bool introScreen = false;
bool roomsScreen = true;
bool gameScreen = false;


//This is the main class
int main(int, char const**)
{
    Map myMap = *new Map();
    myMap.setTilesetTexturePath(resourcePath() + "bonbeurremanTileset.png");
    
    LevelManager lManager = *new LevelManager(myMap);
    lManager.loadMap(resourcePath() + "BonBeurreMap1.txt");
    
    Player playerOne = *new Player();
    playerOne.setTilesetTexturePath(resourcePath() + "fermie01rSpriteSheet.gif");
    playerOne.setPv(1);
    playerOne.setPosX(32);
    playerOne.setPosY(32);
    playerOne.setSpeed(10);
    playerOne.setNumero(0);
    playerOne.setDirection(DIRECTION::DOWN);
    playerOne.setBombsCapacity(0);
    lManager.addPlayer(playerOne);
    
    
    // Create the main window
    sf::RenderWindow window(VideoMode(800, 600), "Bon beurre man");
    
    // IMenu menu = RoomMenu(window.getSize().x, window.getSize().y);

    
    IController* ctrl = new KeyboardController();
    
    // Set the Icon
    //    sf::Image icon;
    //    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
    //        return EXIT_FAILURE;
    //    }
    //    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
    //
    //    // Create a graphical text to display
    //    sf::Font font;
    //    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
    //        return EXIT_FAILURE;
    //    }
    //    sf::Text text("Recherche de parties ...", font, 50);
    //    text.setFillColor(sf::Color::White);
    //
    //    // Load a music to play
    //    sf::Music music;
    //    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
    //        return EXIT_FAILURE;
    //    }
    //
    //    //Play the music
    //    music.play();
    //
    //
    // test function getRoomsFromServer
    // à déplacer pour en extraire les infos et lancer la page des rooms
    // getRoomsFromServer();
    
    //On active la synchro verticale
    window.setVerticalSyncEnabled(true);
    
    
    GameEngine gameEngine = *new GameEngine(&lManager, ctrl);
    
    gameEngine.launchGameEngine(window);
    

    
    return EXIT_SUCCESS;
}
