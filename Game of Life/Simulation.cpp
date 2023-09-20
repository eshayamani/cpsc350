
#include "Simulation.h"

//default constructor
Simulation::Simulation(){

}
//destructor
Simulation::~Simulation(){

}

//starts the game + gives intro + makes first intitial grid
void Simulation::startgame(){
  bool run = true;

  while(run){
    //cute intro
    cout << "Welcome to the Game of life!!!!!"<<endl;
    while (true) {
      cout << "If you would like to generate a random map... press 1"<<endl;
      cout << "If you would like to input a map... press 2"<<endl;
      cin >> gearBox;
      if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Incorrect entry, try again: " << endl;
      }
      else if ((gearBox != 1) && (gearBox != 2)) {
        cout<<"Invalild input, please try again"<<endl;
        cout<<"Select option 1 or 2"<<endl;
        cin>>gearBox;
      }
      else {
        break;
      }
    }

    //random generation things
    if(gearBox == 1){
      cout << "Please enter the dimensions to create your random grid" << endl;


    while (true) {
      cout << "Enter rows: ";
      cin >> row;
      if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Incorrect entry, try again: " << endl;
      }
      else {
        break;
      }
    }
    while (true) {
      cout << "Enter columns: ";
      cin >> column;
      if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Incorrect entry, try again: " << endl;
      }
      else {
        break;
      }
    }

    while (true) {
      cout << "Enter a decimal for the population density (0 - 1): "<<endl;
      cout << "example: 20 percent is 0.20"<<endl;
      cin >> pop;
      if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Incorrect entry, try again: ";
      }
      else if (!(pop>0)||!(pop<1)) {
        cout << "ERROR: please pick a decimal between 0 and 1...";
        cout << "Please try again:"<<endl;
        cin >> pop;
      }
      else {
        break;
      }
    }

    // while(!(pop>0)||!(pop<1)){ //error handling for the given input density
    //   cout << "ERROR: please pick a decimal between 0 and 1...";
    //   cout << "Please try again:";
    //   cin >> pop;
    // }

    //makes the initial "template" board, uses a pointer, and then makes an instance of Grid
    Grid* g = new Grid(row, column, pop);
    board = g->randGen();

    break;

    //grid if given input file
    }
    else if(gearBox == 2){

      string temp = "";
      string line = "";

      cout << "Enter the file name: ";
      cin >> file;

      //opens the file
      ifstream infile(file);

      if(infile.fail()){ //error handling for when it doesnt exist
        cout << "ERROR: File does not exist. please try again:" << endl;
        continue;
      }

      while(getline(infile, line)){ //reads the generation from the file
        temp += line;
      }

      //the char is converted to the ASCII code thus it's subtracted by 48 to fix it
      row = int(temp[0]) - 48;
      column = int(temp[1]) - 48;

      //makes the initial "template" board, uses a pointer, and then makes an instance of Grid
      Grid* g = new Grid(row, column, temp);
      board = g->fileGen();

      break;

    }
    else{//error handling again basically
      cout << "Please enter 1 or 2: " << endl;
      run = true;
      continue;
    }
  }
}





//once board is made mode gets chosen through startmode() and gets printed out to terminal or outside file
void Simulation::startmode(){
  bool runMode = true;
  while(runMode){

    //Lets user choose what game mode they want for their game of life

    while (true) {
      cout<<"You have three different modes to choose from: \n1. Classic Mode \n2. Donut Mode \n3. Mirror Mode"<<endl;
      cout<<"Please enter the number of the mode you would like to run in: "<<endl;
      cin>>chosenMode;
      if (cin.fail()) {
        cin.clear();
        cin.ignore();
        cout << "Incorrect entry, try again: " << endl;
      }
      else if ((chosenMode!=1) && (chosenMode!=2) && (chosenMode!=3)) {
        cout<<"Invalid mode number, please try again"<<endl;
        cin>>chosenMode;
      }
      else {
        break;
      }
    }


    //asks user for weather they want life printed in terminal or output specified file
    cout << "Would you like the generations to be printed onto a outside file (y/n): ";
    cin >> outputFile;

    while ((outputFile != "y") && (outputFile != "n")) {
      cout<<"Invalid entry, please try again: "<<endl;
      cin>>outputFile;
    }
    //gets the output file the user wants
    if(outputFile == "y"){
      cout << "Enter output file name: ";
      cin >> inputFile;

    //asks user if they want automatic pauses or use keys to see each board
    }
    if(outputFile == "n"){
      cout << "Would you like auto-pauses or press the key 'y'?" << endl;
      cout << "type 'y' for auto-pauses: "<<endl;
      cout << "type 'n' for using the y key: "<<endl;
      cin >> pause;
    }

    int count = 0;

    //when classic mode gets chosen:
    if(chosenMode == 1){

        //for when outputting life onto a outside file
        if(outputFile == "y"){

            //opens text file
            ofstream output;

            //will override what is in the file currently
            //will keep all the data that will be written until the program is executed again
            output.open (inputFile);
            output << "Board 0" << endl;

            //iterates through the array
            for(int i = 0; i < row; i++){
                for(int j = 0; j < column; j++){
                 output << board[i][j] << "\t";
                }
                output << "\n";
              }
              output << endl;
              output.close();
              count++;

            //high number to ensure gets looped enough
            while(count < 100){

              //makes an object of class ClassicMode
              ClassicMode* c = new ClassicMode(row, column, board);

              //starts off the game with mode classic
              c->classicGame();

              //method to print data to output file
              board = c->printOutside(inputFile, count);
              count++;

              //checks if the boards keep repeating themselves
              if(c->isEqual()==true){
                  cout << "Grid is STAGNANT" << endl;
                  cout << "Program ended." << endl;
                  cout << "The output is in " << inputFile << endl;
                  break;

              }
              //checks if the grid is empty
              if(c->isEmpty()== true){
                  cout << "Grid is EMPTY" << endl;
                  cout << "Program ended." << endl;
                  cout << "The output is in " << inputFile << endl;
                  break;

              }
              else{
                continue;
              }
            }

      //prints data to the terminal
      }
      else if (outputFile == "n"){

          //automatic pauses for each board
          if(pause == "y"){
            while(count < 1000){

              //making an object of class ClassicMode
              ClassicMode* c = new ClassicMode(row, column, board);

              count++;

              //Entering simulation method
              c->classicGame();

              cout << endl;
              cout << "Board number: " << count << endl;
              cout << endl;

              //prints board to the terminal
              board = c->printBoard();



              //for loop to slow down the program, automatic pauses
              for(int i = 0; i < 1000; i++){
                for(int i = 0; i < 70000; i++){
                  slow+=i;
                }
                slow += i;
              }

              //checks if the boards keep repeating themselves
              if(c->isEqual()==true){
                  cout << "Grid is STAGNANT" << endl;
                  cout << "Program ended." << endl;
                  cout << "The output is in " << inputFile << endl;
                  break;
              }
              //checks if the grid is empty
              if(c->isEmpty()==true){
                  cout << "Grid is EMPTY" << endl;
                    cout << "Program ended." << endl;
                  cout << "The output is in " << inputFile << endl;
                  break;

              }
              else{
                continue;
              }
            }

          //Loop where the user presses the y key to see each board
          }
          else if(pause == "n"){

            //Ensuring enough loops
            while(count < 100){

              //making an object of class ClassicMode
              ClassicMode* c = new ClassicMode(row, column, board);

              count++;

              //Entering simulation method

              c->classicGame();

              cout << endl;
              cout << "Board number: " << count << endl;
              cout << endl;

              //prints board to the terminal
              board = c->printBoard();

              cout << "Press 'y' to continue: ";
              cin >> answer;

              //if the boards are equal . ends
              //checks if the boards keep repeating themselves
              if(c->isEqual()==true){

                  cout << "Grid is STAGNANT" << endl;
                  cout << "Program ended." << endl;
                  cout << "The output is in " << inputFile << endl;
                  break;
              }
              if(c->isEmpty()==true){

                  cout << "Board is EMPTY." << endl;
                  cout << "Program ended." << endl;
                  cout << "Press 'y' to quit: ";
                  cin >> answer;
                  if(answer == 'y'){
                  break;

              }
              else
              {
                continue;
              }
            }
          }
        }
      }

      runMode = false;

    //Donut Mode loop
    }
    else if(chosenMode == 2){

      //outputing boards to a file
      if(outputFile == "y"){

      ofstream output;

      //will override what is in the file currently; will keep all the data that will be written until the program is executed again
      output.open (inputFile);
      output << "Board 0" << endl;

      //iterating through the 2D array
      for(int i = 0; i < row; i++){
        for(int j = 0; j < column; j++){
            output << board[i][j] << "\t";
          }
          output << "\n";
        }
        output << endl;
        output.close();
        count++;

        //high number to ensure enough loops
        while(count < 100){

          //making an object of class ClassicMode
          DonutMode* d = new DonutMode(row, column, board);

          //Entering simulation method
          d->donutGame();

          //method to print data to file
          board = d->printOutside(inputFile, count);
          count++;

          //checks if the boards keep repeating themselves
          if(d->isEqual()==true){
              cout << "Grid is STAGNANT" << endl;
              cout << "Program ended." << endl;
              cout << "The output is in " << inputFile << endl;
              break;

          }
          //checks if the grid is empty
          if(d->isEmpty()==true){

              cout << "Grid is EMPTY" << endl;
                cout << "Program ended." << endl;
              cout << "The output is in " << inputFile << endl;
              break;
          }
          else{
            continue;
          }
        }

      //Loop that prints the terminal with automatic pauses
      }
      else if (outputFile == "n"){
        if(pause == "y"){

          //Ensures enough loops
          while(count < 1000){

            //making an object of class DonutcMode
            DonutMode* d = new DonutMode(row, column, board);

            count++;

            //Entering simulation method
            d->donutGame();

            cout << endl;
            cout << "Board number: " << count << endl;
            cout << endl;

            //prints board to the terminal
            board = d->printBoard();

            //for loop to slow down the program, automatic pauses
            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            //checks if the boards keep repeating themselves
            if(d->isEqual()==true){

                cout << "Grid is STAGNANT" << endl;
                cout << "Program ended." << endl;
                cout << "The output is in " << inputFile << endl;
                break;

            }
            //checks if the grid is empty
            if(d->isEmpty()==true){

                cout << "Grid is EMPTY" << endl;
                  cout << "Program ended." << endl;
                cout << "The output is in " << inputFile << endl;
                break;

            }
            else{
              continue;
            }
          }

      //Loop where the user presses the y key to see each board
      }
      else if(pause == "n"){

        //Ensures enough loops
        while(count < 100){

          //making an object of class DonutMode
          DonutMode* d = new DonutMode(row, column, board);

          count++;

          //Entering simulation method
          d->donutGame();

          cout << endl;
          cout << "Board number: " << count << endl;
          cout << endl;

          //prints board to the terminal
          board = d->printBoard();

          cout << "Press 'y' to continue: ";
          cin >> answer;

          //checks if the boards keep repeating themselves
          if(d->isEqual()==true){
              cout << "Grid is STAGNANT" << endl;
              cout << "Program ended." << endl;
              cout << "The output is in " << inputFile << endl;
              break;
          }
          //checks if the grid is empty
          if(d->isEmpty()==true){

              cout << "Grid is EMPTY" << endl;
                cout << "Program ended." << endl;
              cout << "The output is in " << inputFile << endl;
              break;

          }
            else{
              continue;
          }
        }
      }
    }


  runMode = false;

  //Mirror Mode loop
  }
  else if(chosenMode == 3){

    //outputing boards to a file
    if(outputFile == "y"){
        ofstream output;

        //will override what is in the file currently; will keep all the data that will be written until the program is executed again
        output.open (inputFile);
        output << "Board 0" << endl;

        //Makes Board 0
        for(int i = 0; i < row; i++){
          for(int j = 0; j < column; j++){
              output << board[i][j] << "\t";
          }
          output << "\n";
        }
        output << endl;
        output.close();
        count++;

        //high number to ensure enough loops
        while(count < 100){

          //making an object of class DonutMode
          MirrorMode* m = new MirrorMode(row, column, board);

          //Entering simulation method
          m->mirrorGame();

          //method to print data to file
          board = m->printOutside(inputFile, count);
          count++;

          //checks if the boards keep repeating themselves
          if(m->isEqual()==true){

              cout << "Grid is STAGNANT" << endl;
              cout << "Program ended." << endl;
              cout << "The output is in " << inputFile << endl;
              break;
          }
          //checks if the grid is empty
          if(m->isEmpty()==true){

              cout << "Grid is EMPTY" << endl;
                cout << "Program ended." << endl;
              cout << "The output is in " << inputFile << endl;
              break;
          }
          else{
            continue;
          }
        }

      //Loop that prints the terminal with automatic pauses
      }
      else if (outputFile == "n"){
        if(pause == "y"){
          while(count < 1000){

            //making an object of class MirrorMode
            MirrorMode* m = new MirrorMode(row, column, board);

            count++;

            //Entering simulation method
            m->mirrorGame();

            cout << endl;
            cout << "Board number: " << count << endl;
            cout << endl;

            //prints board to the terminal
            board = m->printBoard();

            //for loop to slow down the program, automatic pauses
            for(int i = 0; i < 1000; i++){
              for(int i = 0; i < 70000; i++){
                slow+=i;
              }
              slow += i;
            }

            //checks if the boards keep repeating themselves
            if(m->isEqual()==true){
                cout << "Grid is STAGNANT" << endl;
                cout << "Program ended." << endl;
                cout << "The output is in " << inputFile << endl;
                break;

            }
            //checks if the grid is empty
            if(m->isEmpty()==true){
                cout << "Grid is EMPTY" << endl;
                  cout << "Program ended." << endl;
                cout << "The output is in " << inputFile << endl;
                break;
            }
            else{
              continue;
            }
          }
        }
        else if(pause == "n"){

          //Ensures enough loops
          while(count < 100){

            //making an object of class MirrorMode
            MirrorMode* m = new MirrorMode(row, column, board);

            count++;

            //Entering simulation method
            m->mirrorGame();

            //prints board to the terminal

            cout << endl;
            cout << "Board number: " << count << endl;
            cout << endl;

            board = m->printBoard();

            cout << "Press 'y' to continue: ";
            cin >> answer;

            //checks if the boards keep repeating themselves
            if(m->isEqual()==true){
                cout << "Grid is STAGNANT" << endl;
                cout << "Program ended." << endl;
                cout << "The output is in " << inputFile << endl;
                break;

            }
            //checks if the grid is empty
            if(m->isEmpty()==true){
                cout << "Grid is EMPTY" << endl;
                cout << "Program ended." << endl;
                cout << "The output is in " << inputFile << endl;
                break;
            }
            else{
              continue;
            }
          }
        }
      }
      runMode = false;

      //else to catch in case put in wrong
      }
      else{
        cout << "ERROR: mode wasn't put in correctly..." << endl;
        runMode = true;
      }
    }
  }
