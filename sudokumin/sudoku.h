#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <algorithm>
#include <iostream>
#include "ga.h"

class Sudoku{
public:
    void setTile(int index, int value);
    int getTile(int index);
    void fixTile(int index);
    
    void setTile(int x, int y, int value);
    int getTile(int x, int y);
    void fixTile(int x, int y);
    
    void renderBoard();
    void mutate();
    void adoptParams(Sudoku&);
    float getFitness();
    float getAltFitness(){std::cout<< "WHYYYYYYYYYYYYYYYYYYYYY";return 0;};
private:
    bool fixed[81] = {};
    int cells[81] = {};
};

#endif
