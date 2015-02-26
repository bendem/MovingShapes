#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <SFML/Graphics.hpp>

#include "Application.hpp"

class EventManager {

public:
    EventManager();

    void update(Application& application);

private:
    bool isMouseDown;

};

#endif
