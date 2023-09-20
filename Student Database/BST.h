//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#ifndef BST_H
#define BST_H

#include "TreeNode.h"
#include "Student.h"
#include "Faculty.h"
#include <iostream>
#include <fstream>

using namespace std;

template <class T>

class BST{
  private:
    TreeNode<T> *root;

  public:
    BST(); //default
    ~BST(); //destructor

    void printTree(); //prints out everything in tree
    TreeNode<T>* getMax(); //get the tree node of the biggest value
    TreeNode<T>* getMin(); //get the tree node of the smallest value
    void getNodeInfo(TreeNode<T>* node); //prints out info of node  ************ might not need this
    void insert(T *value); //inserts tree node to the  binary tree
    T* search(int key); //searching for the node with the int value

    bool deleteNode(int key); //deleting the node given the key
    TreeNode<T>* getSuccessor(TreeNode<T> *d); //getting the successor of the node
    void TSerialization(TreeNode<T>* node, string f); //outs data of tree to the file ************* might not need this
    void RSerialization(string f); //data of the root node to file
    bool isEmpty(); //checks if the tree is empty

  };




  //default constructor
  template <class T>
  BST<T>::BST(){
    root = NULL;
  }

  //destructor
  template <class T>
  BST<T>::~BST(){
    delete root;
  }

  //prints out node info
  template <class T>
  void BST<T>::getNodeInfo(TreeNode<T>* node){

    if(node == NULL){
      return;
    }
    //inorder traversal :)
    getNodeInfo(node->left);
    node->data->getInfo();
    cout << endl;
    getNodeInfo(node->right);
  }


  //prints everythinging in tree
  template <class T>
  void BST<T>::printTree(){
    getNodeInfo(root);
  }

  //get the biggest node
  template <class T>
  TreeNode<T>* BST<T>::getMax(){
    TreeNode<T> *current = root;

    if(root == NULL){ //when empty
      return NULL;
    }

    while(current->right != NULL){
      current = current->right;
    }
    return current;
  }

  //get the smallest node (opposite of get max)
  template <class T>
  TreeNode<T>* BST<T>::getMin(){
    TreeNode<T> *current = root;

    if(root == NULL){ //when empty
      return NULL;
    }

    while(current->left != NULL){
      current = current->left;
    }
    return current;
  }

  //to insert into tree
  template <class T>
  void BST<T>::insert(T *value){
    TreeNode<T> *node = new TreeNode<T>(value);

    if(root == NULL){
      root = node;
    }

    else{
      TreeNode<T> *current = root;
      TreeNode<T> *parent = NULL;

      while(true){
        parent = current;

        if(value < current->data){
          current = current->left;

          if(current == NULL){
            //where to insert
            parent->left = node;
            break;
          }


        }else{
          current = current->right;

          if(current == NULL){
            //insert here
            parent->right = node;
            break;
          }
        }
      }
    }
  }

  //to search within a tree
  template <class T>
  T* BST<T>::search(int value){

    bool isThere = true;
    if(isEmpty()){
      isThere = false;
    }

    TreeNode<T> *current = root;
    if (isThere == true) {
      while (*(current->data) != value) {
        if (*(current->data) > value) {
          current = current->left;
        } else {
          current = current->right;
        }
        if (current == NULL) {
          isThere = false;
          break;
        }
      }
    }

    if (!isThere) {
      return NULL;
    }

    TreeNode<T> *curr2 = root;
    while (*(curr2->data) != value) {
      if (*(curr2->data) > value) {
        curr2 = curr2->left;
      } else {
        curr2 = curr2->right;
      }
    }

    return (curr2->data);

  }

  //deleting a node given the key
  template <class T>
  bool BST<T>::deleteNode(int k){
    if(root == NULL){
      cout << "ERROR: the BST is empty!" << endl;
    }

    TreeNode<T> *current = root;
    TreeNode<T> *parent = root;
    bool isLeft = true;

    while(*current->data != k){
      parent = current;
      if(*current->data > k){
        isLeft = true;
        current = current->left;
      }
      else{
        isLeft = false;
        current = current->right;
      }
      if(current == NULL){ //value wasnt found
        cout << "ERROR: not able to find your value" << endl;
        return false;
      }
    }

    //WHEN NO CHILDREN::

    if(current->left == NULL && current->right == NULL){
      if(current == root){
        root = NULL;
      }
      else if (isLeft){
        parent->left = NULL;
      }
      else{
        parent->right = NULL;
      }
    }

    //ONE CHILD: (left or right)
    else if(current->right == NULL){ //left
      //check if root
      if(current == root){
        root = current->left;
      }
      else if(isLeft){
        parent->left = current->left;
      }
      else{
        parent->right = current->left;
      }
    }

    else if(current->left == NULL){ //right
      //check if root
      if(current == root){
        root = current->right;
      }
      else if(isLeft){
        parent->left = current->right;
      }
      else{
        parent->right = current->right;
      }
    }

    else{
      //2 children smh
      TreeNode<T> *successor = getSuccessor(current);

      if(current == root){
        root = successor;
      }
      else if(isLeft){
        parent->left = successor;
      }
      else{
        parent->right = successor;
      }
      successor->left = current->left;
      current->left = NULL;
      current->right = NULL;
    }
    delete current;
    return true;
  }

  //get successor
  template <class T>
  TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d){ //d is the node to be deleted
    TreeNode<T> *current = d->right;
    TreeNode<T> *sp = d;
    TreeNode<T> *successor = d;

    while(current != NULL){
      //traverse through the tree to find successor
      sp = successor;
      successor = current;
      current = current->left;
    }
    if(successor != d->right){
      sp->left = successor->right;
      successor->right = d->right;
    }
    return successor;
  }

  //serialization of the entire tree
  template<class T>
  void BST<T>::TSerialization(TreeNode<T>* node, string f){
    ofstream output;
    output.open(f, fstream::app);

    bool loop = true;

    if(node == NULL){
      return;
    }

    output << node->data->getInfoS() << endl;

    TSerialization(node->left, f);

    TSerialization(node->right, f);


  }

  //serialization of a tree node
  template <class T>
  void BST<T>::RSerialization(string f){

    ofstream output;
    output.open(f);

    if(root == NULL){
      cout << "ERROR: BST is empty. Please try again" << endl;
    }

    else{
      output << root->data->getInfoS() << endl;
    }
    if(root->left != NULL){
      TSerialization(root->left, f);
    }
    if(root->right != NULL){
      TSerialization(root->right, f);
    }
  }


  //when tree is empty
  template <class T>
  bool BST<T>::isEmpty(){
    if(root == NULL){
      return true;
    }else{
      return false;
    }
  }

#endif
