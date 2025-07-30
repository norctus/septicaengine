#pragma once
#include "MainMenu.hpp"
#include "Options.hpp"

Options::Options(std::shared_ptr<GameContext> cont) : context(cont) {
    UIButton fullscreen(sf::Text("Fullscreen!", *context->font, 60), sf::Color::Blue, {640.f, 100.f});
    DEBUG_LOG("BEFORE SET FOR FULLSCREEN\n");
    fullscreen.setOnClick([cont = context]() {
        DEBUG_LOG("Fullscreen toggle requested!\n");
        cont->toggleFullscreen = true;
    });
    DEBUG_LOG("Before emplaceback\n");
    buttons.emplace_back(fullscreen);
    DEBUG_LOG("After emplacebakc\n");

    UIButton exitButton(sf::Text("Exit", *context->font, 60), sf::Color::Blue, {640.f, 800.f});
    exitButton.setOnClick([cont = context]() {
        switchState<MainMenu>(cont);
    });
    buttons.emplace_back(exitButton);
}
    

void Options::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

    for (auto& button : buttons) {
        button.handleEvent(event, mousePos);
    }
}

void Options::update(sf::Time dt, const sf::RenderWindow& window){
    DEBUG_LOG("[OPTIONS UPDATE START]\n");
    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    bool mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    for (auto& button : buttons) {
        button.update(mousePosition, mousePressed);
    }
    DEBUG_LOG("[OPTIONS UPDATE END]\n");
}

void Options::render(sf::RenderWindow& window) {
    DEBUG_LOG("[OPTIONS RENDER START]\n");
    for (UIButton& button : buttons) {
        window.draw(button.getTextObject());
    }
    DEBUG_LOG("[OPTIONS RENDER END]\n");
}




