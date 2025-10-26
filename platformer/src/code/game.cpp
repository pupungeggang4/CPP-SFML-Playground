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

    window = sf::RenderWindow(sf::VideoMode({width, height}), "Auto Card Battle");
    window.setFramerateLimit(60);
    sf::View view({640, 360}, {1280, 720});
    window.setView(view);

    loadImage();
}

void Game::init(shared_ptr<Game> game) {
    field = make_shared<Field>();
    frameCurrent = 0;
    framePrevious = clock.getElapsedTime().asSeconds();
    delta = 0.016;
    locale = Locale::data[lang];
}

void Game::loadImage() {
    Res::tex.insert(std::make_pair("arrow", sf::Texture("image/arrow.png")));
    Res::tex.insert(std::make_pair("player", sf::Texture("image/player.png")));
    Res::tex.insert(std::make_pair("coin", sf::Texture("image/sprite/spritecoin.png")));
    tex.insert(std::make_pair("arrow", sf::Texture("image/arrow.png")));
    tex.insert(std::make_pair("player", sf::Texture("image/player.png")));
    tex.insert(std::make_pair("coin", sf::Texture("image/sprite/spritecoin.png")));
}

void Game::run(shared_ptr<Game> game) {
    while (game->window.isOpen()) {
        game->handleInput(game);
        game->handleScene(game);
    }
}

void Game::handleInput(shared_ptr<Game> game) {
    while (const std::optional event = game->window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            game->window.close();
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
            
            if (scene == "title") {
                SceneTitle::keyDown(game, key);
            } else if (scene == "field") {
                SceneField::keyDown(game, key);
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

            if (scene == "title") {
                SceneTitle::keyUp(game, key);
            } else if (scene == "field") {
                SceneField::keyUp(game, key);
            }
        }

        if (const auto *mouseReleased = event->getIf<sf::Event::MouseButtonReleased>()) {
            sf::Vector2i pos = {int(mouseReleased->position.x * 1280 / width), int(mouseReleased->position.y * 720 / height)};
            std::cout << pos.x << "," << pos.y << std::endl;
        }
    }
}

void Game::handleScene(shared_ptr<Game> game) {
    frameCurrent = clock.getElapsedTime().asSeconds();
    delta = frameCurrent - framePrevious;
    framePrevious = clock.getElapsedTime().asSeconds();

    if (game->scene == "title") {
        SceneTitle::loop(game);
    } else if (game->scene == "field") {
        SceneField::loop(game);
    }
}
