#ifndef DOCUMENTDECORATOR_H
#define DOCUMENTDECORATOR_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//base class used to store list of students
class StudentList
{
 public:
  //function will be implemented by derived classes
  virtual void printStudentNames() = 0;
};

//derives from studentlist
class StudentDocument:public StudentList
{
 public:
  //implements message to user and next class continues the cycle
  void printStudentNames()
  {
    cout << "Putting Student Names in Output File output.txt" << endl;
  }
};

//Wrapper of the StudentList class
class StudentDocumentWrapper:public StudentList
{
  //creates pointer of studentlist
 private:
  StudentList* d_wrappee;

 public:
  //assign pointer to an inner pointer to keep track of which function to call dynamically
  StudentDocumentWrapper(StudentList* inner)
    {
      d_wrappee = inner;
    }
  //destructor for safety purposes
  ~StudentDocumentWrapper()
    {
      delete d_wrappee;
    }
  
  //will be used to dynamically call correct function
  void printStudentNames()
  {
    d_wrappee->printStudentNames();
  }

};

//adding functionality because decorator
class StudentDocumentDatabase:public StudentDocumentWrapper
{
 public:
  //constructor to add functonality when creating instance
  StudentDocumentDatabase(StudentList* core): StudentDocumentWrapper(core){}

    //along with printing output to user
    void printStudentNames()
    {
      StudentDocumentWrapper::printStudentNames();
      string name;
      
      ofstream outFile;
      outFile.open("output.txt");
      
      //This will allow user, let's say teacher enter all names of students he/she wants to check their documents so they don't forget
      while(name != "Q")
	{
	  //teacher can enter as many student names as they can and will be sent to output file output.txt
	  cout << "Enter student's name or Q to quit: ";
	  cin >> name;
	  if(name == "Q") break;
	  outFile << name << endl;
	}
    }
};
      
#endif

