/* Jada Houser
 * jahouse
 * CPSC 1020 Fall 2017
 * Assignment: Project 4
 * Instructor: Dr. Yvon Feaster
 */

#include "Fruit.h" 

using namespace std; 

//Intialize static members
double Fruit::totalFruitSales = 0.0;
int Fruit::fruitCount = 0;

//Default Constructor
Fruit::Fruit()
{

}

//Regular/Initialization List Constructor
Fruit::Fruit(string n, double w, double price_lb, double price_each, int items):
ProduceStand(n, w, price_lb, price_each, items)
{

}

//Default Destructor
Fruit::~Fruit()
{

}

//Calculate the sale of each item, then add value to totalFruitSales,
//totalFruitSales to customerSales, and totalFruitSale to
//dailySales
void Fruit::calculateSale()
{
  if(pricePerlb == 0.0 && weight == 0.0)
  {
    eachSale = pricePerEach * howMany;
    fruitCount += howMany;
  }
  else if(pricePerEach == 0.0 && howMany == 0)
  {
    eachSale = pricePerlb * weight;
    fruitCount++;
  }

  //just fruit sales
  totalFruitSales += eachSale;
  //fruit and veggie sales per customer
  customerTotal += eachSale;
  //fruit and veggie sales for all customers
  dailySales += eachSale;
}

//Calculate the tax of each item, then add value to totalSalesTax,
//and totalSalesTax to dailySalesTax
void Fruit::calculateTax()
{
  //tax for one customer
  totalSalesTax += eachSale * tax;
  //tax for all customers
  dailySalesTax += eachSale * tax;
}

void Fruit::printReceipt(ofstream& out)
{
  out << setprecision(2) << fixed;
  out << name << "\n" << eachSale << endl; 
}

void Fruit::printStats(ofstream& out)
{
  out << "Total Fruits Sold: " << fruitCount << endl;
  out << "Total Fruit Sales: " << totalFruitSales << endl;
}
