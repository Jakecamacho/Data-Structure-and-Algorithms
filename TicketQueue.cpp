# include <iostream>
# include "Ticket.h"
# include "TicketQueue.h"


ticketQueue :: ticketQueue(){
    data = new ticket *[SIZE];
    count = 0;
}

void ticketQueue :: insert(ticket* item){
    if (isEmpty() == true) {
        data[count++] = item;
    }
    else{
        int t;
        for (t = (count -1); t >= 0; t--){
            if (*item < *data[t]) {
                data[t + 1] = data[t];               
            }
            else{
                break;
            }
            data[t + 1] = item;
            count++;
        }
    }
}

ticket* ticketQueue :: remove(){
    return data[count--];
}

bool ticketQueue :: isFull(){
    return count == SIZE;
}

bool ticketQueue :: isEmpty(){
    return count == 0;
}