#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

#include "Application.hpp"

class Renderer {

public:
    ~Renderer();
    Renderer& registerShape(sf::Drawable*);

    void render(Application& application1);

private:
    Application& application;
    std::vector<sf::Drawable*> shapes;

};

#endif
