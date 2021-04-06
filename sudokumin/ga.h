#ifndef GA_H
#define GA_H

#include <vector>
#include <random>

/*
 * This is a population-sampling genetic algorithm. Think 'iterated Hunger Games'. 
 * 'adam' must be an organism (object) with a working .mutate(), .adoptParams(T*), and .getFitness(). If pAltTournament > 0, it must also have a .getAltFitness().
 * It has an alternative fitness feature, which means there is a chance that each tournament will use a different fitness function.
 * This helps with variety, and also multi-objective optimization. Set pAltTournament to -1 or something if you don't want it.
 * It uses elitism (deterministic, only max fitness individual of tournament survices). Noise in fitness approximation can add needed variety.
 * If you ever feel tempted to use a better RNG, like xorshift*, recall that genetic algorithms often perform better with worse RNGs. rand() will do fine.
*/

template <typename T>
class GA{
public:
    void populate(T adam, unsigned int mutationCycles, unsigned int popSize, unsigned int tournamentSize, float pAltTournament);
    void runTournament();
    std::vector<T> population;
    unsigned long int tournamentTally;
private:
    unsigned int tournamentSize;
    float pAltTournament;
};

template <typename T>
void GA<T>::populate(T adam, unsigned int mutationCycles, unsigned int popSize, unsigned int tournamentSize_, float pAltTournament_){
    tournamentTally = 0;
    int i;
    srand(i);
    tournamentSize = tournamentSize_;
    pAltTournament = pAltTournament_;
    while (population.size() < popSize){
        population.push_back(adam);
    }
    for (int i = 0; i < population.size() * mutationCycles; i++){
        population[i % population.size()].mutate();
    }
}

template <typename T>
void GA<T>::runTournament(){
    tournamentTally++;
    std::vector<T*> contestants;
    while (contestants.size() < tournamentSize){
        contestants.push_back(&population[rand() % population.size()]);
    }
    bool alt = pAltTournament > ((float) rand() / (RAND_MAX));
    float bestFitness = -1 * INFINITY;
    int bestContestant = -1;
    float fitness;
    for (int i = 0; i < contestants.size(); i++){
        if (alt){
            fitness = contestants[i]->getAltFitness();
        } else {
            fitness = contestants[i]->getFitness();
        }
        if (fitness >= bestFitness){
            bestFitness = fitness;
            bestContestant = i;
        }
    }
    for (int i = 0; i < contestants.size(); i++){
        if (i == bestContestant){
            continue;
        }
        contestants[i]->adoptParams(*contestants[bestContestant]);
        contestants[i]->mutate();
    }
    /// Uncomment for 'parental death'
//     contestants[bestContestant].mutate();
}

#endif
