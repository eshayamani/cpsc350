#ifndef DONUTMODE_H
#define DONUTMODE_H

#include <iostream> //standard
#include <fstream> //for file  stuff
#include "ClassicMode.h"// to call classic within donut

using namespace std;

class DonutMode{

  //member variables
  private:
    char **board;
    char **board2;
    int neighborCount;
    int row;
    int column;

  //methods
  public:
    DonutMode();//default
    DonutMode(int row, int column, char** board);//overloaded
    ~DonutMode();//destructor
    void donutGame(); //runs through each cell and calls its respective methods
    int donutCount(char **board, int i, int j, int row, int column); //counts neighbors
    bool isCorner(char **board, int i, int j, int row, int column); //checks if corner
    int newCorner(char **board, int i, int j, int row, int column); // rules for if corner
    int newEdge(char **board, int i, int j,int row, int column);// rules for edges


    void getBoard(int i, int j, int neighborCount);//rules of game
    char** printBoard();// prints grid to terminal
    char** printOutside(string fileInput, int count);//prints to output file
    bool isEqual();//checks if equal
    bool isEmpty();//checks if empty
};
#endif
