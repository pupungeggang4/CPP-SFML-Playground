#include "general.hpp"
#include "decl.hpp"

void Render::strokeRectUI(sf::RenderWindow& window, sf::RectangleShape r, std::vector<float> rect) {
    float thickness = r.getOutlineThickness();
    r.setPosition({rect[0] + thickness / 2, rect[1] + thickness / 2});
    r.setSize({rect[2], rect[3]});
    window.draw(r);
}

void Render::fillTextUI(sf::RenderWindow& window, sf::Text t, std::string text, std::vector<float> pos) {
    float yOffset = t.getCharacterSize();
    t.setString(text);
    t.setPosition({pos[0], pos[1] - yOffset / 32 * 6});
    window.draw(t);
}