//header file for file processor class
#include <iostream>
#include <fstream>
#include "Translator.h"
using namespace std;


class FileProcessor{
public:
  FileProcessor(); //default constructor
  ~FileProcessor(); //destructor

  //defines the methods used in the cpp file for the file processor class
  void processEnglishFile(string file_name, string output_name);
  void processTutneseFile(string file_name, string output_name);
};
