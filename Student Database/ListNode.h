//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#ifndef LISTNODE_H
#define LISTNODE_H

#include <iostream>

using namespace std;

template <class T>

class ListNode{
  public:
    T data;
    ListNode *next;
    ListNode *prev;


    ListNode();//default
    ListNode(T d); //overloaded
    ~ListNode();//destructor
};

//default
template <class T>
ListNode<T>::ListNode(){
  data = NULL;
  next = NULL;
  prev = NULL;
}

//overloaded
template <class T>
ListNode<T>::ListNode(T d){
  data = d;
  next = NULL;
  prev = NULL;
}

//destructor
template <class T>
ListNode<T>::~ListNode(){
  next = NULL;
  prev = NULL;
}

#endif
