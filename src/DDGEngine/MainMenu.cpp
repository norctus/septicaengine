#pragma once
#include "MainMenu.hpp"
#include "Options.hpp"
#include <optional>    

MainMenu::MainMenu(GameContext cont) : context(cont) {
    UIButton mainMenuButton(sf::Text("Main Menu", *context.font, 60), sf::Color::Blue, {640.f, 100.f}, false);
    UIButton playButton(sf::Text("Play", *context.font, 40), sf::Color::White, {800.f, 300.f});
    UIButton optionsButton(sf::Text("Options", *context.font, 40), sf::Color::White, {800.f, 500.f});
    UIButton exitButton(sf::Text("Exit", *context.font, 40), sf::Color::White, {800.f, 700.f});
    buttons.emplace_back(mainMenuButton);
    buttons.emplace_back(playButton);
    buttons.emplace_back(optionsButton);
    buttons.emplace_back(exitButton);
}

void MainMenu::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
        for (size_t i = 0; i < buttons.size(); ++i) {
            if (!buttons[i].isInteractible()) continue;

            if (buttons[i].getTextObject().getGlobalBounds().contains(mousePos)) {
                clickedButtonIndex = i;
                buttons[i].getTextObject().setFillColor(sf::Color::Yellow);
                break;
            }
        }
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));
        if (clickedButtonIndex.has_value()) {
            size_t i = clickedButtonIndex.value();
            
            if (buttons[i].getTextObject().getGlobalBounds().contains(mousePos)) {
                std::cout <<"STATE CHANGE!";
                currentState = std::make_unique<Options>(context);
            }

            clickedButtonIndex.reset();
        }
    }
}

void MainMenu::update(sf::Time dt, const sf::RenderWindow& window) {
    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

    for (size_t i = 0; i < buttons.size(); ++i) {
        auto& button = buttons[i];
        if (!button.isInteractible()) continue;

        sf::FloatRect bounds = button.getTextObject().getGlobalBounds();

        if (bounds.contains(mousePosition)) {
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                button.getTextObject().setFillColor(sf::Color::Yellow);
            } else {
                button.getTextObject().setFillColor(sf::Color::Cyan);
            }
        } else {
            button.getTextObject().setFillColor(sf::Color::White);
        }
    }
}

void MainMenu::render(sf::RenderWindow& window) {
    for(UIButton& button : buttons) {
        window.draw(button.getTextObject());
    }
}

std::vector<UIButton>& MainMenu::getButtons() {
    return buttons;
}

