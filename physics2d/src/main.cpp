#include "code/general.hpp"
#include "code/game.hpp"

int main()
{
    shared_ptr<Game> game = make_shared<Game>();
    game->run();
}
