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
                if (event.button.button == SDL_BUTTON_LEFT){
                    Particle* square = new Particle;
                    square->texture = SDL_CreateTextureFromSurface(renderer, SDL_LoadBMP("./rounded-square.bmp"));
                    SDL_QueryTexture(square->texture, NULL, NULL, &square->w, &square->h);
                    SDL_GetMouseState(&square->x, &square->y);
                    square->x = square->x;
                    square->y = square->y;
                    square->w *= 0.25;
                    square->h *= 0.25;
                    square->collisionRadius = 0.5 * square->w;
                    square->yAcc = 0.3; 
                    state.entities.push_back(square);
                }
                break;
            default:
                break;
        }
    }
}

struct Collision{
    Entity* obj1;
    Entity* obj2;
};

std::vector<Collision> getCollisions(std::vector<Particle*> particles){
    std::sort(particles.begin(), particles.end(), [](Entity* a, Entity* b){
        return a->x > b->x;
    });
    int j, activeMax, candidateMin;
    std::vector<Collision> collisions;
    for (int i = 0; i < particles.size(); i++){
        activeMax = int(particles[i]->x + 2 * particles[i]->collisionRadius);
        j = i;
        while(true){
            j++;
            if (j == particles.size()){
                break;
            }
            candidateMin = particles[j]->x;
            if(activeMax > candidateMin){
                std::cout << activeMax - candidateMin << '\n';
                Collision c;
                c.obj1 = particles[i];
                c.obj2 = particles[j];
                collisions.push_back(c);
            } else {
                break;
            }
        }
    }
    return collisions;
}

//// should be update method on class AppState
void updateState(AppState& state){
    std::vector<Particle*> particles;
    for (int i = 0; i < state.entities.size(); i++){
        Particle* p = dynamic_cast<Particle*>(state.entities[i]);
        if (p){
            particles.push_back(p);
        }
        state.entities[i]->update();
    }
    std::vector<Collision> collisions = getCollisions(particles);
//     std::cout << collisions.size() << '\n'; ////////////////////////////////////
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
        updateState(state);
        drawScene(state, app);
        SDL_Delay(tick);
    }
}
