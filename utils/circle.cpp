#include "Circle.h"
#include <iostream>

Circle::Circle(int _radius, int _posX, int _posY, bool _fill){
    radius = _radius;
    posX = _posX;
    posY = _posY;
    fill = _fill;
    calculatePixels();
}

Circle::~Circle(){
    //Nothing
}

void Circle::calculatePixels(){
    int x = 0;
    int y = -radius;
    int p = -radius;

    std::vector<int> scanline(2 * radius + 1, 0);

    auto store = [&](int sy, int sx) {
        int idx = sy + radius;
        scanline[idx] = std::max(scanline[idx], sx);
    };

    while (x < -y){
        if (p > 0){
            y += 1;
            p += 2 * (x + y) + 1;
        }else{
            p += 2 * x + 1;
        }

        store(y, x);
        store(-y, x);
        store(x, -y);
        store(-x, -y);

        //Perimeter
        if(!fill){
            pixels.push_back({posX + x, posY + y, RGB(255,0,0)});
            pixels.push_back({posX - x, posY + y, RGB(255,0,0)});
            pixels.push_back({posX + x, posY - y, RGB(255,0,0)});
            pixels.push_back({posX - x, posY - y, RGB(255,0,0)});
            pixels.push_back({posX + y, posY + x, RGB(255,0,0)});
            pixels.push_back({posX + y, posY - x, RGB(255,0,0)});
            pixels.push_back({posX - y, posY + x, RGB(255,0,0)});
            pixels.push_back({posX - y, posY - x, RGB(255,0,0)});
        }
        x += 1;
    }
    if (fill) {
        for (int sy = -radius; sy <= radius; sy++) {
            int maxX = scanline[sy + radius];
            for (int i = -maxX; i <= maxX; i++) {
                pixels.push_back({posX + i, posY + sy, RGB(128,0,0)});
            }
        }
    }
    
}

void Circle::draw(FrameBuffer& fb){
    for(auto &p: pixels){
        fb.setPixel(p.x, p.y, p.color);
    }
}

void Circle::setPosition(int x, int y){
    posX = x;
    posY = y;
    pixels.clear();
    calculatePixels();
}