
//header guards
#ifndef GRID_H
#define GRID_H

#include <iostream> //standard
#include <fstream> // for file stuff

using namespace std;

class Grid{

  //members
  private:
    char **board;//initial board
    char **board2;//second board
    int row;
    int column;
    float pop;//density
    string temp;// helps to read from input file

  //methods
  public:
    Grid();//default
    Grid(int row, int column, float pop);//default rand grid
    Grid(int row, int column, string temp);//rand from input file
    ~Grid();//destructor
    //given by user
    char** randGen(); //rand grid
    char** fileGen(); //makes grid from input file



};
#endif
