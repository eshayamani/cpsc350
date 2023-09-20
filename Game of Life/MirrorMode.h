#ifndef MIRRORMODE_H
#define MIRRORMODE_H

#include <iostream> //standard
#include <fstream> // for file stuff
#include "ClassicMode.h" //needed bc needs methods from classic

using namespace std;

class MirrorMode{

  //members
  private:
    char **board; //initial board
    char **board2; //board 2 to compare
    int neighborCount;
    int row;
    int column;


  //methods
  public:
    MirrorMode();//default
    MirrorMode(int row, int column, char** board);//overloaded
    ~MirrorMode();//destructor
    void mirrorGame();// runs through each cell and calls other methods
    int mirrorCount(char **board, int i, int j, int row, int column);// counts neighbors
    bool isCorner(char **board, int i, int j, int row, int column); //checks weather is corner
    int forCorner(char **board, int i, int j, int row, int column);//follows rules for if corner
    int forEdge(char **board, int i, int j,int row, int column); //follows rule for edges


    void getBoard(int i, int j, int neighborCount); //rules of the game
    char** printBoard(); //prints board to terminal
    char** printOutside(string fileInput, int count);//prints board to output file
    bool isEqual();//checks if equal
    bool isEmpty();//checks if empty
};

#endif
