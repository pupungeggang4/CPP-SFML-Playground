#include "game.hpp"

Game::Game() {
    sf::err().rdbuf(NULL);
    window = sf::RenderWindow(sf::VideoMode({1280u, 720u}), "Adventure Game");
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
