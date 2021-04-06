#include "sudoku.h"

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

void Sudoku::adoptParams(Sudoku& victor){
    *cells = *victor.cells;
    *fixed = *victor.fixed;
}

/*
// for Sudoku, fitness is -1 * number of errors. 0 errors corresponds to a solved sudoku
float Sudoku::getFitness(){
    int errors = 0;
    std::vector<bool> nineFalse(9,false);
    std::vector<bool> used = nineFalse;
    for (int n = 0; n < 9; n++){
        int i;
        //grids
        i = 3 * (n % 4) + 27 * (n / 4); // upper left corner of grid
        used[i] = true;
        for (int m = 1; m <= 8; m++){
            bool addSeven = m % 3 == 0;
            i += addSeven? 7 : 1;
            if (used[i]){
                std::cout << "i = " << i << ",*i = " << cells[i]<<", n = " << n << '\n';
                errors++;
                break;
            }
            used[i] = true;
        }
        
        //cols
        used = nineFalse;
        i = n;
        used[i] = true;
        for (int m = 1; m <= 8; m++){
            i += 9;
            std::cout << i << std::endl;
            if (used[i]){
                errors++;
                break;
            }
            used[i] = true;
        }

        //rows
        used = nineFalse;
        i = 9*n;
        used[i] = true;
        for (int m = 1; m <= 8; m++){
            i++;
            if (used[i]){
                errors++;
                break;
            }
            used[i] = true;
        }
    }
    return -1 * errors;
}
*/

float Sudoku::getFitness(){
    int errors = 0;
    std::vector<bool> nineFalse(9,false);
    std::vector<bool> used = nineFalse;
    //////
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
