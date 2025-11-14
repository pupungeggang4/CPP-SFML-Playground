#include "level.hpp"
#include "field.hpp"
#include "entity.hpp"

void LevelLoader::loadLevel(shared_ptr<Field> field, std::string path) {
    field->entityList.clear();
    std::ifstream file(path);
    std::istringstream iss;
    std::string line = "";
    while (std::getline(file, line)) {
        iss.seekg(0);
        iss.clear();
        iss.str(line);
        std::string first;
        while (iss >> first) {
            if (first == "start_pos") {
                float x, y;
                iss >> x >> y;
                field->player->rect.position.x = x;
                field->player->rect.position.y = y;
            }
            if (first == "coin") {
                float x, y;
                iss >> x >> y;
                shared_ptr<Coin> coin = make_shared<Coin>();
                coin->rect.position.x = x;
                coin->rect.position.y = y;
                field->entityList.push_back(coin);
            }
            if (first == "platform") {
                float x, y, w, h;
                iss >> x >> y >> w >> h;
                shared_ptr<Platform> platform = make_shared<Platform>();
                platform->rect.position.x = x;
                platform->rect.position.y = y;
                platform->rect.size.x = w;
                platform->rect.size.y = h;
                field->entityList.push_back(platform);
            }
            if (first == "wall") {
                float x, y, w, h;
                iss >> x >> y >> w >> h;
                shared_ptr<Wall> wall = make_shared<Wall>();
                wall->rect.position.x = x;
                wall->rect.position.y = y;
                wall->rect.size.x = w;
                wall->rect.size.y = h;
                wall->sprite.setTextureRect(sf::IntRect(wall->rect));
                field->entityList.push_back(wall);
            }
        }
    }
    std::cout << "Loaded level" << std::endl;
}
