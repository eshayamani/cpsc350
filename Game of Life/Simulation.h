//header guards:

#ifndef SIMULATION_H
#define SIMULATION_H

//stuff needed
#include "Grid.h"
#include "ClassicMode.h"
#include "DonutMode.h"
#include "MirrorMode.h"
#include <iostream> //standard
#include <fstream>//for files stuff


using namespace std;

class Simulation{

  //members
  private:
    char** board;
    char** board2;
    string outputFile;
    int chosenMode;
    string pause;
    int gearBox; //gearBox bc it determines weather grid will be created automatically or by input file
    bool run;
    bool runMode;
    int row;
    int column;
    float pop;
    string file;
    string inputFile;
    char answer;
    string slow;
    int check;

  //methods
  public:
    Simulation();//default
    ~Simulation();//destructor
    void startgame();//starts the game
    void startmode();//runs the mode once the first board is initilized

};
#endif
