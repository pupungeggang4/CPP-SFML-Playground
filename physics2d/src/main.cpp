#include "code/game.hpp"
#include "code/res.hpp"

int main() {
    shared_ptr<Game> game = make_shared<Game>();
    game->run(game);
    Res::texture.reset();
    Res::neodgm.reset();
}
