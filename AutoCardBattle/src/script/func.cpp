#include "general.hpp"
#include "decl.hpp"

bool pointInsideRectUI(sf::Vector2f point, std::vector<float> rect) {
    return point.x > rect[0] && point.x < rect[0] + rect[2] && point.y > rect[1] && point.y < rect[1] + rect[3];
}