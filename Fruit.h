#ifndef FRUIT_H
#define FRUIT_H

#include <string>
#include "ProduceStand.h"
#include <fstream>
#include <iostream>

using namespace std;

class Fruit : public ProduceStand
{
  private:
    static double totalFruitSales;
    static int fruitCount;

  public:
    Fruit();
    Fruit(string, double, double, double, int);
    ~Fruit();   
    void calculateSale();
    void calculateTax();
    void printReceipt(ofstream& out);
    static void printStats(ofstream& out); 
};

#endif
