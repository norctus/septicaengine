#include "septica.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <algorithm>

int main() {
    srand(time(0));

    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "Septica Game");
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

    sf::Text mainMenu;
    mainMenu.setFont(font);
    mainMenu.setString("Main Menu");
    mainMenu.setCharacterSize(60);
    mainMenu.setFillColor(sf::Color::Blue);
    mainMenu.setPosition(640.f, 100.f);

    sf::Text playButton;
    playButton.setFont(font);
    playButton.setString("Play");
    playButton.setCharacterSize(40);
    playButton.setFillColor(sf::Color::White);
    playButton.setPosition(800.f, 300.f);

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        auto mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));

        if(playButton.getGlobalBounds().contains(mousePosition)) {
            playButton.setFillColor(sf::Color::Cyan);

            if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                playButton.setFillColor(sf::Color::Yellow);
            }
        }
        else {
            playButton.setFillColor(sf::Color::White);
        }

        window.clear(sf::Color::Black);
        window.draw(mainMenu);
        window.draw(playButton);
        window.display();
    }

    return 0;
}
