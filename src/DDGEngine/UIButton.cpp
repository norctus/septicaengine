#include "UIButton.hpp"
#include "GameState.hpp"

void UIButton::update(sf::Time, const sf::RenderWindow& window) {
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    bool mousePressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    update(mousePos, mousePressed);
}

void UIButton::update(const sf::Vector2f& mousePos, bool mousePressed) {
    if (!interactible) return;

    if (text.getGlobalBounds().contains(mousePos)) {
        if (mousePressed && pressedInside)
            text.setFillColor(sf::Color::Yellow);
        else
            text.setFillColor(sf::Color::Cyan);
    } else {
        text.setFillColor(sf::Color::White);
    }
}

void UIButton::handleEvent(const sf::Event& event, sf::RenderWindow& window) {
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    handleEvent(event, mousePos);
}

bool UIButton::handleEvent(const sf::Event& event, const sf::Vector2f& mousePos) {
    if (!interactible || !onClick) return false;

    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        if (text.getGlobalBounds().contains(mousePos)) {
            pressedInside = true;
        } else {
            pressedInside = false;
        }
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        if (text.getGlobalBounds().contains(mousePos) && pressedInside) {
            onClick();
            return true;
        }
        pressedInside = false;
    }

    return false;
}

void UIButton::render(sf::RenderWindow& window) {
    window.draw(text);
}