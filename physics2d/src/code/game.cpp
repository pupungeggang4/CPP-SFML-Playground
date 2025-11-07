#include "game.hpp"

Game::Game() {
    std::srand(std::time(0));
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
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Platformer 2D Test", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(60);
    //window.setVerticalSyncEnabled(true);
    sf::View view({640, 360}, {1280, 720});
    window.setView(view);
}

void Game::run() {
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}