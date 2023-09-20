
#include "MirrorMode.h"


//default constructor
MirrorMode::MirrorMode(){
  neighborCount = 0;
  row = 0;
  column = 0;
}

//overloaded constructor
MirrorMode::MirrorMode(int r, int c, char** b){
  row = r;
  column  = c;

  board = b;
  //makes the new board
  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}
}

//destructor
MirrorMode::~MirrorMode(){
  delete board;
  delete board2;
}

//Makes the new board
void MirrorMode::mirrorGame(){
  ClassicMode* c = new ClassicMode(row, column, board);
  //iterates thru the array
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighborCount = 0;
      neighborCount += c->countclassic(board,i,j,row,column);
      neighborCount += mirrorCount(board,i,j,row,column);
        //adds new cells to board 2
      getBoard(i, j, neighborCount);
    }
  }
}

//adds new cells to board 2
void MirrorMode::getBoard(int i, int j, int count){

    if(count == 3){// 3 neighbors = lives
      board2[i][j] = 'X';

    }
    else if(count == 4){// if four neighbors it dies
      board2[i][j] = '-';

    }
    else if(count == 1 || count == 0){//dies
      board2[i][j] = '-';

    }
    else if(count == 2){//stays the same
      board2[i][j] = board[i][j];
    }
    else{
      board2[i][j] = '-';//dead is dead
    }
}

//prints grid to terminal
char** MirrorMode::printBoard(){
  for(int i = 0; i < row; i++){
    cout << endl;
    for(int j = 0; j < column; j++){
     cout << board2[i][j] << "\t"; // \t is a tab so that there's some space b/w grid lives
    }
  }
  cout << endl;
  return board2;
}

//prints generations onto the output file
char** MirrorMode::printOutside(string file, int count){

  //opening the file
  ofstream outputFile;

  //appending it to the file, not overwritting
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
    return board2;
}

//checking if the grids  are equal
bool MirrorMode::isEqual(){
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
bool MirrorMode::isEmpty(){
  for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if (board[i][j] == 'X') {
				return false;
			}
		}
	}
	return true;
}
//figures out weather is corner and then calls the appropriate methods
int MirrorMode::mirrorCount(char **board, int i, int j, int row, int column) {
  int extra_count = 0;

  if (isCorner(board,i,j,row,column) == true) {
    extra_count += forCorner(board,i,j,row,column);
  }
  else {
    extra_count += forEdge(board,i,j,row,column);
  }
  return extra_count;
}
//checks to see if it is a corner
bool MirrorMode::isCorner(char **board, int i, int j, int row, int column) {
  bool corner = false;
  if (i==0) {
    if (j==0 || (j==column-1)) {
      corner = true;
    }
  }
  else if(i==row-1) {
    if ((j==0) || (j==column-1)) {
      corner = true;
    }
  }
  else {
    corner = false;
  }
  return corner;
}
//if corner then follows the rules of the game
int MirrorMode::forCorner(char **board, int i, int j, int row, int column){
  int extra_count = 0;
  if(board[i][j] == 'X'){
    extra_count += 3;
  }

  if(i==0) {
    if(j==0) {
      if(board[i][j+1] == 'X') {
        extra_count+=1;
      }
    }
    else if(j==column-1) {
      if(board[i][j-1] == 'X') {
        extra_count+=1;
      }
    }
    if(board[i+1][j] == 'X') {
      extra_count+=1;
    }
  }
  if(i==row-1) {
    if(j==0) {
      if(board[i][j+1] == 'X') {
        extra_count+=1;
      }
    }
    else if (j==column-1) {
      if(board[i][j-1] == 'X') {
        extra_count+=1;
      }
    }
    if(board[i-1][j] == 'X') {
      extra_count+=1;
    }
  }
  return extra_count;
}
//for edges then follows the rules of the game
int MirrorMode::forEdge(char **board, int i, int j,int row, int column){
  int extra_count = 0;
  if ((i==0) || (i==row-1)){
    for(int a = -1; a<2; a++) {
      if(board[i][j+a] == 'X') {
        extra_count += 1;
      }
    }
  }
  if((j==0) || (j==column-1)) {
    for(int b = -1; b<2; b++) {
      if(board[i+b][j] == 'X') {
        extra_count += 1;
      }
    }
  }
  return extra_count;
}
