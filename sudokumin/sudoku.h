#ifndef SUDOKU_H
#define SUDOKU_H

#include <vector>
#include <algorithm>
#include <iostream>

class Sudoku{
public:
    void setTile(int index, int value);
    int getTile(int index);
    void fixTile(int index);
    void renderBoard();
    void mutate();
    void adoptParams(Sudoku&);
    float getFitness();
    float getAltFitness(){return 0;};
private:
    int cells[81] = {};
    bool fixed[81] = {};
};

#endif
