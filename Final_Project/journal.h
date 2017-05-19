#ifndef JOURNAL_H
#define JOURNAL_H

#include "document.h"

//Inherits from document base class
class Journal:public Document
{
 public:
  //clone function used for prototype design pattern
  Document* clone();
  //readDocument is implementing the virtual function from base class
  //reads all content from file
  void readDocument(vector<string>& file, string fileName);
  //articleType is a function that displays special message for Journal class only
  //function used only in executePrint function for template Method
  void articleType();
};

#endif
