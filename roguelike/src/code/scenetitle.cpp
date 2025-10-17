#pragma once
#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::fillText(game->window, game->rText, game->locale["game_name"], UI::title["text_title"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_start"]);
    Render::fillText(game->window, game->rText, game->locale["start_game"], UI::title["text_start"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_collection"]);
    Render::fillText(game->window, game->rText, game->locale["collection"], UI::title["text_collection"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_lang"]);
    Render::fillText(game->window, game->rText, game->locale["lang"], UI::title["text_lang"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_erase"]);
    Render::fillText(game->window, game->rText, game->locale["erase_data"], UI::title["text_erase"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_exit"]);
    Render::fillText(game->window, game->rText, game->locale["exit"], UI::title["text_exit"]);
    Render::drawTexture(game->window, game->tex["arrow"], game->sprite, UI::titleArrow[game->selectedTitle]);
    game->window.display();
}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {
    if (key == K_UP) {
        game->selectedTitle = (game->selectedTitle + 4) % 5;
    } else if (key == K_DOWN) {
        game->selectedTitle = (game->selectedTitle + 1) % 5;
    } else if (key == K_RETURN) {
        if (game->selectedTitle == 0) {

        } else if (game->selectedTitle == 1) {

        } else if (game->selectedTitle == 2) {
            if (game->lang == "en") {
                game->lang = "ko";
            } else if (game->lang == "ko") {
                game->lang = "en";
            }

            game->locale = Locale::data[game->lang];
        } else if (game->selectedTitle == 4) {
            game->window.close();
        }
    }
}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}
