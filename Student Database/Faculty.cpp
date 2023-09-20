//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#include "Faculty.h"
#include "GenDoublyLinkedList.h"
#include <iostream>
#include <string>

using namespace std;

//default
Faculty::Faculty(){
  id = 0;
  name = "";
  level = "";
  department = "";
  advisees = new GenDoublyLinkedList<int>();
}

//overloaded
Faculty::Faculty(int i, string n, string l, string d, int a){
  id = i;
  name = n;
  level = l;
  department = d;
  advisees = new GenDoublyLinkedList<int>();
  advisees->insertBack(a);
}

//overloaded
Faculty::Faculty(int i, string n, string l, string d, GenDoublyLinkedList<int> *a){
  id = i;
  name = n;
  level = l;
  department = d;
  advisees = a;
}

//destructor aka trash
Faculty::~Faculty(){
  delete advisees;
}

//prints out the faculty info
void Faculty::getInfo(){
  cout << "\nID: " << id;
  cout << "\nName: " << name;
  cout << "\nLevel: " << level;
  cout << "\nDepartment: " << department;
  cout << "\nAdvisees ID: " << endl;
  advisees->printList();
}

//prints out faculty info as a string
string Faculty::getInfoS(){
  string temp = "";
  temp += to_string(id);
  temp += "\n" + name;
  temp += "\n" + level;
  temp += "\n" + department;
  temp += advisees->returnList();

  return temp;
}

//gets faculty ID
int Faculty::getFacultyID(){
  return id;
}

//gets the advisees of the advisor
GenDoublyLinkedList<int>* Faculty::getAdvisees(){
  return advisees;
}

//prints out the list of advissess of the advisor
void Faculty::printAdvisees(){
  advisees->printList();
}

//deletes an advisee
int Faculty::deleteAdvisee(int pos){
  advisees->deletePos(pos);
  if(advisees->isEmpty()){
    insertAdvisee(0);
  }
  return advisees->deletePos(pos);
}

//adds an advisee
void Faculty::insertAdvisee(int a){
  advisees->insertBack(a);
}


bool Faculty::operator<(int other){
  return(id < other);
}

bool Faculty::operator>(int other){
  return(id > other);
}

bool Faculty::operator==(int other){
  return(id == other);
  }

bool Faculty::operator!=(int other){
  return(id != other);
}
