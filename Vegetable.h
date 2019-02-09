#ifndef VEGETABLE_H
#define VEGETABLE_H

#include <string>
#include "ProduceStand.h"
#include <fstream>
#include <iostream>

using namespace std;

class Vegetable : public ProduceStand
{
  private:

    static double totalVegtSales;
    static int vegtCount;

  public:
    //constructor
    Vegetable(); //default
    Vegetable(string, double, double, double, int); //regular
    ~Vegetable(); //destructor

    void calculateSale();
    void calculateTax();
    void printReceipt(ofstream& out);
    static void printStats(ofstream& out);
};

#endif
