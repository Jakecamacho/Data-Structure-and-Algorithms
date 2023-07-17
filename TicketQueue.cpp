# include <iostream>
# include "Ticket.h"
# include "TicketQueue.h"


ticketQueue :: ticketQueue(int size){
    data = new ticket *[size]; // constructor which uses the size parameter to initalise the queue 
    count = 0;
}

void ticketQueue :: insert(ticket* item){
    if (isEmpty() == true) {
        data[count++] = item; //checks if the queue is empty and adds the item
    }
    else{ // if the queue is not empty, then it loops through all items in the queue 
        int t;
        for (t = (count -1); t >= 0; t--){
            if (*item < *data[t]) {   //if the new item has a greater collection time value than the items in the queue 
                data[t + 1] = data[t];    // then it will move this down in the queue to a different index             
            }
            else{
                break;
            }
            data[t + 1] = item; // this adds the item to the correct place within the queue.
            count++;
        }
    }
}

ticket* ticketQueue :: remove(){
    return data[count--];
}

bool ticketQueue :: isFull(){
    return count == size;
}

bool ticketQueue :: isEmpty(){
    return count == 0;
}
