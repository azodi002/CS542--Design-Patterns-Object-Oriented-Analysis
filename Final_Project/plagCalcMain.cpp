/*******************************************************************
Name: Omid Azodi
Professor: Dr. Ye
Class: CS542 Object Oriented Analysis & Design Patterns
Due Date: 05/19/2017

Assignment: Final Project

Description: 
The goal is to take different file types such as Articles & Journals, and compare to a original file.
The similarity percentage will be returned as well as if the person cheated or not cheated
The threshold of cheating is held at <=20%

Design Patterns Used:
- Structural: Decorator Design Pattern
- Behavioral: Template Method Design Pattern
- Creational: Static Factory Method Design Pattern
- Creational: Prototype Design Pattern
- Creational: Singleton Design Pattern
**********************************************************************/ 

#include "plagCalc.h"
#include "docFactory.h"
#include "document.h"
#include "documentDecorator.h"

int main()
{
  //Create instance of plagiarism checker
  plagCalc* checker = plagCalc::GetInstance();
  //contents of original file that will be used to compare against 
  vector<string> originalFile;
  string originalFileName;
  
  //vector storing Articles & Journals
  vector<Document*> documents;
  int choice;

  //User can determine which original file they want to choose
  cout << "******************************************************************" << endl;
  cout << "Enter the original File name (used to compare): ";
  cin >> originalFileName;
  //store contents of original file to the vector
  checker->readFile(originalFileName, originalFile);

  //user can now choose which type of document they want to create
  //user can create article or journal document types
  cout << endl << "******************************************************************" << endl;
  cout << " ['0'] = Article " << endl;
  cout << " ['1'] = Journal " << endl;
  cout << " ['2'] = QUIT" << endl << endl;
  cout << "Enter type of document: ";
  cin >> choice;
  
  cout << endl << "******************************************************************" << endl;
 
  //while the user chooses article and journal push back to vector
  while(choice == 0 || choice == 1)
    {
      documents.push_back(DocumentFactory::makeDocument(choice));

      cout << " ['0'] = Article " << endl;
      cout << " ['1'] = Journal " << endl;
      cout << " ['2'] = QUIT" << endl << endl;
      cout << "Enter type of document: ";
      cin >> choice;
      
      cout << "******************************************************************" << endl;
    }

  //content stores the article or journal files and used to compare on original fiel
  vector<string> content;
  //user can choose document file name for journal or article
  string documentFileName;

  //variables used for calculations on similarity and determine if cheat or not cheat
  float totalSimilarityPercentage;
  float totalOriginalFile;
  float totalCheckFile;
  float percentage = 0.0;
  bool cheated;

  //go through each document (article or journal)
  for(int i = 0; i < documents.size(); i++)
    {
      //for each document will print out document number 
      cout << endl <<  "******************************************************************" << endl;
      //user will enter the file name for that specific document
      cout << "Enter file name for [Document " << i+1 << "] (EX: student.txt): ";
      cin >> documentFileName;
      //will read contents from the document
      documents[i]->readDocument(content, documentFileName);

      //similar percentage will be calculated based on original file and the document file
      totalSimilarityPercentage = checker->percentageSimilarity(originalFile, content);
      
      //calculating total words for original file and document file
      totalOriginalFile = checker->totalWords(originalFile);
      totalCheckFile = checker->totalWords(content);

      //If more words in original file than continue calculations
      if(totalOriginalFile >= totalCheckFile)
	{
	  //print to user the number of similar words over the total words in the file
	  cout << totalSimilarityPercentage << "/" << totalCheckFile << " words the same " << endl;
	  //print to user the total percentage of similarity
	  percentage = (totalSimilarityPercentage/totalCheckFile) * 100;
	}

      //If more words in document file than continue calculations
      if(totalCheckFile > totalOriginalFile)
	{
	  //print to user the total similar percentage
	  cout << totalSimilarityPercentage << "/" << totalOriginalFile << " words the same " << endl;
	  //print to user the total percentage of similarity
	  percentage = (totalSimilarityPercentage/totalOriginalFile) * 100; 
	}
      
      //calculate final result, by sending in the percentage
      cheated = checker->plagiarismCheck(percentage);
  
      //if the result of function plagiarismCheck was true than continue
      if(cheated == true)
	{
	  //the user cheated, display messages
	  cout << "!!!! CHEATED !!!! " << endl;
	  cout << "Similarity OVER 20%, your similarity is: " << percentage << "%" << endl;
	  cout << endl;
	  //display the template method which has information regarding the specific document type the user cheated on (Journal or Article)
	  documents[i]->executePrint();
	  cout << endl << endl;
	}
  
      //if result of function plagiarismCheck was false than continue 
      if(cheated == false)
	{
	  //if user did NOT cheat, display messages
	  cout << "NO CHEATING " << endl;
	  cout << "Similarity UNDER 20%, your similarity is: " << percentage << "%" <<  endl;
	  cout << endl;
	  //display the template method, for which the user has information regarding specific document type the user did not cheat on (Journal or Article)
	  documents[i]->executePrint();
	  cout << endl << endl;
	}

      cout << endl <<  "******************************************************************" << endl;

      //clear content of document file so new document can be read
      content.clear();
      //the loop wil continue until all documents (article or journals) has been checked

    }//End of for loop    

  //ALL the documents have been calculated and tested for similarity between the original file
  cout << endl << endl <<  "ALL DOCUMENTS HAVE BEEN CHECKED" << endl << endl;
  
  //creates a small database using decorator pattern
  //will print user information on what the database will do in terms of storing into specific file
  StudentList* database = new StudentDocumentDatabase(new StudentDocument);
  //then will print studentNames, will ask user to enter names of students
  //the names of students will be stored into a output.txt 
  //the reason is so the teacher or client can go back to output.txt and see if they need to grade or test anyone else's files
  //used for a reminder for client
  database->printStudentNames();

  return 0;
}
