#include "Renderer.hpp"
#include "Application.hpp"

Renderer::~Renderer() {
    for(sf::Drawable* shape : this->shapes) {
        delete shape;
    }
    this->shapes.clear();
}

Renderer& Renderer::setBackground(const sf::Color& color) {
    this->bgColor = color;
    return *this;
}

Renderer& Renderer::registerShape(sf::Drawable* shape) {
    this->shapes.push_back(shape);
    return *this;
}

void Renderer::render(Application& application) {
    application.window.clear(this->bgColor);
    for(sf::Drawable* shape : this->shapes) {
        application.window.draw(*shape);
    }
    application.window.display();
}
