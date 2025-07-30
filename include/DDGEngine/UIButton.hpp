#pragma once
#include "UIElement.hpp"

class UIButton : public UIElement {
    public:
        UIButton(sf::Text _text, sf::Color color, sf::Vector2f vector, bool interactible = true) : text(std::move(_text)), interactible(interactible) {
            text.setFillColor(color);
            text.setPosition(vector);
        }

        const sf::Text& getTextObject() const { return text; }

        bool isInteractible() { return interactible; }

        void update(sf::Time dt, const sf::RenderWindow& window) override;
        void update(const sf::Vector2f& mousePos, bool mousePressed);

        void handleEvent(const sf::Event& event, sf::RenderWindow& window) override;
        bool handleEvent(const sf::Event& event, const sf::Vector2f& mousePos);

        void render(sf::RenderWindow& window) override;

        void setOnClick(std::function<void()> callback) { onClick = std::move(callback); }

    private:
        sf::Text text;
        bool interactible;
        bool pressedInside;
        std::function<void()> onClick;
};