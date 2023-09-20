//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4

//implementation file
#include "DNAComplement.h"
#include "FileProcessor.h"
#include "GenStack.h"

DNAComplement::DNAComplement(){} //constructor
DNAComplement::~DNAComplement(){} //desctructor


//takes in a string and replaces all nucleotides with their complements
string DNAComplement::complement(string s){
  int valid = 0;
  for(int i = 0; i<s.length(); i++) {
    if(s[i] == 'A'){
      s[i] = 'T';
    }
    else if(s[i] == 'T'){
      s[i] = 'A';
    }
    else if(s[i] == 'C'){
      s[i] = 'G';
    }
    else if(s[i] == 'G'){
      s[i] = 'C';
    }
    else {
      s = "invalid entry";
    }
  }
  return s;
}

//takes in a string, uses complement function to find the complement
//then uses a new stack to reverse the order
string DNAComplement::revComplement(string s){
  GenStack<char> myStack;
  string revComp;
  string output;
  s = complement(s);
  if (s == "invalid entry") {
    revComp = "invalid entry";
  }
  else {
    for(int i=0; i<s.length(); i++){
      myStack.push(s[i]);
    }
    for(int i=0; i<s.length(); i++){
      revComp += myStack.pop();
    }
  }
  return revComp;
}

//a print function to format the complements onto the output file
string DNAComplement::print(string s){
  string output = "Sequence: " + s + "\nComplement: " +complement(s) + "\nReverse Complement: " + revComplement(s) + "\n";
  return output;
}
