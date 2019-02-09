/*
 Bekk Blando | Jada Houser
 Programming Assignment 4
 Instructor:  Dr. Yvon Feaster
 CPSC 1020
 Due: Friday, December 8th
*/

#include "clientFunct.h"

using namespace std;

// Load Our Data from a text file with the appropriate format
vector<vector<ProduceStand*> > loadData(ifstream& input, ofstream& mailing){
  // Get the type, item, weight, price_per_weight, piece_price, items, mailing_list
  // Fruit  apple  0  0  .30 10 y
    // If they want to be on the mailing mailing_list
        // Get there name, email, street_number, street_name, city, state, zip_code
        // Mitch Rapp mRapp@gmail.com 201 NoWhere Poedunk VA 31908 10 7 1963
  string type, item, first_name, last_name, email, street_name, city, state;
  char mailing_list;
  double weight, price_per_weight, piece_price;
  int i, numItems, items, zip_code, street_number, day, month, year;
  //ProduceStand* standS = &stand;
  vector<ProduceStand*> sales;
  vector<vector<ProduceStand*> > orders;
  PersonList mailingList;

  while(input >> numItems)
  {
    sales.clear();
    for(i = numItems; i > 0; i--)
    {
      input >> type >> item >> weight >> price_per_weight >> piece_price >> items;
      if(type == "Fruit")
      {
        Fruit* fruit = new Fruit(item, weight, price_per_weight, piece_price, items);

        sales.push_back(fruit);
      }
      else
      {
        Vegetable* veggie = new Vegetable(item, weight, price_per_weight, piece_price, items);

        sales.push_back(veggie);
      }
    }
    orders.push_back(sales);

    input >> mailing_list;

    if(mailing_list == 'y')
    {
      //store
      input >> first_name >> last_name >> email >> street_number >> street_name;
      input >> city >> state >> zip_code >> day >> month >> year;

      //initialize
      Address* address = new Address(street_number, street_name, city, state, zip_code);
      Date* date = new Date(day, month, year);
      Person* person = new Person(first_name, last_name, email, *address, *date);

      mailingList.append(person);

    }
  }
  mailingList.alpha_sort();
  mailingList.print(mailing);

  return orders;
}
