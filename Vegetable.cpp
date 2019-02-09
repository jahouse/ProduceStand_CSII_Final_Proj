/* Jada Houser
 * jahouse
 * CPSC 1021 Fall 2017
 * Assignment: Project 4
 * Instructor: Dr. Yvon Feaster
 */

#include "Vegetable.h"

using namespace std;

//Initialize static members
double Vegetable::totalVegtSales = 0.0;
int Vegetable::vegtCount = 0;

Vegetable::Vegetable()
{

}

Vegetable::Vegetable(string n, double w, double price_lb, double price_each, int items):
ProduceStand(n, w, price_lb, price_each, items)
{

}

Vegetable::~Vegetable()
{

}

void Vegetable::calculateSale()
{
  if(pricePerlb == 0.0 && weight == 0.0)
  {
    eachSale = pricePerEach * howMany;
    vegtCount += howMany;
  }
   else if(pricePerEach == 0.0 && howMany == 0)
  {
    eachSale = pricePerlb * weight;
    vegtCount++;
  }

  //all fruit sales
  totalVegtSales += eachSale;
  //fruit and veggie sales per customer
  customerTotal += eachSale;
  //fruit and veggie sales for all customers
  dailySales += eachSale;
}

void Vegetable::calculateTax()
{
  //tax for one customer
  totalSalesTax += eachSale * tax;
  //tax for all customers
  dailySalesTax += eachSale * tax;
}

void Vegetable::printReceipt(ofstream& out)
{
  out << setprecision(2) << fixed;
  out << name << "\n" << eachSale << endl;
}

void Vegetable::printStats(ofstream& out)
{
  out << "Total Vegetables Sold: " << vegtCount << endl;
  out << "Total Vegetable Sales: " << totalVegtSales << endl;
}
