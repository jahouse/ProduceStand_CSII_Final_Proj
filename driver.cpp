/**KEEP FILE**/

#include "clientFunct.h"

using namespace std;

int main(int argv, char** args){
  ifstream input;
  ofstream output, mailing;
  input.open(args[1]);
  output.open(args[2]);
  mailing.open(args[3]);
  vector<vector<ProduceStand*> > orders;
  unsigned int order, sale = 0;

  // Validate File TODC Redundent yo
  if(!input){
    cout << "Invalid File: " << args[1];
    return 1;
  }
  if(!output){
    cout << "Invalid File: " << args[2];
    return 1;
  }

  if(!mailing){
    cout << "Invalid File: " << args[3];
    return 1;
  }

  //Load data
  orders = loadData(input, mailing);

  for(order = 0; order < orders.size(); order++)
  {
   orders[order][0]->printReceiptTop(output); 
   for(sale = 0; sale < orders[order].size(); sale++)
   {
      orders[order][sale]->calculateSale();
      orders[order][sale]->calculateTax();
      orders[order][sale]->printReceipt(output);
    }
    orders[order][sale]->printReceiptBot(output);
  }
 
  ProduceStand::printStats(output); 
  Fruit::printStats(output);
  Vegetable::printStats(output);
 
  for(order = 0; order < orders.size(); order++)
  {
    for(sale = 0; sale < orders[order].size(); sale++)
    {
      delete orders[order][sale];
    }
  }
 
  orders.clear();

  return 0;
}
