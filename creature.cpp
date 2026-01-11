#include "Creature.h"

Creature::Creature(){
    segments.push_back({100, 100, RGB(255,0,0)});
    segments.push_back({101, 100, RGB(255,0,0)});
    segments.push_back({102, 100, RGB(255,0,0)});
    segments.push_back({102, 100, RGB(255,0,0)});
    segments.push_back({101, 101, RGB(0,255,0)});
    segments.push_back({100, 101, RGB(0,0,255)});
}

Creature::~Creature(){
    //Nothing
}

void Creature::draw(FrameBuffer& fb){
    for(auto &p: segments){
        fb.setPixel(p.x, p.y, p.color);
    }
}

void Creature::update(){
    
}