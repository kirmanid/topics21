#include <iostream>
#include <vector>
#include "sudoku.h"

int main(){
    Sudoku s;
    
    for (int i = 0; i < 81; i++){
        s.setTile(i, i % 9);
    }
    
    s.renderBoard();
    std::cout << "FITNESS: " << s.getFitness() << '\n';
    
    GA<Sudoku> world; 
    
    world.populate(s, 0, 128, 32, 0.0);
    
    while (world.population[0].getFitness() < 0){
        world.runTournament();
        std::cout << "FITNESS: " << world.population[0].getFitness() << '\n';
//         world.dumpPopFitness();
    }
    
    world.population[0].renderBoard();
//     std::cout << "FITNESS: " << world.population[0].getFitness() << '\n';
    std::cout << "#GENERATIONS: " << world.tournamentTally << '\n';
//     std::cout << "NUM MUT: " << world.population[0].numMut << '\n';
//     std::cout << "pMetaMutate: " << world.population[0].pMetaMutate << '\n';
    
}
