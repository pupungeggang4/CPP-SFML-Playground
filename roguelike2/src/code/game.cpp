#pragma once
#include "general.hpp"
#include "decl.hpp"

Game::Game() {
    sf::err().rdbuf(NULL);
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    if (videoMode.size.x > 2000) {
        width = 1920; height = 1080;
    } else {
        width = 1280; height = 720;
    }

    window = sf::RenderWindow(sf::VideoMode({width, height}), "Auto Card Battle");
    window.setFramerateLimit(60);
    window.setVerticalSynnEnabled(true);
    sf::View view({640, 360}, {1280, 720});
    window.setView(view);
}

void Game::run(shared_ptr<Game> game) {
    while (game->window.isOpen()) {
        handleInput(game);
        window.clear();
        window.display();
    }
}

void Game::handleScene(shared_ptr<Game> game) {

}

void Game::handleInput(shared_ptr<Game> game) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}