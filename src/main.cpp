#include "septica.hpp"
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <algorithm>

int main() {
    srand(time(0));

    auto pachet = std::make_shared<Pachet>(Pachet::generarePachet());
    pachet->amestecarePachet();
    
    std::vector<std::shared_ptr<Jucator>> jucatori = {
        std::make_shared<Jucator>("Darius"),
        std::make_shared<Jucator>("Edi"),
        std::make_shared<Jucator>("Ileana"),
        std::make_shared<Jucator>("Robi"),
        std::make_shared<Jucator>("Dori"),
        std::make_shared<Jucator>("Horia")
    };

    Septica septica(pachet, jucatori);
    septica.distribuirePachet();
    
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

    sf::Text text;
    text.setFont(font);
    std::string toShow = septica.printJucatori();
    text.setString(toShow);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(100.f, 100.f);

    while(window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        window.draw(text);
        window.display();
    }

    return 0;
}
