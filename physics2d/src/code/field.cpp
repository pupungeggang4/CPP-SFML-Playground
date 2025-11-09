#include "field.hpp"
#include "fieldplayer.hpp"
#include "entity.hpp"
#include "game.hpp"

Field::Field() {
    player = make_shared<FieldPlayer>();
    entityList = std::vector<shared_ptr<Entity>>();
    entityList.push_back(make_shared<Coin>());
}

void Field::handleTick(shared_ptr<Game> game) {
    player->handleTick(game);
}

void Field::render(shared_ptr<Game> game) {
    player->render(game);
    for (int i = 0; i < entityList.size(); i++) {
        entityList[i]->render(game);
    }
}