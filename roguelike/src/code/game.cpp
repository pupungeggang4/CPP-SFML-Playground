#include "game.hpp"

#include "res.hpp"
#include "locale.hpp"
#include "village.hpp"
#include "field.hpp"

#include "scenetitle.hpp"

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
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Roguelike Game", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(60);
    //window.setVerticalSyncEnabled(true);
    sf::View view({640, 360}, {1280, 720});
    window.setView(view);

    Res::loadFont();
    Res::loadImage();
    locale = Locale::data[lang];

    rText = sf::Text(*Res::neodgm, "", 32);
    rText.setFillColor(sf::Color::Black);
    rRect.setOutlineThickness(2);
    rRect.setOutlineColor(sf::Color::Black);

    framePrevious = clock.getElapsedTime().asSeconds();
    frameCurrent = 0;

    scene = make_shared<SceneTitle>();
}

void Game::init(shared_ptr<Game> game) {
    field = make_shared<Field>(game);
    village = make_shared<Village>(game);
}

void Game::run(shared_ptr<Game> game) {
    while (game->window.isOpen()) {
        frameCurrent = clock.getElapsedTime().asSeconds();
        delta = frameCurrent - framePrevious;
        framePrevious = clock.getElapsedTime().asSeconds();
        //std::cout << delta << std::endl;
        handleInput(game);
        handleScene(game);
    }
}

void Game::handleScene(shared_ptr<Game> game) {
    game->scene->loop(game);
}

void Game::handleInput(shared_ptr<Game> game) {
    while (const std::optional event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        if (const auto *keyPress = event->getIf<sf::Event::KeyPressed>()) {
            int key = int(keyPress->scancode);
            if (key == K_LEFT) {
                keyPressed["left"] = true;
            }
            if (key == K_RIGHT) {
                keyPressed["right"] = true;
            }
            if (key == K_UP) {
                keyPressed["up"] = true;
            }
            if (key == K_DOWN) {
                keyPressed["down"] = true;
            }
            game->scene->keyDown(game, key);
        }

        if (const auto *keyRelease = event->getIf<sf::Event::KeyReleased>()) {
            int key = int(keyRelease->scancode);
            if (key == K_LEFT) {
                keyPressed["left"] = false;
            }
            if (key == K_RIGHT) {
                keyPressed["right"] = false;
            }
            if (key == K_UP) {
                keyPressed["up"] = false;
            }
            if (key == K_DOWN) {
                keyPressed["down"] = false;
            }
            game->scene->keyUp(game, key);
        }
    }
}
