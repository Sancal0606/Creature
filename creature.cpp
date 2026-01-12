#include "Creature.h"

Creature::Creature(int xo, int yo) : circle(21, xo, yo, true) {
    posX = xo;
    posY = yo;
}

Creature::~Creature(){
    //Nothing
}

void Creature::draw(FrameBuffer& fb){
    circle.draw(fb);
}

void Creature::update(){
    
}

void Creature::setPosition(int x, int y){
    posX = x;
    posY = y;
    circle.setPosition(posX, posY);
}