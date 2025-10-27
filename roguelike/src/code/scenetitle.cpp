#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::renderInit(game);
    Render::fillText(game->window, game->rText, game->locale["game_name"], UI::title["text_title"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_start"], 2);
    Render::fillText(game->window, game->rText, game->locale["start_game"], UI::title["text_start"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_collection"], 2);
    Render::fillText(game->window, game->rText, game->locale["collection"], UI::title["text_collection"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_lang"], 2);
    Render::fillText(game->window, game->rText, game->locale["lang"], UI::title["text_lang"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_erase"], 2);
    Render::fillText(game->window, game->rText, game->locale["erase_data"], UI::title["text_erase"]);
    Render::drawRect(game->window, game->rRect, UI::title["button_exit"], 2);
    Render::fillText(game->window, game->rText, game->locale["exit"], UI::title["text_exit"]);
    Render::drawTexture(game->window, game->sprite, game->tex["arrow"], UI::titleArrow[game->selectedTitle]);
    game->window.display();
}

void SceneTitle::keyDown(shared_ptr<Game> game, int key) {
    if (key == K_UP) {
        game->selectedTitle = (game->selectedTitle + 4) % 5;
    } else if (key == K_DOWN) {
        game->selectedTitle = (game->selectedTitle + 1) % 5;
    } else if (key == K_RETURN) {
        if (game->selectedTitle == 0) {
            game->scene = "village";
            game->state = "";
            game->village = make_shared<Village>(game);
        } else if (game->selectedTitle == 1) {

        } else if (game->selectedTitle == 2) {
            if (game->lang == "en") {
                game->lang = "ko";
            } else if (game->lang == "ko") {
                game->lang = "en";
            }
            game->locale = Locale::data[game->lang];
        } else if (game->selectedTitle == 3) {
        } else if (game->selectedTitle == 4) {
            game->window.close();
        }
    }
}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}
