#include "general.hpp"
#include "decl.hpp"

Game::Game() {
    sf::err().rdbuf(NULL);
    sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
    if (videoMode.size.x > 2000) {
        width = 1920; height = 1080;
    } else {
        width = 1280; height = 720;
    }

    window = sf::RenderWindow(sf::VideoMode({width, height}), "Auto Card Battle");
    window.setFramerateLimit(60);
    sf::View view({640, 360}, {1280, 720});
    window.setView(view);
}

void Game::run(shared_ptr<Game> game) {
    while (game->window.isOpen())
    {
        while (const std::optional event = game->window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                game->window.close();
            }

            if (const auto *mouse = event->getIf<sf::Event::MouseButtonReleased>()) {
                sf::Vector2f mousePos = {mouse->position.x * 1280.0f / width, mouse->position.y * 720.0f / height};
                if (scene == "title") {
                    SceneTitle::mouseUp(game, mousePos);
                } else if (scene == "ready") {
                    SceneReady::mouseUp(game, mousePos);
                } else if (scene == "battle") {
                    SceneBattle::mouseUp(game, mousePos);
                }
            }
        }

        if (scene == "title") {
            SceneTitle::loop(game);
        } else if (scene == "ready") {
            SceneReady::loop(game);
        } else if (scene == "battle") {
            SceneBattle::loop(game);
        }
    }
}
