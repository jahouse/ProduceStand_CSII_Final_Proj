/*
 Bekk Blando
 Programming Assignment 4
 Instructor:  Dr. Yvon Feaster
 CPSC 1020
 Due:  Friday, December 8th
*/

#include "Person.h"

Person::Person(){

}

Person::Person(string first_name, string last_name, string email_address, Address addr, Date date): first(first_name), last(last_name), email(email_address), address(addr), bday(date){

}

Person::~Person(){

}

string Person::print(){
  stringstream output;
  output << last << ", "<< first << endl;
  output << email << endl;
  output << address.print();
  return output.str();
}

string Person::getFirst(){
  return(first);
}

string Person::getLast(){
  return(last);
}
