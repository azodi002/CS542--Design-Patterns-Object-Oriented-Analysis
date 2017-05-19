#ifndef ARTICLE_H
#define ARTICLE_H

#include "document.h"

//Derivces from base class document
class Article:public Document
{
 public:
  //implements readDocument function, stores all from file
    void readDocument(vector<string>& file, string fileName);
    //implements a special message used in printExecute for template method
    void articleType();
    //used for prototype design pattern, to create instance
    Document* clone();
};

#endif
