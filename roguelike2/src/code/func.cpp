#pragma once
#include "general.hpp"
#include "decl.hpp"

bool Func::pointInsideRectUI(sf::Vector2i pos, sf::IntRect rect) {
    return pos.x > rect.position.x && pos.x < rect.position.x + rect.size.x && pos.y > rect.position.y && pos.y < rect.position.y + rect.size.y;
}