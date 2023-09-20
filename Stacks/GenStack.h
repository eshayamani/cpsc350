//Esha Yamani
//2377310
//yamani@chapman.edu
//CPSC 350-03
//Assignment 4

#ifndef GENSTACK_H
#define GENSTACK_H

#include <iostream>
#include <string>
#include <exception>

using namespace std;

//implementation for listNode
template <class T>

class ListNode{
public:
  ListNode(); //constructor
  ListNode(int *d); //overloaded constructor
  ~ListNode(); //destructor
  ListNode *next; //pointer to next node
  ListNode *prev; //pointer to previous node
  T data; //data of any type
};

//default constructor
template<class T>
ListNode<T>::ListNode(){}

//overloaded constructor
template<class T>
ListNode<T>::ListNode(int *d){
  next = NULL;
  prev = NULL;
  data = d;
}

//desctructor
template<class T>
ListNode<T>::~ListNode(){}


//implementation for the stack
template<class T>
class GenStack{
public:
  GenStack(); //default constructor
  GenStack(int maxSize); //overloaded constructor
  ~GenStack(); //destructor

  //core functions
  void push(T data);
  T pop();

  //helper functions
  T peek(); //aka top
  bool isEmpty();
  bool isFull();
  T getSize();

private:
  T *myList;
  int mSize;
  int top;
};

//default constructor
template<class T>
GenStack<T>::GenStack(){
  mSize = 128;
  top = -1;
  myList = new T[mSize];
}

//overloaded constructor
template<class T>
GenStack<T>::GenStack(int maxSize){
  mSize = maxSize;
  top = -1;
  myList = new T[mSize];
}

//destructor
template<class T>
GenStack<T>::~GenStack(){
  delete myList;
}

//pushes an element into the stack
template<class T>
void GenStack<T>::push(T data){
  if(isFull()) {
    cout<<"Error! Stack is full"<<endl;
  }
  else {
    myList[++top] = data;
  }
}

//removes an element from the top of our stack
template<class T>
T GenStack<T>::pop(){
  if(isEmpty()) {
    cout<<"Error! Stack is empty"<<endl;
  }
  else {
    return myList[top--];
  }
}

//returns whatever is on the top of the stack without removing it
template<class T>
T GenStack<T>::peek(){
  if(isEmpty()) {
    cout<<"Error! Stack is empty"<<endl;
  }
  else {
    return myList[top];
  }
}

//returns true is the stack is full
template<class T>
bool GenStack<T>::isFull(){
  return(top == mSize-1);
}

//returns true if the stack is empty
template<class T>
bool GenStack<T>::isEmpty(){
  return(top == -1);
}

template<class T>
T GenStack<T>::getSize(){
  return mSize;
}


//implementation for the doubly linked list
template<class T>
class DoublyLinkedList{
private:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;

public:
  DoublyLinkedList();
  ~DoublyLinkedList();

  void insertFront(T *d);
  void insertBack(T *d);
  T* removeFront();
  T* removeBack();

  T* deletePos(T *pos);
  T* peek();
  T* find(T *d);
  void printList();
  bool isEmpty();
  unsigned int getSize();
};

//constructor
template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  size = 0;
  front = NULL;
  back = NULL;
}

//desctructor
template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  //iterate through the list
  while (front->next != front)
	{
		ListNode<T>* curr = front->next;
		curr->next->prev = front;
		front->next = curr->next;
		delete curr;
	}
	delete front;
}
//inserts a node to the front of the stack
template<class T>
void DoublyLinkedList<T>::insertFront(T *d){
  ListNode<T> *node = new ListNode<T>(d);

  if(isEmpty()) {
    //the list is currently empty
    back = node;
  }
  else {
    //not empty
    //the current front points back to the new node and new node points to the current front
    front->prev = node;
    node->next = front;
  }
  //new front is the node
  front = node;
  size++;
}

//inserts node to the end (can't really use for a stack but necessary for linked list)
template<class T>
void DoublyLinkedList<T>::insertBack(T *d){
  ListNode<T> *node = new ListNode<T>(d);

  if (isEmpty()) {
    //the list is currently empty
    front = node;
  }
  else {
    //not empty
    //the current back points to the new node and new node points back to the current back
    back->next = node;
    node->prev = back;
  }
  //new back is the node
  back = node;
  ++size;
}

//deletes node from the front
template<class T>
T* DoublyLinkedList<T>::removeFront(){
  T *temp = new ListNode<T>;
  if (isEmpty()) {
    cout<<"Error! List is empty"<<endl;
  }
  else {
    ListNode<T> *ft = front;

    if(front->next == NULL) { //contains a single element
      back = NULL;
    }
    else {
      front->next->prev = NULL;
    }
    front = front->next;
    temp = ft->data;
    ft->next = NULL;
    delete ft;
    size --;
  }
  return temp;
}

//deletes node from the back (cannot be done using the stack but necessary for linked list)
template<class T>
T* DoublyLinkedList<T>::removeBack(){
  T *temp = new ListNode<T>;
  if (isEmpty()) {
    cout<<"Error! List is empty"<<endl;
  }
  else {
    ListNode<T> *bk = back;

    if(front->next == NULL) { //contains only one element
      front = NULL;
    }
    else {
      back->prev->next = NULL;
    }
    back = back->prev;
    temp = bk->data;
    bk->prev = NULL;
    delete bk;
    size --;
  }
  return temp;
}

//deletes node at certain position (cannot be done using the stack but necessary for linked list)
template<class T>
T* DoublyLinkedList<T>::deletePos(T *pos) {
  if(isEmpty()) {
    cout<<"Error! List is empty"<<endl;
  }
  else {
    ListNode<T> *curr = front;

    while(curr->data != pos) {
      curr = curr->next;

      if(curr == NULL) {
        return NULL;
      }
      //now we have found the node to be removed

      if(curr == front){
        front = curr->next;
      }
      else {
        //not front so somewhere in between
        curr->prev->next = curr->next;
      }

      if(curr == back){
        back = curr->prev;
      }
      else{
        curr->next->back = curr->prev;
      }

      curr->next = NULL;
      curr->prev = NULL;
      size--;
    }
    return curr;
  }
}

//returns the value stored in the front node
template<class T>
T* DoublyLinkedList<T>::peek(){
  if(isEmpty()) {
    cout<<"Error! List is empty"<<endl;
  }
  else{
    return front->data;
  }
}

//returns the position of the given data
template<class T>
T* DoublyLinkedList<T>::find(T *d){
  if(isEmpty()) {
    cout<<"Error! List is empty"<<endl;
  }
  else{
    int index = 0;
    ListNode<T> *curr = front;

    while(curr != NULL){
      if(curr->data == d) {
        break;
      }
      else {
        curr = curr->next;
        index++;
      }
    }

    if(curr == NULL) { //this means we did not find the value
      index = -1;
    }
    return index;
  }
}

//prints out all the values in the linked list
template<class T>
void DoublyLinkedList<T>::printList() {
  ListNode<T> *curr = front;

  while(curr != NULL) {
    cout<<curr->data<<endl;
    curr = curr->next;
  }
}

//returns true if the list is empty
template<class T>
bool DoublyLinkedList<T>::isEmpty(){
  if(size==0){
    return true;
  }
  else {
    return false;
  }
}

//returns the size of the linked list
template<class T>
unsigned int DoublyLinkedList<T>::getSize() {
  return size;
}

#endif
