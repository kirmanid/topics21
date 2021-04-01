#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "renderWindow.h"
#include "appState.h"

// modifes AppState based off of input queue
void handleInput(AppState& state, SDL_Renderer* renderer){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                break;
            default:
                break;
        }
    }
}

//// should have own header
// turns AppState into rendered scenes
void drawScene(const AppState& state, RenderWindow& app){
    SDL_RenderClear(app.renderer);
    // render entities
    for (Entity* e : state.entities){
        SDL_Rect dest;
        dest.x = e->x;
        dest.y = e->y;
        dest.h = e->h;
        dest.w = e->w;
        SDL_RenderCopy(app.renderer, e->texture, NULL, &dest);
    }
    SDL_RenderPresent(app.renderer);
}

int main(){
    RenderWindow app = RenderWindow("teeest", 1280, 720);
    AppState state;
    unsigned int tick = 16;

    while(true){
        handleInput(state, app.renderer);
        state.update();
        drawScene(state, app);
        SDL_Delay(tick);
    }
}
