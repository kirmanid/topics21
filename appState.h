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

class Sudoku{
public:
    void mutate();
    void adoptParams(Sudoku*);
    float getFitness();
    float getAltFitness(){return 0;};
    int[81] cells;
    bool[81] fixed;
};

class AppState{
public:
    void update();
    std::vector<Entity*> entities;
    ~AppState();
};

#endif
