#pragma once
#include "general.hpp"
#include "decl.hpp"

void Render::renderInit(shared_ptr<Game> game) {
    game->rRect.setOutlineColor(sf::Color::Black);
    game->rText.setFillColor(sf::Color::Black);
}

void Render::renderMenu(shared_ptr<Game> game) {
    drawRect(game->window, game->rRect, UI::menuVillage["rect"], 2);
    drawRect(game->window, game->rRect, UI::menuVillage["rect"], 2);
    fillText(game->window, game->rText, game->locale["paused"], UI::menuVillage["text_paused"]);
    drawRect(game->window, game->rRect, UI::menuVillage["button_resume"], 2);
    fillText(game->window, game->rText, game->locale["resume"], UI::menuVillage["text_resume"]);
    drawRect(game->window, game->rRect, UI::menuVillage["button_exit"], 2);
    fillText(game->window, game->rText, game->locale["to_title"], UI::menuVillage["text_exit"]);
    drawRect(game->window, game->rRect, UI::menuVillage["button_quit"], 2);
    fillText(game->window, game->rText, game->locale["exit"], UI::menuVillage["text_quit"]);
    drawTexture(game->window, game->sprite, game->tex["arrow"], UI::menuVillageArrow[game->selectedMenuVillage]);
}

void Render::fillText(sf::RenderTarget& rt, sf::Text rText, sf::String text, std::vector<int> pos) {
    rText.setString(text);
    rText.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(rText);
}

void Render::drawRect(sf::RenderTarget& rt, sf::RectangleShape rRect, std::vector<int> rect, float thickness) {
    rRect.setOutlineThickness(thickness);
    rRect.setPosition({float(rect[0]), float(rect[1])});
    rRect.setSize({float(rect[2]), float(rect[3])});
    rt.draw(rRect);
}

void Render::drawTexture(sf::RenderTarget& rt, sf::Sprite sprite, sf::Texture texture, std::vector<int> pos) {
    sprite.setTexture(texture, true);
    sprite.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(sprite);
}
