# pragma once 
# include <iostream>
# include <string>
# include "Ticket.h"

#define TABLE_SIZE 24
#define PRIME 23

using namespace std;

class ticketHashTable{
private:
    ticket** data;
    int count;
    int hashFunction(string key);
    int doubleHashFunction(string key);
public:
    ticketHashTable();
    bool isFull();
    bool isEmpty();
    void display();
    void insert(ticket* item);
    ticket* search(string key);
    ticket* ticketCompleted(string key);
};