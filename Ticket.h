# pragma once 
# include <iostream>

using namespace std;

class ticket{
public:
    string name;
    string contact_number;
    int collection_time;
    string assigned;
    ticket(int collection_time, string name, string contact_number, string assigned); // ticket method with four variables passed in 
    bool operator< (const ticket& rhd); // used to overload the '<' operator and works by comparing two ticket references. and ordering them by collection time in ascending order 
};