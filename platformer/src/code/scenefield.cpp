#include "general.hpp"
#include "decl.hpp"

void SceneField::loop(shared_ptr<Game> game) {
    if (game->menu == false) {
        if (game->state == "") {
            game->field->handleTick(game);
        }
    }
    render(game);
}

void SceneField::render(shared_ptr<Game> game) {
    game->window.clear(sf::Color::White);
    Render::init(game);

    game->field->render(game);
    Render::drawImage(game->window, game->sprite, game->image["coin"], UI::field["icon_coin"]);
    Render::fillText(game->window, game->rText, std::to_string(game->field->player->coin), UI::field["text_coin"]);

    if (game->menu == true) {
        Render::renderMenu(game);
    }
    
    game->window.display();
}

void SceneField::keyDown(shared_ptr<Game> game, int key) {
    if (game->menu == false) {
        if (key == K_ESCAPE || key == 16) {
            game->menu = true;
            game->selectedMenu = 0;
        }
    } else {
        if (key == K_ESCAPE || key == 16) {
            game->menu = false;
        }

        if (key == K_UP) {
            game->selectedMenu = (game->selectedMenu + 2) % 3;
        }
        if (key == K_DOWN) {
            game->selectedMenu = (game->selectedMenu + 1) % 3;
        }
        if (key == K_RETURN) {
            if (game->selectedMenu == 0) {
                game->menu = false;
            } else if (game->selectedMenu == 1) {
                game->menu = false;
                game->scene = "title";
                game->state = "";
            } else if (game->selectedMenu == 2) {
                game->window.close();
            }
        }
    }
}

void SceneField::keyUp(shared_ptr<Game> game, int key) {

}