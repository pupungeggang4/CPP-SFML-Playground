#include "script/general.hpp"
#include "script/decl.hpp"

int main() {
    shared_ptr<Game> game = make_shared<Game>();
    game->run(game);
    return 0;
}