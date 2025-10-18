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

    loadFont();
    loadImage();
    locale = Locale::data[lang];

    rText = sf::Text(neodgm, "", 32);
    rText.setFillColor(sf::Color::Black);
    rRect.setOutlineThickness(2);
    rRect.setOutlineColor(sf::Color::Black);
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
    } else if (game->scene == "village") {
        SceneVillage::loop(game);
    }
}

void Game::handleInput(shared_ptr<Game> game) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        if (const auto *keyPress = event->getIf<sf::Event::KeyPressed>()) {
            int key = int(keyPress->scancode);
            if (game->scene == "title") {
                SceneTitle::keyDown(game, key);
            } else if (game->scene == "village") {
                SceneVillage::keyDown(game, key);
            }
        }

        if (const auto *keyRelease = event->getIf<sf::Event::KeyReleased>()) {
            int key = int(keyRelease->scancode);
            if (game->scene == "title") {
                SceneTitle::keyUp(game, key);
            } else if (game->scene == "village") {
                SceneVillage::keyUp(game, key);
            }
        }
    }
}

void Game::loadFont() {
    neodgm = sf::Font("font/neodgm.ttf");
    neodgm.setSmooth(false);
}

void Game::loadImage() {
    tex.emplace("arrow", sf::Texture("image/arrow.png"));
}
