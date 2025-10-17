#include "general.hpp"
#include "decl.hpp"

void Render::init(shared_ptr<Game> game) {
    game->rRect.setOutlineColor(sf::Color::Black);
    game->rRect.setOutlineThickness(2);
    game->rText.setFillColor(sf::Color::Black);
}

void Render::renderMenu(sf::RenderTarget& rt, shared_ptr<Game> game) {
    game->rRect.setFillColor(sf::Color::White);
    Render::drawRect(rt, game->rRect, UI::menu["rect"], 0);
    Render::drawRect(rt, game->rRect, UI::menu["rect"], 2);
    Render::fillText(rt, game->rText, game->locale["paused"], UI::menu["text_paused"]);
    Render::drawRect(rt, game->rRect, UI::menu["button_resume"], 2);
    Render::fillText(rt, game->rText, game->locale["resume"], UI::menu["text_resume"]);
    Render::drawRect(rt, game->rRect, UI::menu["button_to_title"], 2);
    Render::fillText(rt, game->rText, game->locale["to_title"], UI::menu["text_to_title"]);
    Render::drawRect(rt, game->rRect, UI::menu["button_exit"], 2);
    Render::fillText(rt, game->rText, game->locale["exit"], UI::menu["text_exit"]);
    Render::drawImage(rt, game->sprite, game->tex["arrow"], UI::menuArrow[game->selectedMenu]);
}

void Render::drawRect(sf::RenderTarget& rt, sf::RectangleShape rRect, std::vector<int> pos, float thickness) {
    rRect.setOutlineThickness(thickness);
    rRect.setPosition({float(pos[0]), float(pos[1])});
    rRect.setSize({float(pos[2]), float(pos[3])});
    rt.draw(rRect);
}

void Render::fillText(sf::RenderTarget& rt, sf::Text rText, sf::String text, std::vector<int> pos) {
    rText.setString(text);
    rText.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(rText);
}

void Render::drawImage(sf::RenderTarget& rt, sf::Sprite sprite, sf::Texture texture, std::vector<int> pos) {
    sprite.setTexture(texture, true);
    sprite.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(sprite);
}

void Render::drawCenterCam(sf::RenderTarget& rt, sf::Sprite sprite, sf::FloatRect rect, sf::FloatRect cam) {
    sprite.setPosition({
        rect.position.x - rect.size.x / 2 - cam.position.x + cam.size.x / 2,
        rect.position.y - rect.size.y / 2 - cam.position.y + cam.size.y / 2
    });
    rt.draw(sprite);
}
