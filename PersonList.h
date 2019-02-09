/*
 Bekk Blando | Jada Houser
 Programming Assignment 4
 Instructor:  Dr. Yvon Feaster
 CPSC 1020
 Due:  Friday, December 8th
*/

#include <iostream>
#include "Person.h"
#include <fstream>

using namespace std;

struct node{
  Person *person;
  node *next;
};

class PersonList {

  private:
    // Node Definition Head Tail
    node *head, *tail;

  public:
    PersonList(): head(NULL), tail(NULL) {}
    ~PersonList();

  // Add Node
  node* append(Person* person);

  // Override [] operator
  node* operator[](int);


  void swapNodes(int);

  // sort in alphabetical order
  void alpha_sort();

  void print(ofstream&);
};
