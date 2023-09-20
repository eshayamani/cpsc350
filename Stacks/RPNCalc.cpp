//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4

//implementation file
#include "RPNCalc.h"
#include "GenStack.h"
#include <stdio.h>
#include <stdlib.h>

RPNCalc::RPNCalc(){} //constructor
RPNCalc::~RPNCalc(){} //desctructor

//takes in a string containing the equation
//once it identifies an operand it pops the last two numbers given and performs the operation
//pushes the result back in and continues with the equation
int RPNCalc::calculate(string s){
  int a = 0;
  int b = 0;
  int num = 0;
  string op = "";
  GenStack<int> myStack;

  //to skip over any empty spaces in the equation
  for(int i=0; i<s.length(); i++){
    if(s[i] == ' '){
      i++;
    }
    //if the value is not an operand we are pusjing to the stack
    if((s[i] != '+') && (s[i] != '-') && (s[i] != '*') && (s[i] != '/') && (s[i] != '%')){
      myStack.push((s[i])-48); //to deal with ascii value
    }
    //we reach here when we identify an operand and need to perform an operation
    else {
      b = myStack.pop();
      a = myStack.pop();
      op = s[i];
      //checking for each of the five operands
      if(op == "+"){
        num = a+b;
      }
      else if(op == "-"){
        num = a-b;
      }
      else if(op == "*"){
        num = a*b;
      }
      else if(op == "/"){
        num = a/b;
      }
      else if(op == "%"){
        num = a%b;
      }
      else {
        cout<<"invalid operation"<<endl;
        break;
      }
      myStack.push(num);
    }
  }
  //checking if all values are used and that the equation doesn't have any unused numbers
  //making sure stack only contains the single final output
  int curr = myStack.pop();
  if(myStack.isEmpty()) {
    myStack.push(curr);
  }
  else{
    cout<<"Invalid equation, result set to default value of 0"<<endl;
    myStack.push(0);
  }
  return myStack.peek();
}
