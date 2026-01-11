#pragma once
#include <windows.h>

class FrameBuffer{
    private:
        COLORREF* pixels;
        int width;
        int height;
        BITMAPINFO bmi;
    public:
        FrameBuffer(int w, int h);
        ~FrameBuffer();

        //Clear the entire buffer to one color
        void clear(COLORREF color);

        //Set a single pixel (with bounds checking)
        void setPixel(int x, int y, COLORREF color);

        //Display the buffer to the screen
        void present(HDC hdc);

        //Get dimensions
        int getWidth() const {return width;}
        int getHeight() const {return height;}
};