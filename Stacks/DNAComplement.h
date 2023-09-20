//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4

#ifndef DNACOMP_H
#define DNACOMP_H

#include <iostream>
#include <string>
using namespace std;

class DNAComplement {
public:
  DNAComplement(); //default constructor
  ~DNAComplement(); //destructor

  //function to find the complement of the DNA sequence
  string complement(string s);
  //function to find the reverse complement of the DNA sequence
  string revComplement(string s);
  //function to print everything the way we want it
  string print(string s);
};

#endif
