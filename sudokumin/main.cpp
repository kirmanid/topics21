#include <iostream>
#include <vector>
#include "sudoku.h"

int main(){
    int i;
    srand(i);
    Sudoku s;
    
    for (int i = 0; i < 81; i++){
        s.setTile(i, i%9);
    }
    
    s.renderBoard();
    std::cout << "FITNESS: " << s.getFitness() << '\n';
    
    GA<Sudoku> world;
    world.populate(s, 0, 16, 4, 0.0);
    
    while (world.tournamentTally < 1e4){
        world.runTournament();
//          std::cout << "FITNESS: " << world.population[0].getFitness() << '\n';
        world.dumpPopFitness();
    }
    
    world.population[0].renderBoard();
    std::cout << "FITNESS: " << world.population[0].getFitness() << '\n';
    
}
