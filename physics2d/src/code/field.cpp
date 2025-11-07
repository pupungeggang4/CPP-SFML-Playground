#include "field.hpp"

Field::Field() {
    player = make_shared<FieldPlayer>();
    entityList = std::vector<shared_ptr<Entity>>();
}