#include "code/general.hpp"
#include "code/game.hpp"
#include "code/res.hpp"

int main(int argc, char* argv[]) {
    shared_ptr<Game> game = make_shared<Game>();
    game->init(game);
    game->run(game);
    Res::neodgm.reset();
    Res::img.reset();
    return 0;
}
