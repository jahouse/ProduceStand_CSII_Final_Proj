/*
 Bekk Blando | Jada Houser
 Programming Assignment 4
 Instructor:  Dr. Yvon Feaster
 CPSC 1020
 Due:  Friday, December 8th
*/

#include "PersonList.h"

PersonList::~PersonList(){
  int people_count, size;
  size = 0;
  node* tmp = this->head;
  while(tmp->next != NULL){
    tmp = tmp->next;
    size++;
  }
  for(people_count = size; people_count >= 0; people_count--){
    delete (*this)[people_count];
  }
}

node* PersonList::append(Person* person){
  node* tmp = new node;
  (*tmp).person = person;
  tmp->next = NULL;

  // First Item Appended
  if(head == NULL){
    // Set the head to the pointer tmp
    head = tmp;
    // Set the tail to the pointer tmp
    tail = tmp;
  }else{
    // Set the tail to the next pointer
    tail->next = tmp;
    // Set the tail to the last pointer
    tail = tmp;
  }
  return(tmp);
}

node* PersonList::operator[](int index){
  // Start at the head
  node* tmp = this->head;
  int index_count = 0;
  while(tmp->next != NULL && index_count != index){
    tmp = tmp->next;
    index_count++;
  }
  return(tmp);
}

void PersonList::swapNodes(int index){
  // Head Special Case
  if((*this)[index] == head){
    // Grab the first node
    node* tmp_first = head;
    // Grab the second node
    node* tmp_second = head->next;
    // Set The Head Node to point to the node after tmp_second
    tmp_first->next = tmp_second->next;
    // Set the New Head Node tmp_second to point to tmp_first
    tmp_second->next = tmp_first;
    // Set tmp_second to the new Head
    head = tmp_second;
  }else{
    node* tmp_prior = (*this)[index - 1];
    node* tmp_first = (*this)[index];
    node* tmp_second = tmp_first->next;
    node* tmp_after = tmp_second->next;

    tmp_prior->next = tmp_second;
    tmp_second->next = tmp_first;
    tmp_first->next = tmp_after;

  }
}


void PersonList::alpha_sort(){
  int number_swaps  = 1;
  int node_counter = 0;
  int total_iterations = 0;
  node* tmp = this->head;
  while(number_swaps != 0){
    node_counter = 0;
    number_swaps = 0;
    // Iterate through the nodes
    tmp = this->head;
    // Iterate to the end of the list
    while(tmp != NULL){
      if(tmp->next == NULL){
        // Handle Tail
        if((*this)[node_counter - 1]->person->getLast()[0] > tmp->person->getLast()[0]){
          swapNodes(node_counter - 1);
          number_swaps++;
        }
        tmp = tmp->next;
        break;
      }
      // Swap if the last name is less then the next last name
      if(tmp->person->getLast()[0] > tmp->next->person->getLast()[0]){
        // Swap any with not in order
        swapNodes(node_counter);
        number_swaps++;
      }
      node_counter++;
      total_iterations++;
      if(tmp->next == NULL)
        break;
      tmp = tmp->next;
    }
    if(total_iterations > 10000)
      break;
  }
}

void PersonList::print(ofstream& out){
  node* tmp = this->head;
  while(tmp != NULL){
    out << tmp->person->print() << endl;
    tmp = tmp->next;
  }
}
