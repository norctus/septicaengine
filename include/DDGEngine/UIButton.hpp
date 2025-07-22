#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include <optional>
#include <functional>

#pragma once

#ifdef MY_DEBUG
    #define DEBUG_LOG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
    #define DEBUG_LOG(x) ((void)0)
#endif

class UIButton {
    public:
        UIButton(sf::Text _text, sf::Color color, sf::Vector2f vector, bool interactible = true) : text(std::move(_text)), interactible(interactible) {
            text.setFillColor(color);
            text.setPosition(vector);
        }

        const sf::Text& getTextObject() const { return text; }

        bool isInteractible() { return interactible; }

        void setOnClick(std::function<void()> callback) { onClick = std::move(callback); }

        void update(const sf::Vector2f& mousePos, bool mousePressed);
        bool handleEvent(const sf::Event& event, const sf::Vector2f& mousePos);

    private:
        sf::Text text;
        bool interactible;
        bool pressedInside;
        std::function<void()> onClick;
};