#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include <chrono>
#include <thread>

#include "Renderer.hpp"
#include "EventManager.hpp"

class Application {

public:
    Application();
    ~Application();

    void start();

private:

    static const sf::Time FPS;

    sf::RenderWindow window;
    Renderer renderer;
    EventManager eventManager;

    sf::RectangleShape* theSquare;
    sf::RectangleShape* theTarget;

    void setup();

    friend class Renderer;
    friend class EventManager;

};

#endif
