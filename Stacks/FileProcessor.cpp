//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4

//implementation file
#include "FileProcessor.h"
#include "DNAComplement.h"

FileProcessor::FileProcessor(){} // constructor
FileProcessor::~FileProcessor(){} //destructor

//takes in an input file name and an output file name
//takes sentences from the input file, converts to tutnese amd outputs to a new file
void FileProcessor::processFile(string input_file) {
  DNAComplement d;
  ifstream file;
  file.open(input_file);
  string line;
  if(file.is_open()) {
    ofstream file_name("dnaoutput.txt");
    while (getline(file,line)) {
      //outputing the translated sentence to the output file
      file_name << d.print(line) << endl;
    }
    cout<<"output file created"<<endl;
  }
  else {
    //if input file does not exist
    cout<<"Unable to read file."<<endl;
  }
  file.close();

}
