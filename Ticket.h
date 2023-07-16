# pragma once 
# include <iostream>

using namespace std;

class ticket{
public:
    string name;
    string contact_number;
    int collection_time;
    string assigned;
    ticket(int collection_time, string name, string contact_number, string assigned);
    bool operator<(const ticket& rhd);
};