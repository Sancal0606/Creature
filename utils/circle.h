#pragma once
#include <windows.h>
#include <vector>
#include "pixel.h"
#include "framebuffer.h"

class Circle{
    private:
        int radius;
        int posX,posY;
        bool fill;
        std::vector<Pixel> pixels;

        void calculatePixels();
    public:
        Circle(int radius, int posX, int posY, bool _fill);
        ~Circle();

        void draw(FrameBuffer& fb);
};