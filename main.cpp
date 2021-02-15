#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

struct renderWindow{
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Surface* surface;
};

struct entity{
    int x;
    int y;
    int w;
    int h;
    SDL_Texture* texture;
    virtual void update(){std::cout<< "base update called\n";};
};

struct inertiaEntity : public entity {
    float xVel = 0;
    float yVel = 0;
    float xAcc = 0;
    float yAcc = 0;
    float actualX;
    float actualY;
    void update() override{
        xVel += xAcc;
        yVel += yAcc;
        actualX += xVel;
        actualY += yVel;
        x = int(actualX);
        y = int(actualY);
    }
};

struct appState{
    std::vector<entity> entities;
};

renderWindow makeWindow(char* winTitle, unsigned int width, unsigned int height){
    renderWindow app;
    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        std::cout << "Initialization failed! Error:\n" << SDL_GetError() << "\n";
        exit(1);
    }
    app.window = SDL_CreateWindow(winTitle, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
    if (!app.window){
        std::cout << "Window creation failed! Error:\n" << SDL_GetError() << "\n";
        exit(2);
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");
    app.renderer = SDL_CreateRenderer(app.window, -1, SDL_RENDERER_ACCELERATED); // Uses graphics card when possible
        if (!app.renderer){
        std::cout << "Renderer creation failed! Error:\n" << SDL_GetError() << "\n";
        exit(3);
    }
    app.surface = SDL_GetWindowSurface(app.window);
    return app;
}

// modifes appState based off of input queue
void handleInput(appState& state, renderWindow& app){
    SDL_Event event;
    while(SDL_PollEvent(&event)){
        switch(event.type){
            case SDL_QUIT:
                exit(0);
                break;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT){
                    inertiaEntity square;
                    square.texture = SDL_CreateTextureFromSurface(app.renderer, SDL_LoadBMP("./rounded-square.bmp"));
                    SDL_QueryTexture(square.texture, NULL, NULL, &square.w, &square.h);
                    SDL_GetMouseState(&square.x, &square.y);
                    square.actualX = float(square.x);
                    square.actualY = float(square.y);
                    square.w *= 0.25;
                    square.h *= 0.25;
                    square.yVel = 2;
                    state.entities.push_back(square);
                }
                break;
            default:
                break;
        }
    }
}

void updateState(appState& state){
    for (int i = 0; i < state.entities.size(); i++){
        state.entities[i].update();
        state.entities[i].x +=2;
    }
}

// turns appState into rendered scene. Do not modify appState!!
void drawScene(appState& state, renderWindow& app){
    SDL_RenderClear(app.renderer);
    // render entities
    for (entity e : state.entities){
        SDL_Rect dest;
        dest.x = e.x;
        dest.y = e.y;
        dest.h = e.h;
        dest.w = e.w;
        SDL_RenderCopy(app.renderer, e.texture, NULL, &dest);
    }
    SDL_RenderPresent(app.renderer);
}

int main(){
    renderWindow app = makeWindow("teeest", 1280, 720);
    appState state;
    unsigned int tick = 16;

    while(true){
        handleInput(state, app);
        updateState(state);
        drawScene(state, app);
        SDL_Delay(tick);
    }
}
