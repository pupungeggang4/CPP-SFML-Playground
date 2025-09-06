#include "field.hpp"

bool pointInsideRectUI(sf::Vector2 pos, sf::Rect rect) {
    return pos.x > rect.position.x && pos.y < rect.position.x + rect.size.x && pos.y > rect.position.y && pos.y < rect.position.y + rect.size.y;
}