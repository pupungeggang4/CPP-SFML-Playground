#include "level.hpp"
#include "field.hpp"
#include "fieldplayer.hpp"
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
        }
    }
    std::cout << "Loaded level" << std::endl;
}
