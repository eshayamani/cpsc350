//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>

using namespace std;

template <class T>

class GenStack{
  public:
    GenStack(); //default
    GenStack(int maxSize); //overloaded
    ~GenStack(); //destructor

    void newStack(); //when stack is full make more
    void push(T d); //pushes element T on top of the stack
    void pushP (T* d); //pushes element T* on top of the stack
    T pop(); //removing top element from the top of the stack
    T* popP(); //removing top element pointer from the top of the stack
    T peek(); //returns but doesnt remove first element

    bool isFull(); //check if full
    bool isEmpty(); //checks if empty


    int size;
    int top;
    T *myArray; //initialize
};

//default
template<class T>
GenStack<T>::GenStack(){
  myArray = new T[128];
  size = 128;
  top = -1;
}

//overloaded
template<class T>
GenStack<T>::GenStack(int maxSize){
  myArray = new T[maxSize];
  size = maxSize;
  top = -1;
}

//destructor
template<class T>
GenStack<T>::~GenStack(){
  delete myArray;
}

//when full to make new stack
template<class T>
void GenStack<T>::newStack(){
  size = size + size;
  T *newStack;
	newStack = new T[size];
	for(int i = 0; i < (size/2); i++){
		newStack[i] = myArray[i];
	}
  myArray = newStack;
}
//push element T on top of the stack
template<class T>
void GenStack<T>::push(T d){
  if(isFull()){
    cout << "WARNING: Stack is full." << endl;
  }else{
    myArray[++top] = d;
  }
}

//push element T* on top of the stack (pointer)
template<class T>
void GenStack<T>::pushP(T *d){
  if(isFull()){
    cout << "WARNING: Stack is full" << endl;
  }else{
    myArray[++top] = *d;
  }
}

//removes the top
template<class T>
T GenStack<T>::pop(){
  if(isEmpty()){
    cout <<"ERROR: Stack is empty" << endl;
    return 0;
  }
  else{
    return myArray[top--];
  }
}

//removes top pointer
template<class T>
T* GenStack<T>::popP(){
  if(isEmpty()){
    cout <<"ERROR:Stack is empty" << endl;
    return 0;
  }else{
    T* temp = &myArray[top];
    return temp;
  }
}

//returns top without deleting
template<class T>
T GenStack<T>::peek(){
  if(isEmpty()){
    cout <<"ERROR:Stack is empty" << endl;
  }else{
    return myArray[top];
  }
}

//checks if full
template<class T>
bool GenStack<T>::isFull(){
  return(top == size-1);
}

//checks if empty
template<class T>
bool GenStack<T>::isEmpty(){
  return (top == -1);
}

#endif
