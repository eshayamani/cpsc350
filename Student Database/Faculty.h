//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#ifndef FACULTY_H
#define FACULTY_H

#include <iostream>
#include "GenDoublyLinkedList.h"
using namespace std;

class Faculty{
  public:
      Faculty(); //default
      Faculty(int i, string n, string l, string d, int a); //overloaded
      Faculty(int i, string n, string l, string d, GenDoublyLinkedList<int> *a); //overloaded
      ~Faculty(); //destructor


      void printAdvisees(); //prints advisee ID#'s
      void insertAdvisee(int a); //inserts an advisee to the list
      int deleteAdvisee(int pos); //deletes the advisee at certain pos
      //void setStudentAdvisee(int s);


      //GETTERS:

      void getInfo(); //gets and prints out faculty info
      string getInfoS(); //gets and prints faculty info as string
      int getFacultyID(); //gets faculty ID #
      GenDoublyLinkedList<int>* getAdvisees(); //returns the advisees table

      bool operator<(int other);
      bool operator>(int other);
      bool operator==(int other);
      bool operator!=(int other);

      string name;
      string level;
      string department;
      int id;
      GenDoublyLinkedList<int> *advisees;

};

#endif
