#ifndef RENDERWINDOW_H
#define RENDERWINDOW_H

#include <SDL2/SDL.h>

class RenderWindow{
public:
    RenderWindow(char* winTitle, unsigned int width, unsigned int height);
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Surface* surface;
};

#endif
