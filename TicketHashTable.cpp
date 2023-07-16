# include <iostream>
# include <string>
# include "Ticket.h"
# include "TicketHashTable.h"

int ticketHashTable ::hashFunction(string key){
    int ASCIITotal = 0;
    for (int t =0; t < key.length(); t++){
        ASCIITotal += (int)key[t];
    }
    return ASCIITotal % TABLE_SIZE;
}


int ticketHashTable :: doubleHashFunction(string key){
    int ASCIIKey = hashFunction(key);
    return PRIME - (ASCIIKey % TABLE_SIZE);     
}

ticketHashTable :: ticketHashTable(){
    data = new ticket*[TABLE_SIZE];
    for (int t = 0; t< TABLE_SIZE; t++){
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
    for (int t = 0; t < TABLE_SIZE; t++){
        if(data[t] != NULL){
            cout<< "Index" << t << "\n Name:" <<data[t]->name << "\n Contact Number:" <<data[t]->contact_number<< "\n Assignee:" <<data[t]->collection_time<<"\n Collection Time:" <<data[t]->assigned<<endl;
        }
    }   
}

void ticketHashTable :: insert(ticket* item){
    if (isFull()){
        return;
    }
    string key = item->name;
    int hash = hashFunction(key);

    if (data[hash] != NULL){
        int doubleHash = doubleHashFunction(key);
        int index = 1;
        while(true){
            int newHash = (hash+index*doubleHash) % TABLE_SIZE;
            if (data[newHash] != NULL){
                data[newHash] = item;
                break;
            }
            index++;
        }
    }
    else{
        data[hash] = item;
    }
    count++;   
}

ticket *ticketHashTable :: ticketCompleted(string key){
    int hash = hashFunction(key);
    int doubleHash = doubleHashFunction(key);
    int index = 0;

    while (data [(hash + index * doubleHash) % TABLE_SIZE] != NULL){
        ticket *item = data [(hash + index * doubleHash) % TABLE_SIZE];
        if (item->name ==key){
            data [(hash + index * doubleHash) % TABLE_SIZE] = NULL;
            return item;
        }
        index++;
    }
        
    return NULL;
}

ticket *ticketHashTable :: search(string key){
    int hash = hashFunction(key);
    int doubleHash = doubleHashFunction(key);
    int index = 0;

    while (data [(hash + index * doubleHash) % TABLE_SIZE] != NULL){
        ticket *item = data [(hash + index * doubleHash) % TABLE_SIZE];
        if (item->name == key){
            data[(hash + index * doubleHash) % TABLE_SIZE] = NULL;
            return item;
        }
        index++;
    }
    return NULL; 
}