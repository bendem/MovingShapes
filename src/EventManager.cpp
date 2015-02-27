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
                if(application.theSquare->getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    this->isMouseDown = true;
                }
                break;

            case sf::Event::MouseButtonReleased:
                if(this->isMouseDown) {
                    // Prevents from dropping the square out of the window
                    sf::Vector2f newPosition = application.theSquare->getPosition();
                    if(newPosition.x < 0) {
                        newPosition.x = 0;
                    } else if(newPosition.x + application.theSquare->getSize().x > application.window.getSize().x) {
                        newPosition.x = application.window.getSize().x - application.theSquare->getSize().x;
                    }
                    if(newPosition.y < 0) {
                        newPosition.y = 0;
                    } else if(newPosition.y + application.theSquare->getSize().y > application.window.getSize().y) {
                        newPosition.y = application.window.getSize().y - application.theSquare->getSize().y;
                    }
                    application.theSquare->setPosition(newPosition);
                }
                this->isMouseDown = false;
                break;

            case sf::Event::MouseMoved:
                if(this->isMouseDown) {
                    application.theSquare->move(
                        event.mouseMove.x - this->mousePosition.x,
                        event.mouseMove.y - this->mousePosition.y
                    );
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

        if(application.theSquare->getPosition() == application.theTarget->getPosition()) {
            application.theScore->setString(std::to_string(++application.score));
            application.theTarget->setPosition(
                application.random.nextUnsigned(application.window.getSize().x - application.theTarget->getSize().x),
                application.random.nextUnsigned(application.window.getSize().y - application.theTarget->getSize().y)
            );
        }
    }
}
