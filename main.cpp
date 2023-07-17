#include <iostream>
#include <string>
#include "Ticket.h"
#include "TicketQueue.h"
#include "TicketHashTable.h"


using namespace std;

// defined for users to input 
#define COMPLETED "COMPLETED"
#define BACK "BACK"
#define EXIT "EXIT"


int main(){
    cout<< "\n****************************************************************************"<<endl;
    cout<< "\n                               Tickets                                      "<<endl;
    cout<< "\n            Please enter the customers details for each ticket              "<<endl;
    cout<< "\n     Once finished, type 'COMPLETED' to stop adding ticket to the list      "<<endl;
    cout<< "\n****************************************************************************"<<endl;
    //defined as they are used within the while loops and helps to break out of these depending on the users input
    bool taskInput = true;
    bool applicationRunning = true;
    bool ticketListMenu = true;

    ticketQueue *ticketList = new ticketQueue(); //initalises the priority queue 

    while (taskInput){ // loops through until a users enters one of the values assigned above 
        string userName;
        string userNumber;
        int userCollectionTime;
        string assigned;

        cout << "Name: "<<endl;
        getline(cin, userName);

        if (userName == COMPLETED){ // if the users enters this value then it will break out the while loop 
            taskInput = false;
            break;
        }

        cout << "Contact Number: "<<endl;
        cin >> userNumber;
        getline(cin, userNumber);
        cout << "Collection time: "<<endl;
        cin >> userCollectionTime;
        cin.ignore();
        cin.clear();
        cout << "Assigned: "<<endl;
        getline(cin, assigned);

        cout<< "Ticket has been sent to the queue to be added! Please add any further tickets or input 'COMPLETED' "<<endl;

        ticketList->insert(new ticket(userCollectionTime, userName, userNumber, assigned)); // inserts the inputs into the priority queue 

    }

    cout<< "\n****************************************************************************"<<endl;
    cout<< "\n                               Ticket Items                                 "<<endl;

    ticketHashTable *ticketTable = new ticketHashTable(); // initialises the hash table 


    while(!ticketList-> isEmpty()){ //loops through the items in the priority queue
        ticket *item = ticketList->remove(); //removes the top item in the priority queue and displays its details 
        cout<< "Collection Time:"<< item->collection_time << "\n Name:"<< item->name << "\t Contact Number:"<< item->contact_number<< "\t Assigned to:" << item->assigned<<endl;
        ticketTable->insert(item); // inserts item into the hash table 
    }   
    
    while (applicationRunning){
        string userInput;
        cout<< "\n****************************************************************************"<<endl;
        cout<< "\n                    Search, Complete or View tickets?                       "<<endl;
        cout<< "\n       Type 'BACK' if you wish to view your ticket list in order            "<<endl;
        cout<< "\n****************************************************************************"<<endl;


        cout<< "Please select from one of the options below:"<<endl;
        cout<< "1: Search" <<endl;
        cout<< "2: Complete" <<endl;
        cout<< "3: View tickets" <<endl;

        cin >> userInput;
        cin.ignore();
        cin.clear();

        
        if(userInput == BACK){ // if user inputs back it will exit the while loop 
            applicationRunning = false;
            break;
        }

        while(ticketListMenu){
            if (userInput == "1"){
                string searchInput;
                ticket *ticketToSearch;

                cout<< "\n****************************************************************************"<<endl;
                cout<< "\n                                Search                                      "<<endl;
                cout<< "\n       Type 'BACK' if you wish to perform a different operation             "<<endl;
                cout<< "\n****************************************************************************"<<endl;

                cout<< "\n Search by Name(1) or Assigned(2)?"<<endl;
                cin >> searchInput;
                cin.ignore();
                cin.clear();

                if(searchInput == "1"){
                    string nameInput;
                    cout<< "Input customers Name:"<<endl;
                    getline(cin, nameInput);

                    ticketToSearch = ticketTable->search(nameInput); // searches the hash table for the name the user has inputted
                    if(ticketToSearch && ticketToSearch->name == nameInput){
                        cout<< "Ticket Found!"<<endl;
                        cout<< "Name: "<< ticketToSearch->name<<endl;
                        cout<< "Contact Number: "<< ticketToSearch->contact_number<<endl;
                        cout<< "Collection Time: "<< ticketToSearch->collection_time<<endl;
                        cout<< "Assigned to: "<< ticketToSearch->assigned<<endl;
                    }
                    else{
                        cout<< "Apologies, this ticket could not be found" <<endl;
                    }
                }
                if (searchInput == "2"){
                    cout<< "Input name of assignee:"<<endl;
                    getline(cin, searchInput);

                    ticketToSearch = ticketTable->search(searchInput); // searches the hash table for the name the user has inputted
                    if(ticketToSearch && ticketToSearch->assigned == searchInput){
                        cout<< "Ticket Found!"<<endl;
                        cout<< "Name: "<< ticketToSearch->name<<endl;
                        cout<< "Contact Number: "<< ticketToSearch->contact_number<<endl;
                        cout<< "Collection Time: "<< ticketToSearch->collection_time<<endl;
                        cout<< "Assigned to: "<< ticketToSearch->assigned<<endl;
                    }
                    else{
                        cout<< "Apologies, this ticket could not be found" <<endl;
                    }

                }
                if(searchInput == "BACK"){
                    ticketListMenu = false;
                    break;
                }
                else{
                    cout<< "It looks like you have entered an incorrect value, please try again!"<<endl;
                    break;
                }

            }
            if (userInput == "2"){
                string completeInput;
                ticket *ticketToComplete;
                cout<< "\n****************************************************************************"<<endl;
                cout<< "\n                         Complete a task?                                   "<<endl;
                cout<< "\n       Type 'BACK' if you wish to view your ticket list in order            "<<endl;
                cout<< "\n****************************************************************************"<<endl;
            
                cout<< "\n Enter the Name or Assignee associated with the ticket you wish to mark as completed:"<<endl;
                getline(cin, completeInput);

                if (completeInput == "BACK"){
                    break;
                }

                ticketToComplete = ticketTable->ticketCompleted(completeInput); // searches the hash table for the name the user has inputted
                if(ticketToComplete && ticketToComplete->name == completeInput){
                    cout<< "\n The Ticket has been found and marked as completed! Your table with uncomplete tickets can be seen below "<<endl;
                    if ((ticketTable->isEmpty()) == 0){
                        cout<<"\n It looks like you have no tickets left to complete.... Keep up the great work!"<<endl;
                        break;
                    }
                    else{
                        ticketTable->display(); // displays the tickettable only if it has values in it 
                    }
                }
                else{
                    cout<< "\n I am sorry but this ticket could not be found, try another name or email address!"<<endl;
                    break;
                }
            }
            if (userInput == "3"){
                string tableViewInput;
                cout<< "\n****************************************************************************"<<endl;
                cout<< "\n                         Table of Tickets                                   "<<endl;
                cout<< "\n****************************************************************************"<<endl;

                ticketTable->display(); // view entries in table 
                break;

            }
            else{
                cout<< "It looks like you have entered an incorrect value, please try again!"<<endl;
                break;
            }
        }
    }
}