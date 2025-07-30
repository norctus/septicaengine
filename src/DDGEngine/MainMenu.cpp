#include "MainMenu.hpp"
#include "Options.hpp"
#include <optional>

MainMenu::MainMenu(std::shared_ptr<GameContext> cont) : context(cont) {
    UIButton mainMenuButton(sf::Text("Main Menu", *context->font, 60), sf::Color::Blue, {640.f, 100.f}, false);
    UIButton playButton(sf::Text("Play", *context->font, 40), sf::Color::White, {800.f, 300.f});
    playButton.setOnClick([]() {
        DEBUG_LOG("Play Button Clicked!\n");
    });

    UIButton optionsButton(sf::Text("Options", *context->font, 40), sf::Color::White, {800.f, 500.f});
    optionsButton.setOnClick([ctx = context]() {
        DEBUG_LOG("[OPTIONS CLICK] Scheduling state change...\n");
        switchState<Options>(ctx);
    });

    UIButton exitButton(sf::Text("Exit", *context->font, 40), sf::Color::White, {800.f, 700.f});
        exitButton.setOnClick([]() {
        DEBUG_LOG("Exit clicked\n");
        std::exit(0);
    });

    buttons.emplace_back(mainMenuButton);
    buttons.emplace_back(playButton);
    buttons.emplace_back(optionsButton);
    buttons.emplace_back(exitButton);
}

void MainMenu::handleEvent(sf::Event& event, sf::RenderWindow& window) {
    sf::Vector2f mousePos(static_cast<float>(event.mouseButton.x), static_cast<float>(event.mouseButton.y));

    for (auto& button : buttons) {
        button.handleEvent(event, mousePos);
    }
}

void MainMenu::update(sf::Time dt, const sf::RenderWindow& window) {
    sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    bool mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    for (auto& button : buttons) {
        button.update(mousePosition, mousePressed);
    }
}

void MainMenu::render(sf::RenderWindow& window) {
    for(UIButton& button : buttons) {
        window.draw(button.getTextObject());
    }
}