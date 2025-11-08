#pragma once
#include "general.hpp"
#include "fdef.hpp"

class Render {
    public:
        static void drawAtCenter(sf::RenderTarget&, sf::RectangleShape&, sf::FloatRect&);
};