#pragma once
#include <windows.h>
#include <vector>

struct Pixel{
    int x, y;
    COLORREF color;
};

class Creature{
    private:
        std::vector<Pixel> segments;
    public:
        Creature();
        ~Creature();

        void draw(HDC hdc);
        void update();
};