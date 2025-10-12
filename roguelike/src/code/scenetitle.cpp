#pragma once
#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::fillText(game->window, game->rText, "Roguelike Game", UI::title["text_title"][0]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_start"][0]);
    Render::fillText(game->window, game->rText, "Start Game", UI::title["text_start"][0]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_collection"][0]);
    Render::fillText(game->window, game->rText, "Collection", UI::title["text_collection"][0]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_exit"][0]);
    Render::fillText(game->window, game->rText, "Exit", UI::title["text_exit"][0]);
    Render::drawTexture(game->window, game->tex["arrow"], game->sprite, UI::title["arrow"][game->selectedTitle]);
    game->window.display();
}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {
    if (key == K_UP) {
        game->selectedTitle = (game->selectedTitle + 2) % 3;
    } else if (key == K_DOWN) {
        game->selectedTitle = (game->selectedTitle + 1) % 3;
    } else if (key == K_RETURN) {
        if (game->selectedTitle == 0) {

        } else if (game->selectedTitle == 1) {

        } else if (game->selectedTitle == 2) {
            game->window.close();
        }
    }
}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}
