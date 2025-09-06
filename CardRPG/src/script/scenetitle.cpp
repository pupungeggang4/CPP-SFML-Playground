#include "scenetitle.hpp"

template <typename Game>
void SceneTitle::render(Game game) {
    game->window.clear();
    game->window.display();
}