# pragma once 
# include <iostream>
# include <string>
# include "Ticket.h"

#define TABLE_SIZE 24 // define table size 
#define PRIME 23 // define prime which is required for double hashing 

using namespace std;

class ticketHashTable{
private:
    ticket** data; // declares data as a pointer to a pointer ticket
    int count;
    int hashFunction(string key);
    int doubleHashFunction(string key);
public:
    ticketHashTable(); //constructor 
    bool isFull();
    bool isEmpty();
    void display();
    void insert(ticket* item);
    ticket* search(string key); //pointer to the search method
    ticket* ticketCompleted(string key);//pointer to the ticktCompleted method
};