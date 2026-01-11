#pragma once
#include <windows.h>
#include <vector>
#include "pixel.h"

class Circle{
    private:
        int radius;
        int posX,posY;
        std::vector<Pixel> pixels;

        void calculatePixels();
    public:
        Circle(int radius, int posX, int posY);
        ~Circle();

        void draw(HDC hdc);
};