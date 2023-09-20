//implementation file
#include "FileProcessor.h"

FileProcessor :: FileProcessor(){} // constructor
FileProcessor :: ~FileProcessor(){} //destructor

//takes in an input file name and an output file name
//takes sentences from the input file, converts to tutnese from english
//outputs to a new file
//http://www.cplusplus.com/forum/beginner/12247/
void FileProcessor :: processEnglishFile(string input_file, string output_file) {
  Translator s;
  ifstream file;
  ofstream file_name(output_file);
  file.open(input_file);
  string line;
  if(file.is_open()) {
    while (getline(file,line)) {
      //outputing the translated sentence to the output file
      file_name << s.translateEnglishSentence(line) << endl;
    }
  }
  else {
    //if input file does not exist
    cout<<"Unable to read file."<<endl;
  }
  file.close();
}

//takes in an input file name and an output file name
//takes sentences from the input file, converts to english from tutnese
//outputs to a new file
void FileProcessor :: processTutneseFile(string input_file, string output_file) {
  Translator s;
  ifstream file;
  ofstream file_name(output_file);
  file.open(input_file);
  string line;
  if(file.is_open()) {
    while (getline(file,line)) {
      //outputing the translated sentence to the output file
      file_name << s.translateTutneseSentence(line) << endl;
    }
  }
  else {
    //if input file does not exist
    cout<<"Unable to read file."<<endl;
  }
  file.close();
}
