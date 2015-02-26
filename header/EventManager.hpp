#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <SFML/Graphics.hpp>

class Application;

class EventManager {

public:
    EventManager();

    void update(Application&);

private:
    bool isMouseDown;
    sf::Vector2f mousePosition;

};

#endif
