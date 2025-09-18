#include "general.hpp"
#include "decl.hpp"

bool pointInsideRectUI(sf::Vector2f point, sf::FloatRect rect) {
    return point.x > rect.position.x && point.x < rect.position.x + rect.size.x && point.y > rect.position.y && point.y < rect.position.y + rect.size.y;
}