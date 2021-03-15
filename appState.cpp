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

void AppState::update(){
    for (int i = 0; i < entities.size(); i++){
        entities[i]->update();
    }
}

void Sudoku::mutate(){
    int swapA = -1;
    int swapB = -1;
    while (swapA < 0 || swapB < 0){
        swapA = rand() % 64;
        swapA = rand() % 64;
        if(fixed[swapA] || fixed[swapB] || swapA == swapB){
            swapA = -1;
            swapB = -1;
        }
    }
    int bHolder = cells[swapB];
    cells[swapB] = cells[swapA];
    cells[swapA] = bHolder;
}

void Sudoku::adoptParams(Sudoku* victor){
    cells = victor->cells;
    fixed = victor->fixed;
}

// for Sudoku, fitness is -1 * number of errors. 0 errors corresponds to a solved sudoku
void Sudoku::getFitness(){
    int errors = 0;
    for (int i = 0; i < 10; i++){
        // incomplete
    }
    return -1 * errors;
}
