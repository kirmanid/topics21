#include"appState.h"
#include <iostream>

void Entity::update(){
    std::cout << "Base update called!";
}

void InertiaEntity::update(){
    xVel += xAcc;
    yVel += yAcc;
    actualX += xVel;
    actualY += yVel;
    x = int(actualX);
    y = int(actualY);
}

AppState::~AppState(){
    for (Entity* e : entities){
        delete e;
    }
}
