#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include <optional>
#include <functional>

#ifdef MY_DEBUG
    #define DEBUG_LOG(x) std::cout << "[DEBUG] " << x << std::endl;
#else
    #define DEBUG_LOG(x) ((void)0)
#endif


class UIElement {
public:
    virtual ~UIElement() = default;
    virtual void handleEvent(const sf::Event& event, sf::RenderWindow& window) = 0;
    virtual void update(sf::Time dt, const sf::RenderWindow& window) = 0;
    virtual void render(sf::RenderWindow& window) = 0;
};