#include "render.hpp"

void Render::drawAtCenter(sf::RenderTarget& target, sf::RectangleShape& rs, sf::FloatRect& rect) {
    rs.setPosition(rect.position - rect.size / 2.0f);
    target.draw(rs);
}