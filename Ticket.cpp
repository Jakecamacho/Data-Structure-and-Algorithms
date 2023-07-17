# include <iostream>
# include "Ticket.h"

using namespace std;

ticket :: ticket(int collection_time,string name, string contact_number, string assigned): collection_time(collection_time), name(name), contact_number(contact_number), assigned(assigned){

}

bool ticket :: operator< (const ticket& rhd) {
    return this->collection_time < rhd.collection_time; // used to overload the '<' operator and works by comparing two ticket references and ordering them by collection time in ascending order.
}
