#pragma once
#include "general.hpp"
#include "fdef.hpp"
#include "entity.hpp"

class FieldPlayer : public Entity {
    public:
        sf::FloatRect rect = sf::FloatRect({{0, 0}, {80, 80}});
        FieldPlayer();
};