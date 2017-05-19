#include "plagCalc.h"

//singleton instance must be initialized since it is static member
plagCalc* plagCalc::instance =0;

//used to implement singleton design pattern
plagCalc* plagCalc::GetInstance()
{
  //ensuring only one instance of this object is created
  if(instance == 0)
    {
      instance = new plagCalc();
    }
  return instance;
}

//Default constructor
plagCalc::plagCalc()
{
  ;
}

//used to read in original file in main for plagiarism calculator to compare too
void plagCalc::readFile(string fileName, vector<string>& contentFile)
{
  //will open desired file by user and read content
  ifstream inFile;
  string word;
  
  inFile.open(fileName);
  
  //continuously read content from file
  while(inFile >> word)
    {
      contentFile.push_back(word);
    }
}

//printFile will print all the contents of the file
//used for debugging to visually match each file
//However, can be used by client if they want to see what is in each file being compared
void plagCalc::printFile(const vector<string> originalFile) const
{
  //will go through each element of file and print it out
  for(int i = 0; i< originalFile.size(); i++)
    {
      cout << originalFile[i];
    }
}
  
//percentageSimilarity will take two files in vector format and compare each element at a time
float plagCalc::percentageSimilarity(vector<string> originalFile, vector<string> checkFile)
{
  //variables used to keep track of calculations that need to be done
  float result;
  float totalSimilarity = 0.0;
  float totalOriginalFile = totalWords(originalFile);
  
  float totalCheckFile = 0.0;
  //totalWords checks if one file has more content than the other
  //This is important to check which file is bigger so the calculation can be divided correctly
  totalCheckFile = totalWords(checkFile);

  //Two iterators from beginning, for each corresponding file
  //iterator for originalFile used to compare against another file
  vector<string>::iterator original = originalFile.begin();
  //iterator for a file that will be tested on original file
  vector<string>::iterator check = checkFile.begin();
  
  //if original file has less content, then we use the less content
  if(totalCheckFile >= totalOriginalFile)
    {
      //keep iterating until original file hits end
      while(original != originalFile.end())
	{
	  //if content of each file (original and one being checked is the same)
	  if(*original == *check)
	    {
	      //increment total words same
	      totalSimilarity++;
	    }
	  //increment each iterator
	  check++;
	  original++;
	} 
    }

  else
    {
      //keep iterating until check file hits end
      while(check != checkFile.end())
        {
	  //if content of each file (original and file being checked are same)
          if(*original == *check)
            {
	      //increment total words same
              totalSimilarity++;
            }
	  //increment each iterator
          check++;
          original++;
        }
    }  

  //return total words that are the same from the two files compared
  //used in calculations in main to figure out and display percentages
  return totalSimilarity;
}

//totalWords, calculates how many words are in each file
float plagCalc::totalWords(vector<string> file)
{
  float totalWords = 0.0;
  //begins iterator from checked file
  vector<string>::iterator fileIterator = file.begin();
  
  //until iterator ends keep adding words
  while(fileIterator != file.end())
    {
      //increment iterator and words counter
      fileIterator++;
      totalWords++;
    }
  return totalWords;
}

//function used to determine if the person cheated based off percentage calculated and used as input
bool plagCalc:: plagiarismCheck(float percentage)
{
  bool cheated;
  
  //if percentage is less than or equal to 20 they don't cheat
  if(percentage <= 20.0)
    {
      //change boolean to indicate NOT cheated
      cheated = false;
    }
  
  //if percentage is more than 20% than they cheated
  else if(percentage > 20.0)
    {
      //change boolean to indicate cheated
      cheated = true;
    }
 
  //return result of cheated or not cheated
 return cheated;
}



