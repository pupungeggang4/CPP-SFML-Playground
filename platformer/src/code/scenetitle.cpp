#include "general.hpp"
#include "decl.hpp"

void SceneTitle::loop(shared_ptr<Game> game) {
    render(game);
}

void SceneTitle::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::init(game);
    Render::fillText(game->window, game->rText, "Platformer Game", UI::title["text_title"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_start"]);
    Render::fillText(game->window, game->rText, "Start Game", UI::title["text_start"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_lang"]);
    Render::fillText(game->window, game->rText, "English", UI::title["text_lang"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_erase"]);
    Render::fillText(game->window, game->rText, "Erase Data", UI::title["text_erase"]);
    Render::strokeRect(game->window, game->rRect, UI::title["button_exit"]);
    Render::fillText(game->window, game->rText, "Exit", UI::title["text_exit"]);
    Render::drawImage(game->window, game->sprite, game->tex["arrow"], UI::titleArrow[game->selectedTitle]);
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
        if (game->selectedTitle == 3) {
            game->window.close();
        }
    }
}

void SceneTitle::keyUp(shared_ptr<Game> game, int key) {

}
