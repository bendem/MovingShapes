#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <SFML/Graphics.hpp>

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

#include "Renderer.hpp"
#include "EventManager.hpp"
#include "utils/Random.hpp"

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
    Random random;

    sf::Text* theScore;
    sf::Text* theFrames;
    sf::RectangleShape* theSquare;
    sf::RectangleShape* theTarget;

    unsigned long frameLived;
    unsigned long score;

    void setup();

    friend class Renderer;
    friend class EventManager;

};

#endif
