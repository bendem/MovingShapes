#include "EventManager.hpp"
#include "Application.hpp"

EventManager::EventManager()
        : isMouseDown(false) {
}

void EventManager::update(Application& application) {
    sf::Event event;
    while (application.window.pollEvent(event)) {
        switch(event.type) {
            case sf::Event::Closed:
                application.window.close();
                break;
            case sf::Event::MouseButtonPressed:
                this->isMouseDown = true;
                break;
            case sf::Event::MouseButtonReleased:
                this->isMouseDown = false;
            case sf::Event::MouseMoved:
                if(this->isMouseDown) {
                    sf::Vector2f pos(application.theSquare->getPosition());
                    application.theSquare->move(event.mouseMove.x - this->mousePosition.x, event.mouseMove.y - this->mousePosition.y);
                }
                this->mousePosition.x = event.mouseMove.x;
                this->mousePosition.y = event.mouseMove.y;
        }
    }
}
