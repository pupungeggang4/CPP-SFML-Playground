#include "shape.hpp"

Vec2::Vec2(float x, float y) {
    this->x = x;
    this->y = y;
}

void Vec2::printVec() {
    std::cout << '(' << x << ',' << y << ')' << std::endl;
}