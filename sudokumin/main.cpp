#include <iostream>
#include <vector>
#include "sudoku.h"

int main(){
    int i;
    srand(i);
    Sudoku s;
    s.setTile(0,7);
    s.setTile(1,7);
//     std::cout << s.getFitness() << "\n";
    s.renderBoard();
}
