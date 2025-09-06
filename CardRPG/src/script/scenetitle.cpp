#include "scenetitle.hpp"

template <typename Game>
void render(Game *game) {
    game->window.clear();
    game->window.display();
}