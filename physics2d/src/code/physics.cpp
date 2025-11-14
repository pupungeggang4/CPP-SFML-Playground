#include "physics.hpp"

float Physics::checkCollideUp(sf::FloatRect base, sf::FloatRect entity) {
    if (std::abs(base.position.x - entity.position.x) < (base.size.x / 2 + entity.size.x / 2)) {
        if (entity.position.y < base.position.y) {
            return base.size.y / 2 + entity.size.y / 2 - (base.position.y - entity.position.y);
        }
    }
    return 0;
}

float Physics::checkCollideDown(sf::FloatRect base, sf::FloatRect entity) {
if (std::abs(base.position.x - entity.position.x) < (base.size.x / 2 + entity.size.x / 2)) {
        if (entity.position.y > base.position.y) {
            return base.size.y / 2 + entity.size.y / 2 + (base.position.y - entity.position.y);
        }
    }
    return 0;
}

float Physics::checkCollideLeft(sf::FloatRect base, sf::FloatRect entity) {
    if (std::abs(base.position.y - entity.position.y) < (base.size.y / 2 + entity.size.y / 2)) {
        if (entity.position.x < base.position.x) {
            return base.size.x / 2 + entity.size.x / 2 - (base.position.x - entity.position.x);
        }
    }
    return 0;
}

float Physics::checkCollideRight(sf::FloatRect base, sf::FloatRect entity) {
    if (std::abs(base.position.y - entity.position.y) < (base.size.y / 2 + entity.size.y / 2)) {
        if (entity.position.x > base.position.x) {
            return base.size.x / 2 + entity.size.x / 2 + (base.position.x - entity.position.x);
        }
    }
    return 0;
}
