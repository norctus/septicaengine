#include "septica.hpp"
#include <cstdlib>
#include <algorithm>
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <UIEngine.hpp>

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

    UIButton mainMenuButton(sf::Text("Main Menu", font, 60), sf::Color::Blue, {640.f, 100.f}, bool(false));
    UIButton playButton(sf::Text("Play", font, 40), sf::Color::White, {800.f, 300.f});
    UIButton optionsButton(sf::Text("Options", font, 40), sf::Color::White, {800.f, 500.f});
    UIButton exitButton(sf::Text("Exit", font, 40), sf::Color::White, {800.f, 700.f});

    UIPush(mainMenuButton);
    UIPush(playButton);
    UIPush(optionsButton);
    UIPush(exitButton);

#ifdef MY_DEBUG
    std::cout << playButton.getTextObject().getGlobalBounds().height << " "
                                << playButton.getTextObject().getGlobalBounds().width << " "
                                << playButton.getTextObject().getGlobalBounds().top << " " 
                                << playButton.getTextObject().getGlobalBounds().left << '\n';
#endif

    while(window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        auto mousePosition = sf::Vector2f(sf::Mouse::getPosition(window));
        std::cout << mousePosition.x << " " << mousePosition.y << "\n"; 

        for(auto& button : UIButtons) {
            if(button.isInteractible()) {
                    if(button.getTextObject().getGlobalBounds().contains(mousePosition)) {
                        button.getTextObject().setFillColor(sf::Color::Cyan);

                        if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                            button.getTextObject().setFillColor(sf::Color::Yellow);
                        }
                    }
                    else {
                        button.getTextObject().setFillColor(sf::Color::White);
                    }
                }
            }

        window.clear(sf::Color::Black);
        for(UIButton& button : UIButtons) {
            window.draw(button.getTextObject());
            std::cout << button.isInteractible();
        }
        window.display();
    }

    return 0;
}
