//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4

#include <iostream>
#include <fstream>
using namespace std;


class FileProcessor{
public:
  FileProcessor(); //default constructor
  ~FileProcessor(); //destructor

  //defines the method used in the cpp file for the file processor class
  void processFile(string input_file);
};
