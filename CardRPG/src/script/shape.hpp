#pragma once
#include "general.hpp"
#include "fdef.hpp"

class Vec2 {
    public:
        float x, y;
        Vec2(float x = 0.0, float y = 0.0);
        void printVec();
};

class Rect2 {
    public:
        shared_ptr<Vec2> pos, size;
};