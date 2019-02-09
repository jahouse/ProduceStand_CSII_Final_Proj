/*
 Bekk Blando
 Programming Assignment 4
 Instructor:  Dr. Yvon Feaster
 CPSC 1020
 Due:  Friday, December 8th
*/

#include "Address.h"

Address::Address(int street_number, string street_name, string city, string state, int zipcode)
{
  streetNum = street_number;
  streetName = street_name;
  this->city = city;
  this->state = state;
  zip = zipcode;
}

string Address::print(){
  stringstream output;
  output << streetNum << " " << streetName << endl;
  output << city << " " << state << " "<< zip << endl;
  return output.str();
}
