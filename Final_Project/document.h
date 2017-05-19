#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

/**********************************************************
Class Document:
Used for base class for Article and Journal types of files
Types of Design Patterns Implemented:
 - Creational: Static Factory Method
 - Creational: Prototype
 - Behavioral: Template Method
***********************************************************/
class Document
{
 private:
  //function used in executePrint for template method
  void printHeader()
  {
    //Shows to user what is going to be displayed
    cout << "****** Document Information ******" << endl;
  }  
  
  //Derived class will implement placeholder method
  virtual void articleType() = 0;

 public:
  //function clone used to be implemented from prototype design pattern
  virtual Document* clone() = 0;
  //readDocument  function is reading in the document types
  virtual void readDocument(vector<string>& file, string fileName) = 0;  
  
  //Standardize skeleton of algorithm in base class "template method"
  void executePrint();

};


#endif
