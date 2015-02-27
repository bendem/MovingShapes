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

            case sf::Event::KeyPressed:
                this->keysDown.insert(event.key.code);
                break;

            case sf::Event::KeyReleased:
                this->keysDown.erase(event.key.code);
                break;

            case sf::Event::MouseButtonPressed:
                this->isMouseDown = true;
                break;

            case sf::Event::MouseButtonReleased:
                this->isMouseDown = false;
                break;

            case sf::Event::MouseMoved:
                if(this->isMouseDown) {
                    application.theSquare->move(event.mouseMove.x - this->mousePosition.x, event.mouseMove.y - this->mousePosition.y);
                }
                this->mousePosition.x = event.mouseMove.x;
                this->mousePosition.y = event.mouseMove.y;
                break;

            case sf::Event::Resized:
            case sf::Event::LostFocus:
            case sf::Event::GainedFocus:
            case sf::Event::TextEntered:
            case sf::Event::MouseWheelMoved:
            case sf::Event::MouseEntered:
            case sf::Event::MouseLeft:
            case sf::Event::JoystickButtonPressed:
            case sf::Event::JoystickButtonReleased:
            case sf::Event::JoystickMoved:
            case sf::Event::JoystickConnected:
            case sf::Event::JoystickDisconnected:
            case sf::Event::Count:
                // NOP
                break;
        }
    }
}
