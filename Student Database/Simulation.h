#ifndef SIMULATION_H
#define SIMULATION_H
//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "GenStack.h"
#include <iostream>

using namespace std;

class Simulation{
  public:
    Simulation(); //default
    Simulation(string file, string file2); //overloaded
    ~Simulation(); //destructor

    bool studentExists(int studentID);//checks if student exists in BST
    bool facultyExists(int facultyID);// checksif faculty exists in BST

    void runSimulation(); //runs simulation



  private:
    //BST's
    BST<Student> *masterStudent;
    BST<Faculty> *masterFaculty;

    //stacks for rollback
    GenStack<Student> *rollBackStudent;
    GenStack<Faculty> *rollBackFaculty;
    GenStack<int> *rollBackNum;

    int option;
    int studentID;
    int facultyID;
    bool stud;

    int undo;
    Student s;
};

#endif
