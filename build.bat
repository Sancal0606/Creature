@echo off
g++ window.cpp creature.cpp utils/circle.cpp utils/framebuffer.cpp -o window.exe -lgdi32
if %errorlevel% equ 0 (
    echo Build successful!
    window.exe
) else (
    echo Build failed!
)