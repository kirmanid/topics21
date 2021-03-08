#ifndef APPSTATE_H
#define APPSTATE_H

#include <SDL2/SDL.h>
#include <vector>

class Entity{
public:
    int x;
    int y;
    int w;
    int h;
    SDL_Texture* texture;
    virtual void update();
};

class AppState{
public:
    std::vector<Entity*> entities;
    ~AppState();
};

#endif
