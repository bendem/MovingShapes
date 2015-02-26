#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics.hpp>
#include <vector>

class Application;

class Renderer {

public:
    Renderer() {}
    ~Renderer();
    Renderer& registerShape(sf::Drawable*);

    void render(Application&);

private:
    std::vector<sf::Drawable*> shapes;

};

#endif
