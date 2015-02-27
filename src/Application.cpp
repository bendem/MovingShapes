#include "Application.hpp"

const sf::Time Application::FPS = sf::seconds(1.f/60);

Application::Application()
        : window(sf::VideoMode(900, 600), "Square!") {
    this->frameLived = 0;
}

Application::~Application() {
}

void Application::start() {
    this->setup();

    sf::Clock clock;
    while(this->window.isOpen()) {
        this->eventManager.update(*this);
        this->renderer.render(*this);

        this->theFrames->setString(std::to_string(++this->frameLived));

        sf::Int64 remaining = (Application::FPS - clock.restart()).asMicroseconds();
        if(remaining > 0) {
            std::this_thread::sleep_for(std::chrono::microseconds(remaining));
        }
    }
}

void Application::setup() {
    std::cerr << "Application setup start" << std::endl;
    static sf::Font f; // Keeps the font alive
    if(!f.loadFromFile("/usr/share/fonts/dejavu/DejaVuSansMono-Bold.ttf")) {
        throw std::runtime_error("Could not load font");
    }

    this->theFrames = new sf::Text("0", f);
    this->theFrames->setCharacterSize(25);
    this->theFrames->setColor(sf::Color(255, 255, 255, 200));
    this->theFrames->setStyle(sf::Text::Bold);
    this->theFrames->setPosition(5, 5);

    this->theScore = new sf::Text("0", f);
    this->theScore->setCharacterSize(25);
    this->theScore->setColor(sf::Color(255, 255, 255, 200));
    this->theScore->setPosition(5, this->window.getSize().y - 35);

    this->theSquare = new sf::RectangleShape(sf::Vector2f(200.f, 200.f));
    this->theSquare->setFillColor(sf::Color(120, 120, 120));
    this->theSquare->setOutlineColor(sf::Color(50, 50, 50));
    this->theSquare->setOutlineThickness(-5);

    this->theTarget = new sf::RectangleShape(sf::Vector2f(200.f, 200.f));
    this->theTarget->setFillColor(sf::Color(0, 0, 0, 0));
    this->theTarget->setOutlineColor(sf::Color(250, 50, 50));
    this->theTarget->setOutlineThickness(-5);

    this->theTarget->setPosition(
        this->random.nextUnsigned(this->window.getSize().x - this->theTarget->getSize().x),
        this->random.nextUnsigned(this->window.getSize().y - this->theTarget->getSize().y)
    );

    this->renderer
        .setBackground(sf::Color(20, 20, 20))
        .registerShape(this->theTarget)
        .registerShape(this->theSquare)
        .registerShape(this->theFrames)
        .registerShape(this->theScore)
        ;
    std::cerr << "Application setup end" << std::endl;
}
