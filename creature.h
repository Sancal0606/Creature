#pragma once
#include <windows.h>
#include <vector>
#include "utils/pixel.h"
#include "utils/framebuffer.h"


class Creature{
    private:
        std::vector<Pixel> segments;
    public:
        Creature();
        ~Creature();

        void draw(FrameBuffer& fb);
        void update();
};