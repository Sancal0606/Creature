#pragma once
#include <windows.h>
#include <vector>
#include "utils/pixel.h"


class Creature{
    private:
        std::vector<Pixel> segments;
    public:
        Creature();
        ~Creature();

        void draw(HDC hdc);
        void update();
};