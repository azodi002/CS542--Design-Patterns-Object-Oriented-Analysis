#include "journal.h"

//Journal will implement its own readDocument function
void Journal::readDocument(vector<string>& file, string fileName)
{
  //will read from a file that contains journal information
  ifstream inFile;
  inFile.open(fileName);
  string read;
  
  //store all journal information to vector
  while(inFile.good())
    {
      inFile >> read;
      file.push_back(read);
    }
}

//used for prototype design pattern, to safely create instance of Journal
Document* Journal::clone()
{
  //wil return new instance of Journal
  return new Journal;
}

//special message from Journal class used in executePrint function for Template Method
void Journal::articleType()
{
  cout << "Document Type: Journal " << endl;
}
