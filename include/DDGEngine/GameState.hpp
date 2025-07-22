#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include <optional>

class UIButton {
    public:
        UIButton(const sf::Text& _text, sf::Color color, sf::Vector2f vector, bool interactible = true) : text(_text), interactible(interactible) {
            text.setFillColor(color);
            text.setPosition(vector);
        }

        sf::Text& getTextObject() {
            return text;
        }

        bool isInteractible() {
            return interactible;
        }

    private:
        sf::Text text;
        bool interactible;
};

struct GameContext {
    sf::Font* font = nullptr;
};

class GameState {
public:
    virtual ~GameState() = default;
    virtual void handleEvent(sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update(sf::Time dt, const sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual std::vector<UIButton>& getButtons() = 0;
};

extern std::unique_ptr<GameState> currentState;

