/**************************************************************
Name: Omid Azodi
Professor: Dr. Ye
Class: CS542
Due Date: 04/19/2017
Description: Observer Design Pattern
**************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// People & Organization inherit from same interface
class Observer
{
public:
  //function used for both People & Organization
  virtual void action(string s) = 0;
};

//FireDept & PoliceDept inherit from same interface
class Subject
{
public:
  //functions used for both FireDept & PoliceDept
  virtual void notify() = 0;
  virtual void attach(Observer* obs) = 0;
};

//People is an observer 
class People:public Observer
{
public:
  //Constructor  
  People(string s) {
    name = s;
  }
  //function that people is supposed to do
  void action(string s)
  {
    cout << name << " is running away from a " << s << endl;
  }
  
protected:
  string name;
};

//Organization is an observer
class Organization:public Observer
{
public:
  //Constructor 
  Organization(string s) {
    name = s;
  }
  //function that organization is supposed to do
  void action(string s)
  {
    cout << name << " is paying attention on a " << s << endl;
  }

protected:
  string name;
};

class FireDept:public Subject
{
  
  string location;
  //vector that accepts people & organization
  vector<Observer*> subs;
  
public:
 
  //subscription function
  //dynamically during run-time can subscribe people or organization to FireDept
  void attach(Observer* obs)
  {
    subs.push_back(obs);
  }
  
  //call the notify function
  void setAlarm(string locat)
  {
    location = locat;
    notify();
  }
  
  //notify calls the corresponding functions for people and organization
  void notify()
  {
    for(int i = 0; i < subs.size(); i++)
      {
	//calls people & organization action functions
	subs[i]->action("fire alarm near " + location);
      }
  }
};

class PoliceDept:public Subject
{
  string location;
  //vector that accepts both People & Organization
  vector<Observer*> subs;

public:
  //calls the notify function for PoliceDept
  void setAlarm(string locat)
  {
    location = locat;
    notify();
  }
 
  //subscribes People or Organization to the PoliceDept
  void attach(Observer* obs)
  {
    subs.push_back(obs);
  }

  //Calls function corresponding from People or Organization
  void notify()
  {
    for(int i = 0; i < subs.size(); i++)
      {
	//will dynamically bind the correct function call for either People or Organization
	subs[i]->action("attack alarm near " + location);
      }
  }

};

int main()
{
  //Object for fireDept 
  FireDept fireDept;
  //Object for policeDept
  PoliceDept policeDept;
  
  //People object corresponding to Sam
  People* personOne = new People("Sam");
  //subscribe Sam to the fireDept
  fireDept.attach(personOne);
  
  //People object corresponding to Mary
  People* personTwo = new People("Mary");
  //subscribe Mary to policeDept 
  policeDept.attach(personTwo);
  
  //Create an UCLA organization
  Organization* orgOne = new Organization("UCLA");
  //subscribe UCLA organization to fireDept
  fireDept.attach(orgOne);  
  //subscribe UCLA organization to policeDept
  policeDept.attach(orgOne);
  
  cout << endl << "******************" << endl;
  fireDept.setAlarm("San Diego"); //Chose San Diego Arbitrary
  cout << endl << endl;
  policeDept.setAlarm("San Marcos"); //Chose San Marcos Arbitrary
  cout << "******************" << endl << endl; 

  return 0;
}
