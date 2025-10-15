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

    Res::loadFont();
    rText.setFont(Res::neodgm);
    tex.insert(std::make_pair("arrow", sf::Texture("image/arrow.png")));
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

        if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>()) {
            int key = int(keyPressed->scancode);
            
            if (scene == "title") {
                SceneTitle::keyDown(game, key);
            } else if (scene == "field") {
                SceneField::keyDown(game, key);
            }
        }

        if (const auto *keyReleased = event->getIf<sf::Event::KeyReleased>()) {
            int key = int(keyReleased->scancode);

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
    if (game->scene == "title") {
        SceneTitle::loop(game);
    } else if (game->scene == "field") {
        SceneField::loop(game);
    }
}
