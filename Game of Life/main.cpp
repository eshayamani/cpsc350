//header files

#include "Simulation.h"
#include <iostream>
#include <fstream>

using namespace std;

int main (){

  Simulation *gameSim = new Simulation();

  gameSim->startgame();//starts the game and makes the first grid
  gameSim->startmode(); // prompts user for what mode to use and then runs through it 

  delete gameSim;

  }
