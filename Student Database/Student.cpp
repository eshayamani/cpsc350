//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

//default
Student::Student(){
  id = 0;
  name = "";
  levelField = "";
  major = "";
  gpa = 0.0;
  facultyAdvisor = 0;
}

//overloaded
Student::Student(int i, string n, string l, string m, double g, int f){
  id = i;
  name = n;
  levelField = l;
  major = m;
  gpa = g;
  facultyAdvisor = f;
}

//destructor
Student::~Student(){
}

//prints student info rather than a ton of getters
void Student::getInfo(){
  cout << "\nID: " << id <<endl;
  cout << "Name: " << name << endl;
  cout << "Level Field: " << levelField <<endl;
  cout << "Major: " << major<<endl;
  cout << "GPA: " << gpa<< endl;
  cout << "Faculty Advisor ID: " << facultyAdvisor<<endl;
}

//prints student info as a string rather than ton og getters
string Student::getInfoS(){
  string temp = "";
  temp += to_string(id);
  temp += "\n" + name;
  temp += "\n" + levelField;
  temp += "\n" + major;
  temp += "\n" + to_string(gpa); //turns into string
  temp += "\n" + to_string(facultyAdvisor);

  return temp;
}

//returns faculty advisor's ID #
int Student::getFacultyID(){
  return facultyAdvisor;
}

//returns student ID #
int Student::getStudentID(){
  return id;
}

//sets the facultyAdvisor to the student f
void Student::setFacultyAdvisor(int f){
  facultyAdvisor = f;
}

bool Student::operator<(int other){
  return(id < other);
}

bool Student::operator>(int other){
  return(id > other);
}

bool Student::operator==(int other){
  return(id == other);
  }

bool Student::operator!=(int other){
  return(id != other);
}
