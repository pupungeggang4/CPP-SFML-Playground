#pragma once
#include "general.hpp"
#include "fdef.hpp"
#include "fieldplayer.hpp"

class Field {
    public:
        Field();
        shared_ptr<FieldPlayer> player;
};