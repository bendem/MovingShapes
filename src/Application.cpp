#include "Application.hpp"

const sf::Time Application::FPS = sf::seconds(1.f/60);

Application::Application()
        : window(sf::VideoMode(900, 600), "Square!"){
}

Application::~Application() {
}

void Application::start() {
    this->setup();

    sf::Clock clock;
    while(this->window.isOpen()) {
        this->eventManager.update(*this);
        this->renderer.render(*this);

        sf::Int64 remaining = (Application::FPS - clock.restart()).asMicroseconds();
        if(remaining > 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(remaining));
        }
    }
}

void Application::setup() {

    this->theSquare = new sf::RectangleShape(sf::Vector2f(200.f, 200.f));
    this->theSquare->setFillColor(sf::Color(120, 120, 120));
    this->theSquare->setOutlineColor(sf::Color(50, 50, 50));
    this->theSquare->setOutlineThickness(-5);

    this->theTarget = new sf::RectangleShape(sf::Vector2f(200.f, 200.f));
    this->theTarget->setFillColor(sf::Color(0, 0, 0, 0));
    this->theTarget->setOutlineColor(sf::Color(250, 50, 50));
    this->theTarget->setOutlineThickness(-5);

    this->renderer
        .setBackground(sf::Color(20, 20, 20))
        .registerShape(this->theTarget)
        .registerShape(this->theSquare);
}
