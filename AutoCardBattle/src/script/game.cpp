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
        }

        game->window.clear(sf::Color::White);
        rTmpRect.setOutlineColor(sf::Color::Black);
        rTmpRect.setOutlineThickness(2.0f);
        rTmpText.setCharacterSize(32);
        rTmpText.setFillColor(sf::Color::Black);
        Render::fillTextUI(game->window, rTmpText, "Auto Card Battle", UITitle["text_title"]);
        Render::strokeRectUI(game->window, rTmpRect, UITitle["button_start"]);
        Render::fillTextUI(game->window, rTmpText, "Start Game", UITitle["text_start"]);
        Render::strokeRectUI(game->window, rTmpRect, UITitle["button_collection"]);
        Render::fillTextUI(game->window, rTmpText, "Collection", UITitle["text_collection"]);
        game->window.display();
    }
}