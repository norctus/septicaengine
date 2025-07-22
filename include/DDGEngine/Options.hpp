#pragma once
#include "GameState.hpp"

class Options : public GameState {
    public:
        Options(GameContext font);
        void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
        void update(sf::Time dt, const sf::RenderWindow& window) override;
        void render(sf::RenderWindow& window) override;
        std::vector<UIButton>& getButtons() override;

    private:
        GameContext context;
        std::vector<UIButton> buttons;
        std::optional<size_t> clickedButtonIndex;
};