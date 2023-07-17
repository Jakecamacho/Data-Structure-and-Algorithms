# pragma once 
# include <iostream>
# include "Ticket.h"

# define SIZE 100 // defines the size of the queue 

using namespace std;

class ticketQueue{

private:
    int count; 
    ticket **data; // declares data as a pointer to a pointer ticket
public:
    ticketQueue(); // constructor 
    void insert (ticket* item);
    ticket* remove(); //pointer to the remove method
    bool isEmpty();
    bool isFull();
};