#include <cstdlib>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include "DDGEngine/MainMenu.hpp"

std::unique_ptr<GameState> currentState;

int main() {
    srand(time(0));

    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Septica Game");
    GameContext context;
    sf::Font font;
    std::string dir = std::getenv("CURRENT_DIR");

    if(dir.empty()) {
        std::cerr << "Environment variable not found.\n";
    }

    std::replace(dir.begin(), dir.end(), '\\', '/'); 
    std::string font_path = dir + "/assets/fonts/ppfont.ttf";

    if(!font.loadFromFile(font_path)) {
        return -1;
    }

    context.font = &font;
    currentState = std::make_unique<MainMenu>(context);

    sf::Clock clock;
    sf::Time deltaTime;

    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (currentState)
                currentState->handleEvent(event, window);
        }

        deltaTime = clock.restart();

        if (currentState)
            currentState->update(deltaTime, window);

        window.clear();
        if (currentState)
            currentState->render(window);
        window.display();

    }

    return 0;
}
