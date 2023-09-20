//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4


#include "GenStack.h"
#include "RPNCalc.h"
#include "DNAComplement.h"
#include "FileProcessor.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
  std::string command = argv[1];
  if(argv[1] == NULL) {
    cout<<"Cannot run the code, please include necessary arguements"<<endl;
  }

  //if the input command is RPN we call the calculator function
  if(command.compare("RPN") == 0) {
    cout<<"You have chosen the RPN Calculator function"<<endl;
    RPNCalc rpn;
    string equation;
    cout<<"Please enter your equation: "<<endl;
    getline(cin,equation);
    int result = rpn.calculate(equation);
    cout<<"The result is: "<<result<<endl;
  }

  //if the input command is DNA we call the complement function
  else if(command.compare("DNA") == 0) {
    cout<<"You have chosen the DNA Complement function"<<endl;
    FileProcessor p;
    string input_file;
    string output_file;
    cout<<"Enter the input file name: "<<endl;
    cin>>input_file;
    p.processFile(input_file);
  }

  //if we get an invalid entry
  else {
    cout<<"Invalid entry so cannot run the code."<<endl;
    cout<<"Please choose between RPN or DNA"<<endl;
  }
}
