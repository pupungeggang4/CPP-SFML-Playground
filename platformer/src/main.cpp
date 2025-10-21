#include "code/general.hpp"
#include "code/decl.hpp"

int main() {
    shared_ptr<Game> game = make_shared<Game>();
    game->init(game);
    game->run(game);
    return 0;
}
