#include "Application.hpp"

Application::Application()
        : window(sf::VideoMode(900, 600), "Square!"){
}

Application::~Application() {
}

void Application::start() {
    this->setup();

    while(this->window.isOpen()) {
        sf::Time start = sf::Time::Zero;
        this->eventManager.update(*this);
        this->renderer.render(*this);
        // TODO Wait?
    }
}

void Application::setup() {
    this->theSquare = new sf::RectangleShape(sf::Vector2f(200.f, 200.f));
    this->theSquare->setFillColor(sf::Color(255, 150, 150));
    this->renderer.registerShape(this->theSquare);
}
