#include <iostream>
#include <memory>
#include "graphics.h"
#include <cmath>
#include <fstream>

#pragma GCC diagnostic ignored "-Wsign-conversion"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wnarrowing"

using namespace std;
using namespace mssm;
#include "../sudokumin/sudoku.h"

void drawBoard(Graphics& g, Sudoku& s)
{
    int margin = 20;
    int x = margin;
    int y = g.height()-margin;

    for (int i = 0; i < 81; i++){
        Color c = s.fixed[i] ? RED : GREEN;
        g.text({x,y},20,to_string(s.getTile(i)), c);
        x += 20;
        if ((i + 1) % 3 == 0){
            x += 20;
        }
        if ((i + 1) % 9 == 0){
            x = margin;
            y -= 30;
        }
        if ((i + 1) % 27 == 0){
            x = margin;
            y -= 30;
        }
    }
}
void graphicsMain(Graphics& g)
{
    srand(g.randomInt(0,INT_MAX));

    Sudoku s;

    for (int i = 0; i < 81; i++){
        s.setTile(i, i%9);
    }

    GA<Sudoku> world;
    world.populate(s, 0, 128, 32, 0.0);

//    world.population[0].renderBoard();
    std::cout << "FITNESS: " << world.population[0].getFitness() << '\n';

    int x = 0;

    vector<Vec2d> fitness;

    while (g.draw()) {
        g.clear();

        drawBoard(g, world.population[0]);

        fitness.push_back({x,-10.0*world.population[0].getFitness()});

        g.polyline(fitness, WHITE);
        x++;

        world.runTournament();

        g.text({100,100},20,"Fitness: " + to_string(world.population[0].getFitness()));

        for (const Event& e : g.events())
        {
            switch (e.evtType)
            {
            case EvtType::MousePress:
                break;
            case EvtType::MouseRelease:
                break;
            case EvtType::MouseWheel:
                break;
            case EvtType::MouseMove:
                break;
            case EvtType::KeyPress:
                break;
            case EvtType::KeyRelease:
                break;
            default:
                break;
            }
        }
    }
}

int main(int /*argc*/, char** /*argv*/)
{
    // main should be empty except for the following line:
    Graphics g("VectorGraphics", 600, 600, graphicsMain);
    return 0;
}



