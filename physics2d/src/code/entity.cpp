#include "entity.hpp"

Entity::Entity() {
    
}

Coin::Coin() : Entity() {
    //texture = Res::texture->at("sprite_coin");
}

void Coin::render(shared_ptr<Game> game) {
    game->window.draw(sprite);
}