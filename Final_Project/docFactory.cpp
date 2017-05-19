#include "docFactory.h"
#include "article.h"
#include "journal.h"

//Static factory method for creating new instance 
//Takes user input as choice and then chooses to create new instance of article or journal
Document* DocumentFactory::makeDocument(int choice)
{
  //factory method mixed with prototype to ensure security when creating new instance
  return d_prototypes[choice]->clone();
}

//Used for prototype design pattern, when user enters specific index 
Document* DocumentFactory::d_prototypes[] = {new Article, new Journal};
