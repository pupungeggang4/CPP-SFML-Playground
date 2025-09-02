#include "game.hpp"

Game::Game() {
    window = sf::RenderWindow(sf::VideoMode({1920u, 1080u}), "CMake SFML Project");
    window.setFramerateLimit(60);
    tex.insert(std::make_pair("test", sf::Texture("image/test.png")));
    s.setTexture(tex.at("test"));
    s.setTextureRect(sf::IntRect({0, 0}, {80, 80}));
    s.setPosition({20.0f, 20.0f});
    run();
}

void Game::run() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear(sf::Color::Black);
        window.draw(s);
        window.display();
    }
}