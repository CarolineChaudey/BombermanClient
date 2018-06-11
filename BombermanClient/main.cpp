
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

void getRoomsFromServer() {
    GameServerService* gameServerService = new GameServerService();
    char recvline[100] = "";
    //getRooms(recvline);
    gameServerService->getRooms(recvline);
    printf("%s\n", recvline);
}

//This is the main class
int main(int, char const**)
{
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 1000), "Bon beurre man");

    // Set the Icon
    sf::Image icon;
    if (!icon.loadFromFile(resourcePath() + "icon.png")) {
        return EXIT_FAILURE;
    }
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile(resourcePath() + "sansation.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text text("Recherche de parties ...", font, 50);
    text.setFillColor(sf::Color::White);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile(resourcePath() + "nice_music.ogg")) {
        return EXIT_FAILURE;
    }

    // Play the music
    music.play();
    
    // test function getRoomsFromServer
    // à déplacer pour en extraire les infos et lancer la page des rooms
    getRoomsFromServer();

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            // Escape pressed: exit
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }
        }

        // Clear screen
        window.clear();
        // Draw the string
        window.draw(text);
        // Update the window
        window.display();
    }

    return EXIT_SUCCESS;
}
