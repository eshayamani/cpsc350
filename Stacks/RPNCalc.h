//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4
#ifndef RPNCALC_H
#define RPNCALC_H

#include "GenStack.h"
#include <string>
#include <iostream>
using namespace std;

class RPNCalc {
public:
  RPNCalc(); //constructor
  ~RPNCalc(); //destructor

  int calculate(string s);
};

#endif
