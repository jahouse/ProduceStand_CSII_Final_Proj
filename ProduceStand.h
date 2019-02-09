#ifndef STAND_H
#define STAND_H

#include <string>
#include <sstream>
#include <ctime>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "Person.h"
#include <vector>

using namespace std;

class ProduceStand
{
  protected:
    //initialize
    Person customer;
    string name;
    double weight;
    double pricePerlb;
    double pricePerEach;
    int howMany;
    const double tax = 0.08;

    //Compute
    double eachSale;
    static double totalSalesTax;
    static double customerTotal;
    
    //keeps track of the dailySales of both Fruit and Vegtable.
    static double dailySales;
    static double dailySalesTax;

  private:
    const string standName = "Produce Stand";
    const string standLocation = "Columbia, SC";
    /*because PS's constructor gets called each time an instance of fruit or
     *vegetable gets cretated then increment receiptNum also.*/
    static int receiptNum;

  public:
    ProduceStand();
    ProduceStand(string, double, double, double, int);
    virtual ~ProduceStand();
    virtual void calculateSale();
    virtual void calculateTax();
    virtual void printReceipt(ofstream&); 
    void printReceiptTop(ofstream& out);
    void printReceiptBot(ofstream& out);
    static void printStats(ofstream& out);
    void setPerson(Person p);
    string getStandName();
    string getStandLocation();
    static int getReceiptNum();
    static void setReceiptNum(int);
};
#endif
