#include "article.h"

//Implementing readDocument function
void Article::readDocument(vector<string>& file, string fileName)
{
  //Reads from input file and stores content of article to vector
  ifstream inFile;
  inFile.open(fileName);
  string read;

  //continuously read everything from file to vector
  while(inFile.good())
    {
      inFile >> read;
      file.push_back(read);
    }
}

//used to implement the prototype design pattern
Document* Article::clone()
{
  //returns new instance of article
  return new Article;
}

//used part of template method
void Article::articleType()
{
  //prints special message regarding article objects only
  cout << "Document Type: Article" << endl;
}
