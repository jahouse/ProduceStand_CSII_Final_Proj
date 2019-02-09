#ifndef PERSON_H
#define PERSON_H

#include "Address.h"
#include "Date.h"
#include <string>

class Person
{
  private:
    string first;
    string last;
    string email;
    Address address;
    Date bday;

  public:

    /*Constructors*/
    Person();/*: first("default"), last("default"),
      email("who@nowhere.com"), address(Address()), bday(Date()) {}*/
    Person(string, string, string, Address, Date);
    ~Person();

    /*Getters and Setters*/

    string getFirst();
    string getLast();

    /*Other functions*/
    string print();

};

#endif
