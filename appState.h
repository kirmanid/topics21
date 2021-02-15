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

class InertiaEntity : public Entity {
public:
    float xVel = 0;
    float yVel = 0;
    float xAcc = 0;
    float yAcc = 0;
    float actualX;
    float actualY;
    void update() override;
};

class AppState{
public:
    std::vector<Entity*> entities;
    ~AppState();
};

#endif
