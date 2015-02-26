#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

class Application;

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

    void setup();

    friend class Renderer;
    friend class EventManager;

};

const sf::Time FPS = sf::Time::seconds(1.f/60);

#endif