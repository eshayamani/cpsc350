
#include "Grid.h"


//default constructor
Grid::Grid(){
  row = 0;
  column  = 0;
  pop = 0;
  temp = "";
}

//makes random generation
Grid::Grid(int r, int c, float p){
  row = r;
  column  = c;
  pop = p;
}

//makes grid from input file
Grid::Grid(int r, int c, string t){
  row = r;
  column  = c;
  temp = t;
}

//destructor
Grid::~Grid(){
  delete board;
}

//makes a random generation
char** Grid::randGen(){
  srand(time(0)); //makes it random

  //creates 2D array
  board = new char *[row];
		for(int i = 0; i < row ; i++){
		    board[i] = new char[column];
		}

  //creates 2nd array
  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}

  int dim = row * column;//dimensions
  int cells = dim * pop;
  int i = 0;

  //randomly adding lives to the grid
  while(i < cells){
      int a =  rand() % row;
      int b =  rand() % column;

      if(board[a][b] == 'X'){
        continue;
      }
      else{
        board[a][b] = 'X';
        board2[a][b] = 'X';
        i++;
      }
    }

    //outputs the first "template" board to the user
    cout << "Board 0" << endl;
    for(int i = 0; i < row; i++){
      cout << endl;
      for(int j = 0; j < column; j++){
        if(!(board[i][j] == 'X')){
          board[i][j] = '-'; //adds the dead "empty" cells
          board2[i][j] = '-';
        }
        cout << board[i][j] << "\t"; //tab for space
      }
    }
    cout << endl;// to make easier to read
    return board;
  }

  //makes grid from input file
  char** Grid::fileGen(){

    //makes initial board
    board = new char *[row];
  		for(int i = 0; i < row ; i++){
  		    board[i] = new char[column];
  		}

    //makes board2 (second board)
    board2 = new char *[row];
    	for(int i = 0; i < row ; i++){
    		   board2[i] = new char[column];
    	}

      //starts at two bc first two lines represent rows and columns
      int count = 2;

      //outputs the board to the terminal for user to check if it got the right grid
      cout << "Board 0" << endl;
        for(int i = 0; i < row; i++){
          cout << endl;
          for(int j = 0; j < column; j++){
              board[i][j] = char(temp[count]);
              board2[i][j] = char(temp[count]);
              count++;

              cout << board[i][j] << "\t";//tab for space
            }
        }
        cout << endl;//to make it easier to read
        return board;
    }
