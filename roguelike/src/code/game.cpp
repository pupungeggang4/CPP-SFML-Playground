#include "general.hpp"
#include "decl.hpp"

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

    loadFont();
    loadImage();
    locale = Locale::data[lang];

    rText = sf::Text(neodgm, "", 32);
    rText.setFillColor(sf::Color::Black);
    rRect.setOutlineThickness(2);
    rRect.setOutlineColor(sf::Color::Black);

    framePrevious = clock.getElapsedTime().asSeconds();
    frameCurrent = 0;
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
    if (game->scene == "title") {
        SceneTitle::loop(game);
    } else if (game->scene == "village") {
        SceneVillage::loop(game);
    } else if (game->scene == "battle") {
        SceneBattle::loop(game);
    }
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
            if (game->scene == "title") {
                SceneTitle::keyDown(game, key);
            } else if (game->scene == "village") {
                SceneVillage::keyDown(game, key);
            } else if (game->scene == "battle") {
                SceneBattle::keyDown(game, key);
            }
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
            if (game->scene == "title") {
                SceneTitle::keyUp(game, key);
            } else if (game->scene == "village") {
                SceneVillage::keyUp(game, key);
            } else if (game->scene == "battle") {
                SceneBattle::keyUp(game, key);
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
    tex.emplace("player", sf::Texture("image/player.png"));
    tex.emplace("portal", sf::Texture("image/portal.png"));
    tex.emplace("arrow_down", sf::Texture("image/arrowdown.png"));
    tex.emplace("exporb", sf::Texture("image/exporb.png"));
    tex.emplace("coin", sf::Texture("image/coin.png"));
    tex.emplace("life", sf::Texture("image/life.png"));
    tex.emplace("energy", sf::Texture("image/energy.png"));
}
