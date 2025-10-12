#pragma once
#include "general.hpp"
#include "decl.hpp"

Game::Game() {
    sf::err().rdbuf(NULL);
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    if (videoMode.size.x > 2560) {
        width = 2560; height = 1440;
    } else if (videoMode.size.x > 2000) {
        width = 1920; height = 1080;
    } else {
        width = 1280; height = 720;
    }

    sf::ContextSettings settings;
    settings.antiAliasingLevel = 0;
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Roguelike Game", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    sf::View view({640, 360}, {1280, 720});
    window.setView(view);

    Res::neodgm.setSmooth(false);
    rText.setFillColor(sf::Color::Black);
    rRect.setOutlineThickness(2);
    rRect.setOutlineColor(sf::Color::Black);

    scene = "title";
    state = "";
    menu = false;
}

void Game::run(shared_ptr<Game> game) {
    while (game->window.isOpen()) {
        handleInput(game);
        handleScene(game);
    }
}

void Game::handleScene(shared_ptr<Game> game) {
    if (game->scene == "title") {
        SceneTitle::loop(game);
    }
}

void Game::handleInput(shared_ptr<Game> game) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
    }
}
