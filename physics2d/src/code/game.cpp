#include "res.hpp"
#include "field.hpp"
#include "scenemain.hpp"
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
    //window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
    UIView = sf::View({640, 360}, {1280, 720});
    window.setView(UIView);

    Res::loadImage();
    field = make_shared<Field>();
}

void Game::run(shared_ptr<Game> game) {
    framePrevious = clock.getElapsedTime().asSeconds();
    loop(game);
}

void Game::loop(shared_ptr<Game> game) {
    while (window.isOpen()) {
        frameCurrent = clock.getElapsedTime().asSeconds();
        delta = frameCurrent - framePrevious;
        framePrevious = clock.getElapsedTime().asSeconds();
        handleInput(game);
        handleScene(game);
        window.display();
    }
}

void Game::handleScene(shared_ptr<Game> game) {
    if (scene == "main") {
        SceneMain::loop(game);
    }
}

void Game::handleInput(shared_ptr<Game> game) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        if (const auto *key = event->getIf<sf::Event::KeyPressed>()) {
            int k = int(key->scancode);
            if (k == K_LEFT) {
                keyPressed["left"] = true;
            }
            if (k == K_RIGHT) {
                keyPressed["right"] = true;
            }
            if (k == K_UP) {
                keyPressed["up"] = true;
            }
            if (k == K_DOWN) {
                keyPressed["down"] = true;
            }
        }

        if (const auto *key = event->getIf<sf::Event::KeyReleased>()) {
            int k = int(key->scancode);
            if (k == K_LEFT) {
                keyPressed["left"] = false;
            }
            if (k == K_RIGHT) {
                keyPressed["right"] = false;
            }
            if (k == K_UP) {
                keyPressed["up"] = false;
            }
            if (k == K_DOWN) {
                keyPressed["down"] = false;
            }
        }
    }
}