#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include <iostream> //standard lol
#include <fstream> //for file stuff

using namespace std;

class ClassicMode{

  //members
  private:
    char **board; //board 1 made
    char **board2;//board 2 to compare
    int neighborCount;
    int row;
    int column;



  //methods
  public:
    ClassicMode(); //default
    ~ClassicMode();//destructor


    ClassicMode(int row, int column, char** board); //overloaded
    void classicGame();//starts the game
    int countclassic(char** board, int i,int j,int row,int column); //this is the OG count

    void getBoard(int i, int j, int neighborCount); //rules of the game
    char** printBoard(); // prints board to terminal
    char** printOutside(string fileInput, int count);//prints to outside file
    bool isEqual(); //check if equal
    bool isEmpty();//check if empty

};
#endif
