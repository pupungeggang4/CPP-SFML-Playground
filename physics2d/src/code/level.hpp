#pragma once
#include "general.hpp"

class Field;
class Entity;
class FieldPlayer;

class LevelLoader {
    public:
        static void loadLevel(shared_ptr<Field>, std::string);
};
