//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#include "Simulation.h"
#include <iostream>
#include <fstream>
#include <istream>
using namespace std;

int main (){
  string line;
  //the two given input files
  string studentFile = "studentTable";
  string facultyFile = "facultyTable";

  ifstream infile(studentFile);//reads the file

  //to read files:
  while(getline(infile, line)){
    Simulation *s = new Simulation(studentFile, facultyFile); // takes infiles
    s->runSimulation();
    return 0;
  }

//when file empty:
  Simulation *s = new Simulation();
  s->runSimulation();
}
