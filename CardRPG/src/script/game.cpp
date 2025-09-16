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

    player = make_shared<Player>();
}

void Game::run(shared_ptr<Game> game) {
    while (game->window.isOpen()) {
        while (const std::optional event = game->window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                game->window.close();
            }

            if (const auto* key = event->getIf<sf::Event::KeyPressed>()) {
                if (key->scancode == sf::Keyboard::Scan::W) {
                    keyPressed["up"] = true;
                }
                if (key->scancode == sf::Keyboard::Scan::A) {
                    keyPressed["left"] = true;
                }
                if (key->scancode == sf::Keyboard::Scan::S) {
                    keyPressed["down"] = true;
                }
                if (key->scancode == sf::Keyboard::Scan::D) {
                    keyPressed["right"] = true;
                }
            }

            if (const auto* key = event->getIf<sf::Event::KeyReleased>()) {
                if (key->scancode == sf::Keyboard::Scan::W) {
                    keyPressed["up"] = false;
                }
                if (key->scancode == sf::Keyboard::Scan::A) {
                    keyPressed["left"] = false;
                }
                if (key->scancode == sf::Keyboard::Scan::S) {
                    keyPressed["down"] = false;
                }
                if (key->scancode == sf::Keyboard::Scan::D) {
                    keyPressed["right"] = false;
                }
            }
        }
        loop(game);
    }
}

void Game::loop(shared_ptr<Game> game) {
    loopTitle(game);
}