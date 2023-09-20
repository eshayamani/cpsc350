//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#ifndef GENDOUBLYLINKEDLIST_H
#define GENDOUBLYLINKEDLIST_H

#include "ListNode.h"
#include <iostream>
#include <string>

using namespace std;

template <class T>

class GenDoublyLinkedList{
  private:
    ListNode<T> *front; //pointer to front
    ListNode<T> *back; //pointer to back
    unsigned int size; //size of list

  public:
    GenDoublyLinkedList(); //constructor
    ~GenDoublyLinkedList(); //destructor

    void insertFront(T d); //inserts to front
    void insertBack(T d); //inserts to back
    T removeFront(); //removes front
    T removeBack(); //removes back
    T peek(); //shows what the front is without deleting it
    T deletePos(T pos); //delete @ certain node
    int find(T d); //finds and returns node @ pos
    bool contains(T d); //returns true if found

    bool isEmpty(); //checks if empty
    void printList(); //prints list
    string returnList(); //returns list
    unsigned int getSize(); //returns the size of list
};

//default
template<class T>
GenDoublyLinkedList<T>::GenDoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

//destructor
template<class T>
GenDoublyLinkedList<T>::~GenDoublyLinkedList(){
  //iterates thru list
  while (front->next != front)
	{
		ListNode<T>* curr = front->next;
		curr->next->prev = front;
		front->next = curr->next;
		delete curr;
	}
	delete front;
}


//inserts to front
template<class T>
void GenDoublyLinkedList<T>::insertFront(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    /// when empty
    back = node;
  }else{
    //not empty
    front->prev = node;
    node->next = front;
  }
  front = node;
  size++;
}

//removes the node from front
template<class T>
T GenDoublyLinkedList<T>::removeFront(){
  T temp;
  if(isEmpty()){
    cout << "ERROR: List is empty" << endl;
  }else{
    ListNode<T> *ft = front;

    if(front->next == NULL){
      //when one thing in tree
      back = NULL;
    }else{

      front->next->prev = NULL;
    }
    front = front->next;
    temp = ft->data;
    ft->next = NULL;
    delete ft;
    size--;
  }
  return temp;
}

//returns front without deleting it
template<class T>
T GenDoublyLinkedList<T>::peek(){
  if(isEmpty()){
    cout << "ERROR: List is empty" << endl;
  }else{
    return front->data;
  }
}

//inserts to back
template<class T>
void GenDoublyLinkedList<T>::insertBack(T d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()){
    //when empty
    front = node;
  }else{
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

//removes the back
template<class T>
T GenDoublyLinkedList<T>::removeBack(){
  T *temp = new ListNode<T>;
  if(isEmpty()){
    cout << "ERROR: List is empty" << endl;
  }else{
    ListNode<T> *bk = back;

    if(front->next == NULL){
      //when one thing
      front = NULL;
    }else{
      back->prev->next = NULL;
    }
    back = back->prev;
    temp = bk->data;
    bk->prev = NULL;
    delete bk;
    size--;

  }
  return temp;
}

//deletes @ certain pos
template<class T>
T GenDoublyLinkedList<T>::deletePos(T d){
  if(isEmpty()){
    cout << "ERROR: List is empty" << endl;
    return 0;
  }
  else{
    ListNode<T> *curr = front;

    if(curr->data == d){
      front = curr->next;
      size--;
    }

    while(curr->data != d){
      curr = curr->next;

      if(curr == NULL){
        return -1;
      }
      if(curr == front){
        front = curr->next;
      }
      else{
      curr->prev->next = curr->next;

      }if(curr == back){
        back = curr->prev;
      }else{
        curr->next->prev = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      size--;

    }
    return curr->data;
  }
}

//finds pos of node
template<class T>
int GenDoublyLinkedList<T>::find(T d){
  if(isEmpty()){
    cout << "ERROR: List is empty." << endl;
  }else{
    int idx = 0;
    ListNode<T> *curr = front;

    while(curr != NULL){
      if(curr->data == d){
        break;
      }else{
        curr = curr->next;
        idx++;
      }
    }

    if(curr == NULL){ //when value not found
      idx = -1;
    }
    return idx;
  }
}

//retursn true if found
template<class T>
bool GenDoublyLinkedList<T>::contains(T d){
  bool isThere = true;
  if(isEmpty()){
    isThere = false;
  }

  ListNode<T> *curr = front;
  while(curr != NULL) {
    if(curr->data != d) {
      curr = curr->next;
    }
    else{
      isThere = false;
    }
  }
  return isThere;
}

//checks if empty
template<class T>
bool GenDoublyLinkedList<T>::isEmpty(){
  if(size == 0){
    return true;
  }
  else{
    return false;
  }
}

//prints the list
template<class T>
void GenDoublyLinkedList<T>::printList(){
  ListNode<T> *curr = front;

  while(curr != NULL){
    cout << curr->data << endl;
    curr = curr->next;
  }
  if(curr == NULL){
  }
}

//returns string of ints in the tree
template <class T>
string GenDoublyLinkedList<T>::returnList(){
  ListNode<T> *curr = front;
  string temp = "\n";// new line

  while(curr != NULL){
    temp += to_string(curr->data);
    curr = curr->next;

    if(curr != NULL){
      temp += " ";
    }
  }
  return temp;
}

//returns size of tree
template<class T>
unsigned int GenDoublyLinkedList<T>::getSize(){
  return size;
}

#endif
