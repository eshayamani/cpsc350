

#include "ClassicMode.h"


//default constructor
ClassicMode::ClassicMode(){
  neighborCount = 0;
  row = 0;
  column  = 0;
}

//overloaded constructor
ClassicMode::ClassicMode(int r, int c, char** b){
  row = r;
  column  = c;

  board = b;
  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}
}

//destructor
ClassicMode::~ClassicMode(){
  delete board;//trash
  delete board2;//trash
}
//calls the other methods for each cell in grid
void ClassicMode::classicGame() {
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighborCount = countclassic(board,i,j,row,column);
      getBoard(i, j, neighborCount);
    }
  }
}
//makes the new board
int ClassicMode::countclassic(char** board,int i,int j,int row,int column){

  //iterates thru the array

  neighborCount = 0;
  if ((i-1>=0) && (j-1>=0) && (i-1<row) && (j-1<column)) {
    if(board[i-1][j-1] == 'X') {
      neighborCount++;
    }
  }
  if ((i-1>=0) && (j>=0) && (i-1<row) && (j<column)) {
    if(board[i-1][j] == 'X') {
      neighborCount++;
    }
  }
  if ((i-1>=0) && (j+1>=0) && (i-1<row) && (j+1<column)) {
    if(board[i-1][j+1] == 'X') {
      neighborCount++;
    }
  }
  if ((i>=0) && (j-1>=0) && (i<row) && (j-1<column)) {
    if(board[i][j-1] == 'X') {
      neighborCount++;
    }
  }
  if ((i>=0) && (j+1>=0) && (i<row) && (j+1<column)) {
    if(board[i][j+1] == 'X') {
      neighborCount++;
    }
  }
  if ((i+1>=0) && (j-1>=0) && (i+1<row) && (j-1<column)) {
    if(board[i+1][j-1] == 'X') {
      neighborCount++;
    }
  }
  if ((i+1>=0) && (j>=0) && (i+1<row) && (j<column)) {
    if(board[i+1][j] == 'X') {
      neighborCount++;
    }
  }
  if ((i+1>=0) && (j+1>=0) && (i+1<row) && (j+1<column)) {
    if(board[i+1][j+1] == 'X') {
      neighborCount++;
    }
  }
  return neighborCount;
}

//adds the new cells to board 2
void ClassicMode::getBoard(int i, int j, int count){ //rules of the game basically

    if(count == 3){// 3 neighbors = lives
      board2[i][j] = 'X';

    }
    else if(count == 4){ // if four neighbors it dies
      board2[i][j] = '-';

    }
    else if(count == 1 || count == 0){ // dies
      board2[i][j] = '-';

    }
    else if(count == 2){ // stays the same
      board2[i][j] = board[i][j];
    }
    else{
      board2[i][j] = '-'; // else remains dead
    }
}

//prints grid to terminal
char** ClassicMode::printBoard(){

  for(int i = 0; i < row; i++){
    cout << endl;
    for(int j = 0; j < column; j++){
     cout << board2[i][j] << "\t"; // \t is a tab so theres space between everyones lives
    }
    cout << endl;
  }
  return board2;
}

//prints generations onto the output file
char** ClassicMode::printOutside(string file, int count){
  ofstream outputFile;

  outputFile.open(file, fstream::app);

  outputFile << "Board " << count << endl;

  for(int i = 0; i < row; i++){
      for(int j = 0; j < column; j++){
       outputFile << board2[i][j] << "\t";
      }
      outputFile << "\n";
    }
    outputFile << endl;
    outputFile.close();
    outputFile << endl;
    return board2;
}

//checking if the grids  are equal
bool ClassicMode::isEqual(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
        if (board[i][j] != board2[i][j]){
            return false;
        }
      }
    }
  return true;
}

//checks if the boards are empty
bool ClassicMode::isEmpty(){
  for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if (board[i][j] == 'X') {
				return false;
			}
		}
	}
	return true;
}
