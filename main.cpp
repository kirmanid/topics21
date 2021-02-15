#include <SDL2/SDL.h>
#include <iostream>
#include <vector>
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
                if (event.button.button == SDL_BUTTON_LEFT){
                    InertiaEntity* square = new InertiaEntity;
                    square->texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("./rounded-square.bmp"));
                    SDL_QueryTexture(square->texture, NULL, NULL, &square->w, &square->h);
                    SDL_GetMouseState(&square->x, &square->y);
                    square->actualX = float(square->x);
                    square->actualY = float(square->y);
                    square->w *= 0.25;
                    square->h *= 0.25;
                    square->yAcc = 0.3;
                    state.entities.push_back(square);
                }
                break;
            default:
                break;
        }
    }
}

void updateState(AppState& state){
    for (int i = 0; i < state.entities.size(); i++){
        state.entities[i]->update();
    }
}

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
        updateState(state);
        drawScene(state, app);
        SDL_Delay(tick);
    }
}
