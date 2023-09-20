
#include "DonutMode.h"




//default constructor
DonutMode::DonutMode(){
  neighborCount = 0;
  row = 0;
  column = 0;
}

//constructor
DonutMode::DonutMode(int r, int c, char** b){
  row = r;
  column  = c;

  board = b;
  board2 = new char *[row];
  	for(int i = 0; i < row ; i++){
  		   board2[i] = new char[column];
  	}
}

//destructor
DonutMode::~DonutMode(){
  delete board;
  delete board2;
}

//Makes the new board and calls back to classic
void DonutMode::donutGame(){
  ClassicMode* c = new ClassicMode(row, column, board);
  //iterates thru the array
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
      neighborCount = 0;
      neighborCount += c->countclassic(board,i,j,row,column);
      neighborCount += donutCount(board,i,j,row,column);
    //ADD THREE METHODS
    //adds new cells to board 2
      getBoard(i, j, neighborCount);
    }
  }
}

//adds the new cells to board 2
void DonutMode::getBoard(int i, int j, int count){

    if(count == 3){ // 3 neighbors = lives
      board2[i][j] = 'X';

    }
    else if(count == 4){ // if four neighbors it dies
      board2[i][j] = '-';

    }
    else if(count == 1 || count == 0){//dies
      board2[i][j] = '-';

    }
    else if(count == 2){// stays the same
      board2[i][j] = board[i][j];
    }
    else{
      board2[i][j] = '-';// remains dead
    }
}

//checks if corner then calls for its appropriate function
int DonutMode::donutCount(char **board, int i, int j, int row, int column) {
  int extra_count = 0;

  if (isCorner(board,i,j,row,column) == true) {
    extra_count += newCorner(board,i,j,row,column);
  }
  else {
    extra_count += newEdge(board,i,j,row,column);
  }
  return extra_count;
}
//checks if its a corner
bool DonutMode::isCorner(char **board, int i, int j, int row, int column) {
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
//rules for when its a corner to be added to board 2
int DonutMode::newCorner(char **board, int i, int j, int row, int column) {
  int extra_count = 0;
  if(i==0) {
    if(j==0) {
      if(board[row-1][column-1] == 'X') {
        extra_count+=1;
      }
      if(board[row-1][j] == 'X') {
        extra_count+=1;
      }
      if(board[row-1][j+1] == 'X') {
        extra_count+=1;
      }
      if(board[i][column-1] == 'X') {
        extra_count+=1;
      }
      if(board[i+1][column-1] == 'X') {
        extra_count+=1;
      }
    }
    else if(j==column-1) {
      if(board[row-1][0] == 'X') {
        extra_count+=1;
      }
      if(board[i][0] == 'X') {
        extra_count+=1;
      }
      if(board[i+1][0] == 'X') {
        extra_count+=1;
      }
      if(board[row-1][j-1] == 'X') {
        extra_count+=1;
      }
      if(board[row-1][j] == 'X') {
        extra_count+=1;
      }
    }
  }
  if(i==row-1) {
    if(j==0) {
      if(board[0][column-1] == 'X') {
        extra_count+=1;
      }
      if(board[0][j] == 'X') {
        extra_count+=1;
      }
      if(board[0][j+1] == 'X') {
        extra_count+=1;
      }
      if(board[i-1][column-1] == 'X') {
        extra_count+=1;
      }
      if(board[i][column-1] == 'X') {
        extra_count+=1;
      }
    }
    else if (j==column-1) {
      if(board[0][0] == 'X') {
        extra_count+=1;
      }
      if(board[0][j] == 'X') {
        extra_count+=1;
      }
      if(board[0][j-1] == 'X') {
        extra_count+=1;
      }
      if(board[i][0] == 'X') {
        extra_count+=1;
      }
      if(board[i-1][0] == 'X') {
        extra_count+=1;
      }
    }
  }
  return extra_count;
}
//rules again 
int DonutMode::newEdge(char **board, int i, int j,int row, int column) {
  int extra_count = 0;
  if (i==0) {
    for(int a = -1; a<2; a++) {
      if(board[row-1][j+a] == 'X') {
        extra_count += 1;
      }
    }
  }
  if (i==row-1) {
    for(int a = -1; a<2; a++) {
      if(board[0][j+a] == 'X') {
        extra_count += 1;
      }
    }
  }
  if (j==0) {
    for(int b = -1; b<2; b++) {
      if(board[i+b][column-1] == 'X') {
        extra_count += 1;
      }
    }
  }
  if (j==column-1) {
    for(int b = -1; b<2; b++) {
      if(board[i+b][0] == 'X') {
        extra_count += 1;
      }
    }
  }
  return extra_count;
}



//prints grid to terminal
char** DonutMode::printBoard(){

  for(int i = 0; i < row; i++){
    cout << endl;
    for(int j = 0; j < column; j++){
     cout << board2[i][j] << "\t";
    }
  }
  cout << endl;
  return board2;
}

//prints generations onto the output file
char** DonutMode::printOutside(string file, int count){

  //opening new file stream
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
    return board2;
}

//checks if boards are equal
bool DonutMode::isEqual(){
  for(int i = 0; i < row; i++){
    for(int j = 0; j < column; j++){
        if (board[i][j] != board2[i][j]){
            return false;
        }
      }
    }
  return true;
}


//checks if board is empty
bool DonutMode::isEmpty(){
  for (int i = 0; i < row; ++i) {
		for (int j = 0; j < column; ++j) {
			if (board[i][j] == 'X') {
				return false;
			}
		}
	}
	return true;
}
