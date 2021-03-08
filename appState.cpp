#include"appState.h"
#include <iostream>

void Entity::update(){
    std::cout << "Base update called!";
}

AppState::~AppState(){
    for (Entity* e : entities){
        delete e;
    }
}
