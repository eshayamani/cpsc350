//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>
using namespace std;

template <class T>

class TreeNode{
  public:
    TreeNode(); //default
    TreeNode(T *d); //overloaded
    ~TreeNode(); //destructor


    T *data;
    TreeNode *left;
    TreeNode *right;
};

//default
template <class T>
TreeNode<T>::TreeNode(){
  data = NULL;
  left = NULL;
  right = NULL;
}

//overloaded
template <class T>
TreeNode<T>::TreeNode(T *d){
  data = d;
  left = NULL;
  right = NULL;
}

//destructor
template <class T>
TreeNode<T>::~TreeNode(){
  left = NULL;
  right = NULL;
}

#endif
