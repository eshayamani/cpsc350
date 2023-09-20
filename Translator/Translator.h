//header file for translator class
#include <iostream>
#include <string>
//https://www.tutorialspoint.com/isalpha-and-isdigit-in-c-cplusplus
#include <ctype.h>
#include <stdio.h>
#include "Model.h"
using namespace std;

class Translator{
public:
  Translator(); //default constructor
  ~Translator(); //destructor

  //defining the methods used in the cpp file for translator class
  string translateEnglishWord(string word);
  string translateEnglishSentence(string line);
  string translateTutneseWord(string tut_word);
  string translateTutneseSentence(string tut_line);
};
