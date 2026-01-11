#include "framebuffer.h"
#include <algorithm>

FrameBuffer::FrameBuffer(int w, int h) : width(w), height(h){
    pixels = new COLORREF[width * height];

    ZeroMemory(&bmi, sizeof(BITMAPINFO));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = - height;
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 32;
    bmi.bmiHeader.biCompression = BI_RGB;

    clear(RGB(255,255,255));
}

FrameBuffer::~FrameBuffer(){
    delete[] pixels;
}

void FrameBuffer::clear(COLORREF color){
    std::fill_n(pixels, width * height, color);
}

void FrameBuffer::setPixel(int x, int y, COLORREF color){
    if (x >= 0 && x < width && y >= 0 && y < height){
        BYTE r = GetRValue(color);
        BYTE g = GetGValue(color);
        BYTE b = GetBValue(color);
        pixels[y * width + x] = RGB(b,g,r);
    }
}

void FrameBuffer::present(HDC hdc){
    StretchDIBits(
        hdc,
        0, 0, width, height,
        0, 0, width, height,
        pixels,
        &bmi,
        DIB_RGB_COLORS,
        SRCCOPY
    );
}