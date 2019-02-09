#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
#include <sstream>
using namespace std;

class Address
{
  private:
    int streetNum;
    string streetName;
    string city;
    string state;
    int zip;

  public:

    /*Constructors*/
    Address(): streetNum(0), streetName("name"), city("city"), state("state"),
    zip(0) {}
    Address(int street_number, string street_name, string city, string state, int zipcode);

    /*Other functions*/
    string print();


};

#endif
