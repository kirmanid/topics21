#include <iostream>
#include <vector>
#include "sudoku.h"

int main(){
    int i;
    srand(i);
    Sudoku s;
    s.setTile(0,0,7);
    s.setTile(1,1,7);
    s.mutate();
    std::cout << "Fitness:  "<< s.getFitness() << "\n";
    s.renderBoard();
}
