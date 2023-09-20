//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student{
  public:
      Student(); //default
      Student(int i, string n, string l, string m, double g, int f); //overloaded
      ~Student(); //destructor

      //GETTERS AND SETTERS
      void getInfo(); //prints student info rather than ton of getters
      string getInfoS(); //prints student info as string rather than ton of getters
      int getFacultyID(); //gets the faculty Advisor's ID #
      int getStudentID(); //gets student ID #
      void setFacultyAdvisor(int f); //sets the faculty Advisor to the student

      bool operator<(int other);
      bool operator>(int other);
      bool operator==(int other);
      bool operator!=(int other);



      int id;
      string name;
      string levelField;
      string major;
      double gpa;
      int facultyAdvisor;



};
#endif
