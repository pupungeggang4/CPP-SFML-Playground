#include "game.hpp"

Game::Game() {
    window = make_shared<sf::RenderWindow>(sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project"));
    window->setFramerateLimit(60);
    run();
}

void Game::run() {
    while (window->isOpen()) {
        while (const std::optional event = window->pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window->close();
            }
        }
        window->clear(sf::Color::Blue);
        window->display();
    }
}