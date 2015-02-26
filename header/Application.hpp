#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include "Renderer.hpp"
#include "EventManager.hpp"

class Application {

public:
    Application();
    ~Application();
    void start();

private:

    sf::RenderWindow window;
    Renderer renderer;
    EventManager eventManager;

    sf::RectangleShape* theSquare;

    void setup();

    friend class Renderer;
    friend class EventManager;

};

#endif
