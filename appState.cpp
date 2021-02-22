#include"appState.h"
#include <iostream>

void Entity::update(){
    std::cout << "Base update called!";
}

void InertiaEntity::update(){
    xVel += xAcc;
    yVel += yAcc;
    x += xVel;
    y += yVel;
}

AppState::~AppState(){
    for (Entity* e : entities){
        delete e;
    }
}

Particle::Particle(Entity& entity){
    x = entity.x;
    y = entity.y;
    texture = entity.texture;
}

Particle::Particle(){
    // I need this apparently
}
