/*************************
Name: Omid Azodi
Prfoessor: Xin Ye
Date: 03/12/2017
Homework: HW5 Composite design pattern
Class: CS542 (Design Patterns)
How to compile: g++ composite.cpp
**************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Interface to all leafs
class LegoComponent
{
public:
  virtual void play() = 0;
};

//Implements play function from LegoComponent
class LegoBrick1X1:public LegoComponent
{
public:
  //Set color for 1x1
  LegoBrick1X1(string val)
  {
    color = val;
  }
  void play()
  {
    cout << "A " << color << " Lego 1X1 brick" << endl;
  }
  string color;
};

//Implements play function from LegoComponent
class LegoBrick1X2:public LegoComponent
{
public:
  //Set color for 1x2
  LegoBrick1X2(string val)
  {
    color = val;
  }
  void play()
  {
    cout << "A " << color << " Lego 1X2 brick" << endl;
  }
  string color;
};

//Implements play function from LegoComponent
class LegoBrick2X2:public LegoComponent
{
public:
  //Set color for 2x2
  LegoBrick2X2(string val)
  {
    color = val;
  }
  void play()
  {
    cout << "A " << color << " Lego 2X2 brick" << endl;
  }
  string color;
};

//Implements play function from LegoComponent
class LegoFigure:public LegoComponent
{
public:
  //Set occupation for Figure
  LegoFigure(string val)
  {
    occupation = val;
  }
  void play()
  {
    cout << "A " << occupation << " Lego figure." << endl;
  }
  string occupation;
};


//LegoProduct is like our Composite class that adds all different lego Parts
class LegoProduct:public LegoComponent
{
  vector<LegoComponent*> legoComponent;
public:
  LegoProduct(string val)
  {
    name = val;
  }
  //Add function reduced to only one, instead of separate for each different type
  //Add function adds all types of legoParts, figures, etc.
  void add(LegoComponent *legoPart)
  {
     legoComponent.push_back(legoPart);
  }
  //One play function needed to print all functionalities for all lego items
  void play()
  {    
    for(int i = 0; i < legoComponent.size(); i++)
      legoComponent[i]->play();
  }
  string name;
};


int main()
{
  //Creating LegoBrick objects with different varieties
  LegoBrick1X1 brick1("red");
  LegoBrick1X2 brick2("yellow");
  LegoBrick2X2 brick3("blue");
  LegoBrick2X2 brick4("green");

  //Creating LegoFigure objects with different figure toys
  LegoFigure figure1("prince");
  LegoFigure figure2("princess");
  LegoFigure figure3("knight");

  //Creating different LegoProduct objects with different products
  LegoProduct product1("castle");
  LegoProduct product2("kindom");

  //Product1 adding required lego brick pieces 
  product1.add(&brick1);
  product1.add(&brick2);
  product1.add(&brick3);
  product1.add(&brick4);

  product1.play();

  cout << "_________________" << endl << endl;

  //Product2 adding required figure lego pieces
  product2.add(&figure1);
  product2.add(&figure2);
  product2.add(&figure3);
  product2.add(&product1);

  product2.play();

  return 0;
}
