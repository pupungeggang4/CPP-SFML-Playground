#include "field.hpp"
#include "entity.hpp"
#include "game.hpp"

Field::Field() {
    player = make_shared<FieldPlayer>();
    entityList = std::vector<shared_ptr<Entity>>();
    entityList.push_back(make_shared<Coin>());
    entityList.push_back(make_shared<Platform>());
    entityList.push_back(make_shared<Wall>());
}

void Field::handleTick(shared_ptr<Game> game) {
    player->handleTick(game);
    for (int i = entityList.size() - 1; i >= 0; i--) {
        entityList[i]->handleTick(game);
    }
}

void Field::render(shared_ptr<Game> game) {
    game->window.setView(view);
    player->render(game);
    for (int i = 0; i < entityList.size(); i++) {
        entityList[i]->render(game);
    }
}
