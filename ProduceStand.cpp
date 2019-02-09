/* Jada Houser
 * jahouse
 * CPSC 1020 Fall 2017
 * Assignment: Project 4
 * Instructor: Dr. Yvon Feaster
 */

#include "ProduceStand.h"

using namespace std;

//Initialize static members
double ProduceStand::dailySales = 0.0;
double ProduceStand::dailySalesTax = 0.0;
int ProduceStand::receiptNum = 1;
double ProduceStand::totalSalesTax = 0;
double ProduceStand::customerTotal = 0;

ProduceStand::ProduceStand()
{

}

ProduceStand::ProduceStand(string n, double w, double price_lb, double price_each, int items):name(n), weight(w), pricePerlb(price_lb), 
 pricePerEach(price_each), howMany(items)
{

}

ProduceStand::~ProduceStand()
{

}

void ProduceStand::calculateSale()
{

}

void ProduceStand::calculateTax()
{

}

void ProduceStand::printReceipt(ofstream& out)
{

}

void ProduceStand::printReceiptTop(ofstream& out)
{
  out << "==================================================" << endl;
  out << standName << "\n" << standLocation << "\n" << "Receipt #" << receiptNum << endl;
  out << "==================================================" << endl;  

  ProduceStand::receiptNum++;
}

void ProduceStand::printReceiptBot(ofstream& out)
{
  out << setw(15) << "Sales Tax:" << setw(35) << totalSalesTax << endl;
  out << setw(11) << "Total:" << setw(39) << customerTotal + totalSalesTax << endl;

  ProduceStand::totalSalesTax = 0;
  ProduceStand::customerTotal = 0; 
}

void ProduceStand::printStats(ofstream& out)
{
  out << "==================================================" << endl;
  out << "Daily Statistics" << endl;
  out << "==================================================" << endl;

  out << setprecision(2) << fixed;
  out << "Total Sales for the Day: " << dailySales << endl;
  out << "Total Tax for the Day: " << dailySalesTax << endl;
}

void ProduceStand::setPerson(Person p)
{
  customer = p;
}

string ProduceStand::getStandName(){
   return(standName);
}

string ProduceStand::getStandLocation(){
   return(standLocation);
}

int ProduceStand::getReceiptNum(){
   return(receiptNum);
}

void ProduceStand::setReceiptNum(int recNum){
   receiptNum = recNum;
}
