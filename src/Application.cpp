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
    this->theSquare->setFillColor(sf::Color(255, 150, 150));
    this->renderer.registerShape(this->theSquare);
}
