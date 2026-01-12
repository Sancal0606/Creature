#pragma once
#include <windows.h>
#include <vector>
#include "utils/pixel.h"
#include "utils/framebuffer.h"
#include "./utils/circle.h"



class Creature{
    private:
        std::vector<Pixel> segments;
        Circle circle;
        int posX, posY;

    public:
        Creature(int xo, int yo);
        ~Creature();

        void draw(FrameBuffer& fb);
        void update();
        void setPosition(int x, int y);
};