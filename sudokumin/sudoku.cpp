#include "sudoku.h"

void Sudoku::mutate(){
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
//                 break;
            }
            used[val] = true;
        }
        //cols
        used = nineFalse;
        for (int m = 0; m < 9; m++){
            val = getTile(n + 9*m);
            if (used[val]){
                errors++;
//                 break;
            }
            used[val] = true;
        }
        //grids
        used = nineFalse;
        int i = 3 * (n % 4) + 27 * (n / 4); // upper left corner of grid
        used[getTile(i)] = true;
        for (int m = 1; m <= 8; m++){
            bool addSeven = m % 3 == 0;
            i += addSeven? 7 : 1;
            if (used[getTile(i)]){
                errors++;
//                 break;
            }
            used[i] = true;
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

