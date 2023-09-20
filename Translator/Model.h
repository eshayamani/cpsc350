//header file for model class
#include <iostream>
using namespace std;

class Model{
public:
  Model(); //default constructor
  ~Model(); //destructor

  //defining the methods to be used in cpp file for model class
  string translateSingleCharacter(char letter);
  string translateDoubleCharacter(char letter);
  string translateTutnese(string tut);
};
