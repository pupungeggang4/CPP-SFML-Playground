#pragma once
#include "general.hpp"

class Adventure;
class Player;
class Unit;
class Card;

class Render;
class Func;
class Game;

class Func {
    public:
        static bool pointInsideRectUI(sf::Vector2i pos, sf::IntRect rect);
};