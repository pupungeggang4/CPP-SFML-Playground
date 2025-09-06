#include "scenetitle.hpp"

SceneTitle::SceneTitle() {

}

void SceneTitle::loop(shared_ptr<Game> game) {
    SceneTitle::render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    game->window.display();
}