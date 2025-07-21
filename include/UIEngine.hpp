#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>

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

inline std::vector<UIButton> UIButtons;

#define UIPush(X) (UIButtons.push_back(X))

