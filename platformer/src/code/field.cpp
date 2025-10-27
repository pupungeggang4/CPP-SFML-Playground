#include "general.hpp"
#include "decl.hpp"

Field::Field(shared_ptr<Game> game) {
    player = make_shared<FieldPlayer>(game);

    for (int i = 0; i < 10; i++) {
        shared_ptr<Coin> e = make_shared<Coin>(game);
        e->rect.position.x = 200 + std::rand() % 200;
        e->rect.position.y = -100 + std::rand() % 200;
        entityList.push_back(e);
    }
}

void Field::handleTick(shared_ptr<Game> game) {
    shared_ptr<Field> field = game->field;
    player->handleTick(game);

    for (int i = entityList.size() - 1; i >= 0; i--) {
        entityCurrent = entityList[i];
        entityList[i]->handleTick(game);
    }
}

void Field::render(shared_ptr<Game> game) {
    player->render(game);

    for (int i = entityList.size() - 1; i >= 0; i--) {
        entityList[i]->render(game);
    }
}
