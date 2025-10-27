#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::init(game);
    Render::fillText(game->window, game->rText, game->locale["game_name"], UI::title["text_title"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_start"], 2);
    Render::fillText(game->window, game->rText, game->locale["start_game"], UI::title["text_start"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_lang"], 2);
    Render::fillText(game->window, game->rText, game->locale["lang"], UI::title["text_lang"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_erase"], 2);
    Render::fillText(game->window, game->rText, game->locale["erase_data"], UI::title["text_erase"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_exit"], 2);
    Render::fillText(game->window, game->rText, game->locale["exit"], UI::title["text_exit"]);
    Render::drawImage(game->window, game->sprite, game->image["arrow"], UI::titleArrow[game->selectedTitle]);
    game->window.display();
}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {
    if (key == K_UP) {
        game->selectedTitle = (game->selectedTitle + 3) % 4;
    }
    if (key == K_DOWN) {
        game->selectedTitle = (game->selectedTitle + 1) % 4;
    }
    if (key == K_RETURN) {
        if (game->selectedTitle == 0) {
            game->scene = "field";
            game->state = "";
            game->menu = false;
        }
        if (game->selectedTitle == 1) {
            if (game->lang == "en") {
                game->lang = "ko";
            } else {
                game->lang = "en";
            }
            game->locale = Locale::data[game->lang];
        }
        if (game->selectedTitle == 3) {
            game->window.close();
        }
    }
}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}
