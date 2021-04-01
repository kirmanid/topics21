#include "renderWindow.h"
#include <iostream>

RenderWindow::RenderWindow(char* winTitle, unsigned int width, unsigned int height){
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Initialization failed! Error:\n" << SDL_GetError() << "\n";
        exit(1);
    }
    window = SDL_CreateWindow(winTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (!window){
        std::cout << "Window creation failed! Error:\n" << SDL_GetError() << "\n";
        exit(2);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED); // Uses graphics card when possible
    if (!renderer){
        std::cout << "Renderer creation failed! Error:\n" << SDL_GetError() << "\n";
        exit(3);
    }
    surface = SDL_GetWindowSurface(window);
}
