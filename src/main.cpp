#include <cstdlib>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include "DDGEngine/MainMenu.hpp"
#include "GameState.hpp"

int main() {
    srand(time(0));

    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Septica Game");
    bool isFullscreen = false;
    auto context = std::make_shared<GameContext>();
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

    context->font = &font;
    context->window = &window;
    context->isFullscreen = isFullscreen;
    currentState = std::make_unique<MainMenu>(context);

    sf::Clock clock;
    sf::Time deltaTime;
    DEBUG_LOG("[MAIN LOOP START]\n");

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // DEBUG_LOG("[POLL EVENT]: " << event.type << "\n");
            if (event.type == sf::Event::Closed)
                window.close();

            // DEBUG_LOG("[HANDLE EVENT]\n");
            if (currentState)
                currentState->handleEvent(event, window);
            // DEBUG_LOG("[HANDLE DONE]\n");
        }

        deltaTime = clock.restart();

        if (context->pendingStateChange) {
            context->pendingStateChange();
            context->pendingStateChange = nullptr;
        }

        // DEBUG_LOG("[UPDATE]\n");
        if (currentState)
            currentState->update(deltaTime, window);
        // DEBUG_LOG("[UPDATE DONE]\n");

        if (context->toggleFullscreen) {
            DEBUG_LOG("Recreating window now...\n");
            context->toggleFullscreen= false;

            context->isFullscreen = !context->isFullscreen;

            if (context->isFullscreen) {
                window.create(sf::VideoMode::getDesktopMode(), "SepticaGame", sf::Style::Fullscreen);
            } else {
                window.create(sf::VideoMode(1280, 720), "SepticaGame", sf::Style::Default);
                }
            }

        window.clear();
        // DEBUG_LOG("[RENDER]\n");
        if (currentState)
            currentState->render(window);
        // DEBUG_LOG("[RENDER DONE]\n");
        window.display();

    }

    return 0;
}
