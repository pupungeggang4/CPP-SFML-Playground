#pragma once
#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::fillText(game->window, game->rText, "Roguelike Game", UI::title["text_title"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_start"]);
    Render::fillText(game->window, game->rText, "Start Game", UI::title["text_start"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_collection"]);
    Render::fillText(game->window, game->rText, "Collection", UI::title["text_collection"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_exit"]);
    Render::fillText(game->window, game->rText, "Exit", UI::title["text_exit"]);
    game->window.display();
}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {

}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}
