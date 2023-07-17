# include <iostream>
# include <string>
# include "Ticket.h"
# include "TicketHashTable.h"

int ticketHashTable ::hashFunction(string key){
    int ASCIITotal = 0;
    for (int t =0; t < key.length(); t++){
        ASCIITotal += (int)key[t]; // works by casting a string to the ASCII int value 
    }
    return ASCIITotal % TABLE_SIZE; // returns hash key 
}


int ticketHashTable :: doubleHashFunction(string key){ //second hash function 
    int ASCIIKey = hashFunction(key); // uses the return value from the first hashfunction to re-key
    return PRIME - (ASCIIKey % TABLE_SIZE);     
}

ticketHashTable :: ticketHashTable(){
    data = new ticket*[TABLE_SIZE];
    for (int t = 0; t< TABLE_SIZE; t++){ // works by initialising the hash table and setting each value to NULL
        data[t] = NULL;
    }   
}

bool ticketHashTable :: isEmpty(){
    return count == 0;
}

bool ticketHashTable :: isFull(){
    return count == TABLE_SIZE;
}

void ticketHashTable :: display(){
    cout << '\n';
    for (int t = 0; t < TABLE_SIZE; t++){ //loop through every value in the table
        if(data[t] != NULL){ // if the value is not equal to null, then display the value 
            cout<< "Index" << t << "\n Name:" <<data[t]->name << "\n Contact Number:" <<data[t]->contact_number<< "\n Assignee:" <<data[t]->collection_time<<"\n Collection Time:" <<data[t]->assigned<<endl;
        }
    }   
}

void ticketHashTable :: insert(ticket* item){
    if (isFull()){ // uses the is full method to check whether the table has availability 
        return;
    }
    string key = item->name;
    int hash = hashFunction(key); // uses the hashfunction method to retrieve the value of the ticket key 

    if (data[hash] != NULL){
        int doubleHash = doubleHashFunction(key); // this then says if there is a collison, look to re-key and get a second hash 
        int index = 1;
        while(true){
            int newHash = (hash+index*doubleHash) % TABLE_SIZE; 
            if (data[newHash] != NULL){ // if there are no collisons, insert the item into the table 
                data[newHash] = item;
                break;
            }
            index++;
        }
    }
    else{
        data[hash] = item; // if there are no collisons, insert the item into the table 
    }
    count++;   
}

ticket *ticketHashTable :: ticketCompleted(string key){ //removes an item from the hash table 
    int hash = hashFunction(key); //gets the hash values to search for 
    int doubleHash = doubleHashFunction(key);
    int index = 0;

    while (data [(hash + index * doubleHash) % TABLE_SIZE] != NULL){ // loops through the table as long as it has items within it
        ticket *item = data [(hash + index * doubleHash) % TABLE_SIZE];
        if (item->name ==key){ 
            data [(hash + index * doubleHash) % TABLE_SIZE] = NULL;
            return item;// return the item
        }
        index++;
    }
        
    return NULL;
}

ticket *ticketHashTable :: search(string key){ // allows for a task to be searched for within the table
    int hash = hashFunction(key); //gets the hash values to search for 
    int doubleHash = doubleHashFunction(key); // loops through the table as long as it has items within it 
    int index = 0;

    while (data [(hash + index * doubleHash) % TABLE_SIZE] != NULL){ // loops through the table as long as it has items within it 
        ticket *item = data [(hash + index * doubleHash) % TABLE_SIZE];
        if (item->name == key){ // if the item is found 
            data[(hash + index * doubleHash) % TABLE_SIZE] = NULL;
            return item; // return the item
        }
        index++; // removes the item
    }
    return NULL; 
}