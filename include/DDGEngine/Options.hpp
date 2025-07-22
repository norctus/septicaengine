#pragma once
#include "GameState.hpp"

class Options : public GameState {
    public:
        Options(std::shared_ptr<GameContext> cont);
        void handleEvent(sf::Event& event, sf::RenderWindow& window) override;
        void update(sf::Time dt, const sf::RenderWindow& window) override;
        void render(sf::RenderWindow& window) override;
        std::vector<UIButton>& getButtons() { return buttons; }

    private:
        std::shared_ptr<GameContext> context;
        std::vector<UIButton> buttons;
        std::optional<size_t> clickedButtonIndex;
};