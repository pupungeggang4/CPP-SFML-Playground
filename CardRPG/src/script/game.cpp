#include "general.hpp"
#include "decl.hpp"

Game::Game() {
    sf::err().rdbuf(NULL);
    unsigned int width, height;
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    if (videoMode.size.x > 2000) {
        width = 1920; height = 1080;
    } else {
        width = 1280; height = 720;
    }

    window = sf::RenderWindow(sf::VideoMode({width, height}), "Adventure Game");
    window.setFramerateLimit(60);
    sf::View view({640, 360}, {1280, 720});
    window.setView(view);

    tex.insert(std::make_pair("test", sf::Texture("image/test.png")));
    s.setTexture(tex.at("test"));
    s.setTextureRect(sf::IntRect({0, 0}, {80, 80}));
    s.setPosition({200.0f, 200.0f});
}

void Game::run(shared_ptr<Game> game) {
    while (game->window.isOpen()) {
        while (const std::optional event = game->window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                game->window.close();
            }
        }
        loop(game);
    }
}

void Game::loop(shared_ptr<Game> game) {
    loopTitle(game);
}