#pragma once
#include "general.hpp"
#include "fdef.hpp"

#include "render.hpp"

#include "game.hpp"
#include "entity.hpp"

class FieldPlayer : public Entity {
    public:
        sf::FloatRect rect = sf::FloatRect({{0, 0}, {80, 80}});
        sf::RectangleShape rectS = sf::RectangleShape({80, 80});

        FieldPlayer();
        void handleTick(shared_ptr<Game>);
        void render(shared_ptr<Game>);
};