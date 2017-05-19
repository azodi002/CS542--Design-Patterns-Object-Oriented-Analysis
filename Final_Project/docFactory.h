#ifndef DOCFACTORY_H
#define DOCFACTORY_H

#include "document.h"

//Static Factory Method Design Pattern
class DocumentFactory
{
  //makeDocument creates instance of class, desired by user
 public:
  static Document* makeDocument(int choice);
 private:
  //d_prototypes is used for prototype pattern, along with factory method
  static Document* d_prototypes[2];
};

#endif
