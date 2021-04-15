#include "sudoku.h"

void Sudoku::mutate(){
    if ( pMetaMutate > ((float) rand() / (RAND_MAX))){
        
        pMetaMutate *=  ((float) rand() / (RAND_MAX)) > 0.5 ? 0.8 : 1.2;
        
        if (((float) rand() / (RAND_MAX)) > 0.5){
            if (numMut > 1){
                numMut--;
            }
        } else {
            numMut++;
        }
    }
    for (int i = 0; i < numMut; i++){
        int swapA = -1;
        int swapB = -1;
        while (swapA < 0 || swapB < 0){
            swapA = rand() % 81;
            swapB = rand() % 81;
            if(fixed[swapA] || fixed[swapB] || swapA == swapB){
                swapA = -1;
                swapB = -1;
            }
        }
        int bHolder = cells[swapB];
        cells[swapB] = cells[swapA];
        cells[swapA] = bHolder;
    }
}

void Sudoku::adoptParams(Sudoku& victor){
    for (int i = 0; i < 81; i++){
        cells[i] = victor.getTile(i);
        fixed[i] = victor.fixed[i];
    }
}

float Sudoku::getFitness(){
    int errors = 0;
    std::vector<bool> nineFalse(9,false);
    std::vector<bool> used = nineFalse;
    for (int n = 0; n < 9; n++){
        int val;
        //rows
        used = nineFalse;
        for (int m = 0; m < 9; m++){
            val = getTile(9*n + m);
            if (used[val]){
                errors++;
            }
            used[val] = true;
        }
        //cols
        used = nineFalse;
        for (int m = 0; m < 9; m++){
            val = getTile(n + 9*m);
            if (used[val]){
                errors++;
            }
            used[val] = true;
        }
        //grids
        used = nineFalse;
        int x, y;
        int deltaX = 0;
        int deltaY = 0;
        x = 3 * (n % 3);
        y = 3 * (n / 3);
        for (int m = 0; m < 9; m++){
//             std::cout << "x: " << x + deltaX << " y: "  << y + deltaY << '\n';
            val = getTile(x + deltaX, y + deltaY);
            if (used[val]){
                errors++;
            }
            used[val] = true;
            if (deltaX == 2){
                deltaX = 0;
                deltaY++;
            } else {
                deltaX++;
            }
        }
    }
    
    return -1 * errors;
}

void Sudoku::renderBoard(){
    std::cout << '\n';
    for (int i = 0; i < 81; i++){
        std::cout << getTile(i);
        if ((i + 1) % 3 == 0){
            std::cout << " ";
        }
        if ((i + 1) % 9 == 0){
            std::cout << '\n';
        }
        if ((i + 1) % 27 == 0){
            std::cout << '\n';
        }
    }
}

void Sudoku::setTile(int index, int value){
    if (fixed[index] || value > 9){
        return;
    }
    cells[index] = value;
}

void Sudoku::fixTile(int index){
    fixed[index] = true;
}

int Sudoku::getTile(int index){
    return cells[index];
}

void Sudoku::setTile(int x, int y, int value){
    int index = x + 9*y;
    if (fixed[index] || value > 9){
        return;
    }
    cells[index] = value;
}

void Sudoku::fixTile(int x, int y){
    int index = x + 9*y;
    fixed[index] = true;
}

int Sudoku::getTile(int x, int y){
    int index = x + 9*y;
    return cells[index];
}

