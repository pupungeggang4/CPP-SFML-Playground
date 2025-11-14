#pragma once
#include "general.hpp"

class Entity;

class Physics {
    public:
        static float checkCollideUp(sf::FloatRect, sf::FloatRect);
        static float checkCollideDown(sf::FloatRect, sf::FloatRect);
        static float checkCollideLeft(sf::FloatRect, sf::FloatRect);
        static float checkCollideRight(sf::FloatRect, sf::FloatRect);
};
