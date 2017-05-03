/*************************************
Name: Omid Azodi
Professor: Dr. Ye
Class: CS542
Date: 05/01/2017

Description: Strategy Design Pattern
**************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Interface for NormalBill, HappyHourBill, HolidayBill
class Bill
{
public:
  float totalPrice;
  float tax;
  Bill(){
    tax = 0.8;
    totalPrice = 0;
  }
  //Functions that is implemented the same throughout all subclasses
  void add(float price){
    totalPrice += price;
  };

  //abstract function that must be implemented in subclasses (has unique implementation per subclass)
  virtual float checkout() = 0;
};

//Normal bill class inherits from Bill
class NormalBill:public Bill
{
public:

  // adds tax to totalprice
  float checkout() {
    return totalPrice * (1 + tax);
  }
protected:

};

//HappyHourBill inherits from Bill
class HappyHourBill:public Bill
{
public:
  //adds tax to totalPrice
  float checkout() {
    return totalPrice * 0.8 * (1 + tax);
  }
protected:

};

//HolidaBill inherits from Bill
class HolidayBill:public Bill
{
public:
  //Adds tax to totalPrice
  float checkout() {
    return totalPrice * 1.2 * (1 + tax);
  }
protected:
};

//Strategy class implemented
class BillStrategy
{
private:
  //Used for correct type client wants to instantiate
  Bill* bill;

public:
  //Client passes in an integer 1,2,3 and instanties a certain type of Bill
  void setType(int type)
  {
    //Client will instantiate NormalBill if choose 1
    if(type == 1)
      {
      	bill = new NormalBill();
      }
    //Client will instantiate HappyHourBill if choose 2
      if(type == 2)
      {
	bill = new HappyHourBill();
      }
      //Client will instantiate HolidayBill if choose 3
    if(type == 3)
      {
	bill = new HolidayBill();
      }
    
  }

  //Client can choose just this function and will resolve add function dynamically
  void addNumber(float price)
  {
    bill->add(price);
  }
  
  //Client can choose this function and willr esolve checkout function dynamically
  float billCheckout()
  {
    return bill->checkout();
  }

};


int main()
{  
  //Instantiate one object for bill
  BillStrategy bill;
  bill.setType(1);//NormalBill
  bill.addNumber(123);//Choose 123 for price
  //Call final price with tax for NormalBill
  cout << "The total price for the normal bill is: " << bill.billCheckout() << endl;
  
  bill.setType(2);//reset type to HappyHourBill
  bill.addNumber(123);//Choose 123 for price
  //Call final price with tax for HappyHourBill
  cout << "The total price for the normal bill is: " << bill.billCheckout() << endl;

  bill.setType(3);//reset type to HolidayBill
  bill.addNumber(123);//Choose 123 for price
  //Call final price with tax for HolidayBill
  cout << "The total price for the normal bill is: " << bill.billCheckout() << endl;

  return 0;
}
