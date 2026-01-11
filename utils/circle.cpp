#include "Circle.h"
#include <iostream>

Circle::Circle(int _radius, int _posX, int _posY){
    radius = _radius;
    posX = _posX;
    posY = _posY;
    calculatePixels();
}

Circle::~Circle(){
    //Nothing
}

void Circle::calculatePixels(){
    std::cout << "radius: " << radius << ", posX: " << posX << ", posY: " << posY << std::endl;
    int x = 0;
    int y = -radius;
    int p = -radius;
    while (x < -y){
        if (p > 0){
            y += 1;
            p += 2 * (x + y) + 1;
        }else{
            p += 2 * x + 1;
        }

        pixels.push_back({posX + x, posY + y, RGB(255,0,0)});
        pixels.push_back({posX - x, posY + y, RGB(255,0,0)});
        pixels.push_back({posX + x, posY - y, RGB(255,0,0)});
        pixels.push_back({posX - x, posY - y, RGB(255,0,0)});
        pixels.push_back({posX + y, posY + x, RGB(255,0,0)});
        pixels.push_back({posX + y, posY - x, RGB(255,0,0)});
        pixels.push_back({posX - y, posY + x, RGB(255,0,0)});
        pixels.push_back({posX - y, posY - x, RGB(255,0,0)});
        x += 1;
    }
}

void Circle::draw(HDC hdc){
    for(auto &p: pixels){
        SetPixel(hdc, p.x, p.y, p.color);
    }
}