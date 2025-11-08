#include "field.hpp"

Field::Field() {
    player = make_shared<FieldPlayer>();
    entityList = std::vector<shared_ptr<Entity>>();
}

void Field::handleTick(shared_ptr<Game> game) {
    
}

void Field::render(shared_ptr<Game> game) {
    player->render(game);
}