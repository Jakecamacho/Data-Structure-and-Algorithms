# pragma once 
# include <iostream>
# include "Ticket.h"

using namespace std;

class ticketQueue{

private:
    int count; 
    int size;
    ticket **data; // declares data as a pointer to a pointer ticket
public:
    ticketQueue(int size); // constructor 
    void insert (ticket* item);
    ticket* remove(); //pointer to the remove method
    bool isEmpty();
    bool isFull();
};