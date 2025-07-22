#pragma once
#include "GameState.hpp"

class MainMenu : public GameState {
    public:
        MainMenu(GameContext cont);
        void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
        void update(sf::Time dt, const sf::RenderWindow& window) override;
        void render(sf::RenderWindow& window) override;
        std::vector<UIButton>& getButtons();

    private:
        GameContext context;
        std::vector<UIButton> buttons;
        std::optional<size_t> clickedButtonIndex;
};
