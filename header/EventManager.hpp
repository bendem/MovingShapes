#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <SFML/Graphics.hpp>

#include <set>

class Application;

class EventManager {

public:
    EventManager();

    void update(Application&);

private:
    bool isMouseDown;
    std::set<sf::Keyboard::Key> keysDown;
    sf::Vector2f mousePosition;

};

#endif
