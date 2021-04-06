// #include"ga.h"
// 
// template <typename T>
// void GA<T>::populate(T adam, unsigned int mutationCycles, unsigned int popSize, unsigned int tournamentSize_, float pAltTournament_){
//     tournamentTally = 0;
//     int i;
//     srand(i);
//     tournamentSize = tournamentSize_;
//     pAltTournament = pAltTournament_;
//     while (population.size() < popSize){
//         population.push_back(adam);
//     }
//     for (int i = 0; i < population.size() * mutationCycles; i++){
//         population[i % population.size()].mutate();
//     }
// }
// 
// template <typename T>
// void GA<T>::runTournament(){
//     tournamentTally++;
//     std::vector<T*> contestants;
//     while (contestants.size() < tournamentSize){
//         contestants.push_back(&population[rand() % population.size()]);
//     }
//     bool alt = pAltTournament > ((float) rand() / (RAND_MAX));
//     float bestFitness = -1 * INFINITY;
//     int bestContestant = -1;
//     float fitness;
//     for (int i = 0; i < contestants.size(); i++){
//         if (alt){
//             fitness = contestants[i]->getAltFitness();
//         } else {
//             fitness = contestants[i]->getFitness();
//         }
//         if (fitness >= bestFitness){
//             bestFitness = fitness;
//             bestContestant = i;
//         }
//     }
//     for (int i = 0; i < contestants.size(); i++){
//         if (i == bestContestant){
//             continue;
//         }
//         contestants[i]->adoptParams(contestants[bestContestant]);
//         contestants[i]->mutate();
//     }
//     / Uncomment for 'parental death'
//     contestants[bestContestant].mutate();
// }
// 
