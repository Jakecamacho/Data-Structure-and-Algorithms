# pragma once 
# include <iostream>
# include "Ticket.h"

# define SIZE 35

using namespace std;

class ticketQueue{

private:
    int count; 
    ticket** data;
public:
    ticketQueue();
    void insert (ticket* item);
    ticket* remove();
    bool isEmpty();
    bool isFull();
};