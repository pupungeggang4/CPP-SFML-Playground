#pragma once
#include "general.hpp"
#include "decl.hpp"

void Render::renderInit(shared_ptr<Game> game) {
    game->rRect.setOutlineColor(sf::Color::Black);
    game->rText.setFillColor(sf::Color::Black);
}

void Render::renderAdventureConfirm(shared_ptr<Game> game) {
    drawRect(game->window, game->rRect, UI::adventureConfirm["rect"], 0);
    drawRect(game->window, game->rRect, UI::adventureConfirm["rect"], 2);
    fillText(game->window, game->rText, game->locale["adventure_start"], UI::adventureConfirm["text_title"]);
    drawRect(game->window, game->rRect, UI::adventureConfirm["button_yes"], 2);
    fillText(game->window, game->rText, game->locale["yes"], UI::adventureConfirm["text_yes"]);
    drawRect(game->window, game->rRect, UI::adventureConfirm["button_no"], 2);
    fillText(game->window, game->rText, game->locale["no"], UI::adventureConfirm["text_no"]);
    drawTexture(game->window, game->sprite, game->tex["arrow"], UI::adventureConfirmArrow[game->selectedAdventureConfirm]);
}

void Render::renderAdventureStart(shared_ptr<Game> game) {
    drawRect(game->window, game->rRect, std::get<0>(UI::window["rect"]), 0);
    drawRect(game->window, game->rRect, std::get<0>(UI::window["rect"]), 2);
    fillText(game->window, game->rText, game->locale["select_weapon"], std::get<0>(UI::window["text_title"]));

    for (int i = 0; i < 3; i++) {
        drawRect(game->window, game->rRect, std::get<1>(UI::window["weapon"])[i], 2);
    }
    drawTexture(game->window, game->sprite, game->tex["arrow"], std::get<1>(UI::window["arrow_weapon"])[game->selectedAdventureStart]);
}

void Render::renderMenuVillage(shared_ptr<Game> game) {
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

void Render::fillText(sf::RenderTarget& rt, sf::Text& rText, sf::String& text, std::vector<int> pos) {
    rText.setString(text);
    rText.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(rText);
}

void Render::drawRect(sf::RenderTarget& rt, sf::RectangleShape& rRect, std::vector<int> rect, float thickness) {
    rRect.setOutlineThickness(thickness);
    rRect.setPosition({float(rect[0]), float(rect[1])});
    rRect.setSize({float(rect[2]), float(rect[3])});
    rt.draw(rRect);
}

void Render::drawTexture(sf::RenderTarget& rt, sf::Sprite& sprite, sf::Texture& texture, std::vector<int> pos) {
    sprite.setTexture(texture, true);
    sprite.setPosition({float(pos[0]), float(pos[1])});
    rt.draw(sprite);
}

void Render::drawCenterCam(sf::RenderTarget& rt, sf::Sprite& sprite, sf::FloatRect rect, sf::FloatRect cam) {
    sf::Vector2f pos = rect.position - rect.size / 2.0f - cam.position + cam.size / 2.0f;
    sprite.setPosition(pos);
    rt.draw(sprite);
}