#include "general.hpp"
#include "decl.hpp"

bool pointInsideRectUI(sf::Vector2f pos, sf::FloatRect rect) {
    return pos.x > rect.position.x && pos.y < rect.position.x + rect.size.x && pos.y > rect.position.y && pos.y < rect.position.y + rect.size.y;
}