#pragma once
#include "UIButton.hpp"

struct GameContext {
    sf::Font* font = nullptr;
    sf::RenderWindow* window = nullptr;
    bool isFullscreen = false;
    bool toggleFullscreen = false;
    std::function<void()> pendingStateChange;
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

template <typename T>
void switchState(std::shared_ptr<GameContext> ctx) {
    ctx->pendingStateChange = [ctx]() {
        DEBUG_LOG("[STATE TRANSITION STARTED]");
        currentState = std::make_unique<T>(ctx);
        DEBUG_LOG("[STATE TRANSITION COMPLETE]");
    };
}