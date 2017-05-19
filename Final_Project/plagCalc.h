#ifndef PLAGCALC_H
#define PLAGCALC_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

//This class is used to check the documents and display percentages
class plagCalc
{
 private:
  //Singleton instance 
  static plagCalc* instance;
  //two files, one is original file
  vector<string> originalFile;
  //one is file being checked
  vector<string> checkFile;

 public:
  plagCalc();
  ~plagCalc();
  //used for Singleton implementation
  static plagCalc* GetInstance();
  //readFile stores all content from file to vector
  void readFile(string fileName, vector<string>& contentFile);
  //printFile displays all content from file to user on display
  void printFile(const vector<string> originalFile) const;
  //percentageSimilarity takes two file contents and return total words that were similar in same order
  float percentageSimilarity(vector<string> originalFile, vector<string> checkFile);
  //totalWords will take file contents and count how many words in file
  float totalWords(vector<string> file);
  //plagiarismCheck will take percentage similarity and determine if cheated or not cheated
  bool plagiarismCheck(float percentage);
};

#endif 
