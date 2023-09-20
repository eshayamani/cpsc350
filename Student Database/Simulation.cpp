//Esha Yamani and Katherine Monroy
//2377310 2368029
//yamani@chapman.edu kmonroy@chapman.edu
//CPSC 350-03
//Assignment 6

#include "Simulation.h"
#include "GenStack.h"

#include <iostream>
#include <fstream>

using namespace std;

//default
Simulation::Simulation(){
  //defaults and intializes everything
  masterFaculty = new BST<Faculty>();
  masterStudent = new BST<Student>();
  rollBackStudent = new GenStack<Student>();
  rollBackFaculty = new GenStack<Faculty>();
  rollBackNum = new GenStack<int>();
  option = 0;
  studentID = 0;
  facultyID = 0;
  stud = true;
  undo = 0;
}

//error handling when the student doesnt exist in the BST
bool Simulation::studentExists(int studentID){
  if(masterStudent->isEmpty() == true) {
    cout << "ERROR: BST is empty!"<<endl;
    return false;
  }
  else if(masterStudent->search(studentID) == NULL){
    cout << "ERROR: Student ID not found/doesn't exist!!!" << endl;
    return false;
  }
  return true;
}

//error handling for when faculty doesnt exist in the BST
bool Simulation::facultyExists(int facultyID){
  if(masterFaculty->isEmpty() == true) {
    cout << "ERROR: BST is empty!"<<endl;
    return false;
  }
  else if (masterFaculty->search(facultyID) == NULL){
    cout << "ERROR: Faculty ID not found/doesn't exist!!!" << endl;
    return false;
  }
  return true;
}



//overloaded
Simulation::Simulation(string studentFile, string facultyFile){
  //intialize BSTs
  masterFaculty = new BST<Faculty>();
  masterStudent = new BST<Student>();

  int step = 0;
  string line = "";

  //to read file
  ifstream infile(studentFile);

  int id = 0;
  int advisor = 0;
  int advisee = 0;
  string name = "";
  string level = "";
  string major = "";
  string department = "";
  double gpa = 0.0;


  //loops to add stuff to the BST from the given file
  while(getline(infile, line)){
    if(step == 0){ // same reading file method as last assignment
      id = stoi(line); // gets ID
      step++;
      continue;
    }
    if(step == 1){ // gets student name
      name = line;
      step++;
      continue;
    }
    if(step == 2){ // gets level
      level = line;
      step++;
      continue;
    }
    if(step == 3){
      major = line; // gets major
      step++;
      continue;
    }
    if(step == 4){
      gpa = stoi(line);// gets GPA
      step++;
      continue;
    }
    if(step == 5){
      advisor = stoi(line); //gets advisor
      step++;
    }
    if(step == 6){ // creates student and inserts to the BST
      Student *s = new Student(id, name, level, major, gpa, advisor);
      masterStudent->insert(s);
      step = 0;
    }
  }

  //adds things from faculty file to BST
  ifstream infacultyFile(facultyFile);

  while(getline(infacultyFile, line)){ // again loop to read through the file
    if(step == 0){
      id = stoi(line);// gets ID
      step++;
      continue;
    }
    if(step == 1){
      name = line;//gets name
      step++;
      continue;
    }
    if(step == 2){
      level = line;// gets level
      step++;
      continue;
    }
    if(step == 3){
      department = line; // gets department
      step++;
      continue;
    }
    if(step == 4){
      Faculty *f = NULL; // to get adviseeeees of advisor
      string s;
      int step2 = 0;
      //when theres multiple ppl under an advisor
      for(char c : line){ // gives a warning but i think i just need to update terminal or something.
        if(c != ' '){
          s += c;
        }
        else if(c == ' '){
          advisee = stoi(s);
          if(step2 == 0){
            f = new Faculty(id, name, level, department, advisee);
            masterFaculty->insert(f); // makes faculty and adds them to the faculty BST
            step2++;
            s = "";
            continue;
          }
          else{
            f->insertAdvisee(advisee); // inserts corresponding advisees
            s = "";
            continue;
          }
        }
      }
      advisee = stoi(s);
      if(step2 != 0){
        f->insertAdvisee(advisee);// inserts corresponding advisees
      }

      if(step2 == 0){
        f = new Faculty(id, name, level, department, advisee); // creates faculty and inserts them to BST
        masterFaculty->insert(f);
      }
      step = 0;
    }
  }
  //rollback!
  rollBackStudent = new GenStack<Student>(); // makes stack for student
  rollBackFaculty = new GenStack<Faculty>();// makes tsack for faculty
  rollBackNum = new GenStack<int>(); // genstack

  option = 0;
  studentID = 0;
  facultyID = 0;
  stud = true;
  undo = 0;
}

//destructor
Simulation::~Simulation(){ // takes out trash
  delete masterFaculty;
  delete masterStudent;
  delete rollBackFaculty;
  delete rollBackStudent;
}

//simulation runs the whole program basically ( HUGE LOOOOP)
void Simulation::runSimulation(){
  int id = 0;
  int facultyID = 0;
  int studentID = 0;
  int advisor = 0;
  int ad = 0; //
  int advisee = 0;
  string name = "";//
  string level = "";
  string major = "";
  string department = "";
  double gpa = 0.0;
  bool loop = true; // just keep the loop going

  //main menu
  while(loop){ // same vibes as last assignment
    cout << "\n═══════════════  𝑊𝐸𝐿𝐶𝑂𝑀𝐸 𝑇𝑂 𝑇𝐻𝐸 𝑆𝑇𝑈𝐷𝐸𝑁𝑇 𝐷𝐴𝑇𝐴𝐵𝐴𝑆𝐸  ═══════════════"<< endl;
    cout << "1. Print all students and their information (sorted by ascending id #" << endl;
    cout << "2. Print all faculty and their information (sorted by ascending id #)" << endl;
    cout << "3. Find and display student information given the students id" << endl;
    cout << "4. Find and display faculty information given the faculty id" << endl;
    cout << "5. Given a student’s id, print the name and info of their faculty advisor" << endl;
    cout << "6. Given a faculty id, print ALL the names and info of his/her advisees" << endl;
    cout << "7. Add a new student" << endl;
    cout << "8. Delete a student given the id" << endl;
    cout << "9. Add a new faculty member" << endl;
    cout << "10. Delete a faculty member given the id" << endl;
    cout << "11. Change a student’s advisor given the student id and the new faculty id" << endl;
    cout << "12. Remove an advisee from a faculty member given the ids" << endl;
    cout << "13. Rollback" << endl;
    cout << "14. Exit" << endl;
    cout << "═══════════════════════════════════════════════════════════════════════"<<endl;
    cout << "Select one of the above options: ";
    cin >> option;

    //prints out student BST
    if(option == 1){
      masterStudent->printTree();
    }

    //prints out faculty BST
    if(option == 2){
      masterFaculty->printTree();
    }

    //finds and displays student information given the students id
    if(option == 3){
      cout << "Enter Student ID # to display info: ";
      cin >> studentID;
      //error handling
      if (studentExists(studentID)){
        masterStudent->search(studentID)->getInfo();
        cout << endl;
      }
      else{
        cout<<"ERROR: Student ID not found"<<endl;
      }
    }

    //finds and displays faculty information given the faculty id
    if(option == 4){
      cout << "Enter Faculty ID # to display info: ";
      cin >> facultyID;

      //error handling
      if (facultyExists(facultyID)){
        masterFaculty->search(facultyID)->getInfo();
      }
      else{
        cout<<"ERROR: Faculty ID not found"<<endl;
      }
    }

    //Given a student’s id, prints the name and info of their faculty advisor
    if(option == 5){
      cout << "Enter Student ID # to show their advisor: ";
      cin >> studentID;

      //error handling
      if (studentExists(studentID)){
        Student *temp = masterStudent->search(studentID);
        facultyID = temp->getFacultyID();
        masterFaculty->search(facultyID)->getInfo();
      }
      else{
        cout<<"ERROR: Student ID not found"<<endl;
      }
    }

    //Given a faculty id, prints ALL the names and info of his/her advisees
    if(option == 6){
      cout << "Enter Faculty ID# to show their advisees: ";
      cin >> facultyID;

      //error handling
      if (facultyExists(facultyID)){
        Faculty *temp = masterFaculty->search(facultyID);
        GenDoublyLinkedList<int> *list = temp->getAdvisees();

        int size = list->getSize();
        for(int i = 0; i < size; i++){
          int studentID = list->removeFront();
          masterStudent->search(studentID)->getInfo();
          temp->insertAdvisee(studentID);
        }
      }
      else{
        cout<<"Faculty ID not found"<<endl;
      }
    }
    //adds a new student
    if(option == 7){
      cout << "Enter ID: ";
      cin >> id;

      //if student ID is already in use
      if(masterStudent->search(id) != NULL){
        cout <<  "ERROR: Student ID # is already in use.";
      }
      else {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter major: ";
        cin >> major;
        cout << "Enter GPA: ";
        cin >> gpa;

        char choice;
        cout<<"Does student have faculty advisor (y/n): ";
        cin >> choice;
        if (choice == 'y') {
          cout << "Enter faculty advisor ID: ";
          cin >> facultyID;
          cout << endl;
        }
        else {
          facultyID = 0;
        }

        if((facultyID != 0) && (!(facultyExists(facultyID)))) { // if faculty doesnt exist
          cout<<"ERROR: Faculty ID does not exist"<<endl;
          cout<<"Please try again with a correct ID"<<endl;
        }
        else{
          Student *s = new Student(id, name, level, major, gpa, facultyID);
          masterStudent->insert(s);// inserts to student BST
          if(facultyID != 0){
            masterFaculty->search(facultyID)->insertAdvisee(studentID); //adding student to faculty list as well
          }

          rollBackNum->push(7);
          rollBackStudent->pushP(s);
        }
      }
    }

    //deletes a student
    if(option == 8){
      cout << "Enter student ID # : ";
      cin >> studentID;

      //error handling
      if (studentExists(studentID)){

        rollBackNum->push(8);
        rollBackStudent->pushP(masterStudent->search(studentID));

        int facID = masterStudent->search(studentID)->getFacultyID();
        if(facID != 0){

          GenDoublyLinkedList<int> *adviseeList = masterFaculty->search(facID)->getAdvisees(); //creating a list of advisees

          if(adviseeList->contains(0)) { //checking if no previous advisee
            masterFaculty->search(facID)->deleteAdvisee(0);
          }
          else{
            masterFaculty->search(facID)->deleteAdvisee(studentID); //deleting student from faculty
          }
        }

        masterStudent->deleteNode(studentID); //deleting

        cout << "The student has been deleted." << endl;
      }
      else{
        cout<<"ERROR: Student ID not found"<<endl;
      }
    }

    //adds a new faculty member
    if(option == 9){

      int num = 0;
      char choice;
      bool facultyLoop = true;


      cout << "Enter ID #: ";
      cin >> id;

      //if faculty ID already in use
      if(masterFaculty->search(id) != NULL){
        cout <<  "ERROR: Faculty ID is already in use."  << endl;
      }
      else {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter level: ";
        cin >> level;
        cout << "Enter department: ";
        cin >> department;

        cout<<"Does faculty have student advisee (y/n): ";
        cin >> choice;
        if (choice == 'y') {
          cout << "Enter student advisee ID: ";
          cin >> advisee;
          cout << endl;
        }
        else {
          advisee = 0;
        }

        if((advisee != 0) && (!studentExists(advisee))) {
          cout << "ERR0R: Student doesn't exist" << endl;
          cout<<"Please try again with a correct ID"<<endl;
        }
        else{
          Faculty *f = new Faculty(id, name, level, department, advisee);
          masterFaculty->insert(f);
          masterStudent->search(advisee)->setFacultyAdvisor(facultyID); //adding student to faculty list as well

          while(facultyLoop){


          if (choice == 'y') {
            cout << "Does the faculty member have another advisee ? (y/n): ";
            cin >> choice;

            if(choice == 'y'){
              cout << "Enter advisee ID #: ";
              cin >> advisee;
              if(!studentExists(advisee)){
                cout << "ERR0R: Student doesn't exist" << endl;
                cout<<"Please try again with a correct ID"<<endl;
              }
              else{
                f->insertAdvisee(advisee);
                masterStudent->search(advisee)->setFacultyAdvisor(facultyID); //adding student to faculty list as well
              }
            }
          }
          else{
            facultyLoop = false;
          }
        }
        rollBackNum->push(9);
        rollBackFaculty->pushP(f);
        }
      }
    }

    //Deletes a faculty member given the id
    if(option == 10){
      cout << "Enter faculty ID #: ";
      cin >> facultyID;

      //error handling
      if (facultyExists(facultyID)){
        rollBackNum->push(10);
        rollBackFaculty->pushP(masterFaculty->search(facultyID));

        // deleting faculty advisor from student
        GenDoublyLinkedList<int>* adviseeList = masterFaculty->search(facultyID)->getAdvisees(); //creating a list of advisees
        if(adviseeList->contains(0) == false) { //checking if no previous advisee
          while(adviseeList->isEmpty() == false){
            int top = adviseeList->peek();
            masterStudent->search(top)->setFacultyAdvisor(0);
            adviseeList->removeFront();
          }
        }

        masterFaculty->deleteNode(facultyID);
        cout << "The faculty has been deleted." << endl;
      //masterFaculty->search(facultyID)->printAdvisees();
      }
      else{
        cout<<"ERROR: Faculty ID not found"<<endl;
      }
    }

    // /Changes a student’s advisor given the student id and the new faculty id.
    if(option == 11){
      int ogFac = 0;
      cout << "Enter student ID # : ";
      cin >> studentID;

      //error handling
      if(studentExists(studentID)){
        cout << "Enter new advisor ID #: ";
        cin >> facultyID;
        if(facultyExists(facultyID)) {

          masterFaculty->search(facultyID)->insertAdvisee(studentID); //adding advisee to the faculty
          masterStudent->search(studentID)->setFacultyAdvisor(facultyID); //changing advisor for student
          cout<<"Successfully changed the student's advisor"<<endl;
        }
        else {
          cout << "ERROR: Faculty doesn't exist!!"<<endl;
        }
      }
      else{
        cout<<"ERROR: Student ID not found"<<endl;
      }
    }

    //Removes an advisee from a faculty member given the ids
    if(option == 12){
      cout << "Enter faculty ID #: ";
      cin >> facultyID;

      //error handling
      if (facultyExists(facultyID)){
        cout << "Enter the student ID # you want to remove: ";
        cin >> studentID;
        if (studentExists(studentID)){
          studentID = masterFaculty->search(facultyID)->deleteAdvisee(studentID);
          cout << "Advisee has been removed from the faculty member" <<  endl;
        }
        else{
          cout<<"ERROR: Student ID not found"<<endl;
        }
      }
      else{
        cout << "ERROR: Faculty ID not found"<<endl;
      }
    }

    //rollback
    if(option == 13){

      int num = 0;
      // gets command that was jsut chosen from stack
      num = rollBackNum->pop();

      int IDnum;

      //deletes inserted student node
      if(num == 7){
        Student *temp;
        temp = rollBackStudent->popP();
        IDnum = temp->getStudentID();

        facultyID = temp->getFacultyID();
        masterStudent->deleteNode(IDnum);
        //deletes the student from the faculty
        masterFaculty->search(facultyID)->deleteAdvisee(IDnum);
      }

      //inserts deleted student node
      if(num == 8){
        Student *temp;
        temp = rollBackStudent->popP();
        IDnum = temp->getStudentID();

        masterStudent->insert(temp);
        facultyID = masterStudent->search(studentID)->getFacultyID();
        //adds the student to the faculty
        masterFaculty->search(facultyID)->insertAdvisee(studentID);

      }

      //deletes inserted faculty
      if(num == 9){
        Faculty *temp = rollBackFaculty->popP();
        IDnum = temp->getFacultyID();
        masterFaculty->deleteNode(IDnum);
        cout << "Faculty has been deleted." << endl;
      }

      //inserts deleted faculty node
      if(num == 10){

        Faculty *temp = rollBackFaculty->popP();
        IDnum = temp->getFacultyID();

        masterFaculty->insert(temp);

      }

      //for new students + faculty
      if(num == 11){
        Student *temp;
        temp = rollBackStudent->popP();
        IDnum = temp->getStudentID();

        masterStudent->deleteNode(IDnum);

        Faculty *temp2 = rollBackFaculty->popP();
        IDnum = temp2->getFacultyID();

        masterFaculty->deleteNode(IDnum);

      }
    }

    //exit
    if(option == 14){
      if(masterStudent->isEmpty() == false){ // when the student BST isnt empty
        masterStudent->RSerialization("studentTable"); // appendix A
      }

      if(masterFaculty->isEmpty() == false){ // when the faculty BST isnt empty
        masterFaculty->RSerialization("facultyTable");// appendix A
      }

      loop = false;
    }
    //ALPHA error handling
    if(option > 14 || option <=0|| cin.fail()){ // when not an option 1-14/ or string
    cout << "ERROR: Invalid input.\nSelect a proper option from above (1-14)" << endl;
    cin >> option;
    }
  }
}
