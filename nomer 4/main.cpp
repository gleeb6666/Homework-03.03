#include <iostream>
#include "Ticket.h"

int main() {
    Ticket* tickets[60];
    int n = 0;

    tickets[n++] = new Ticket("John Smith");
    tickets[n++] = new Ticket("Mary Johnson");
    tickets[n++] = new Ticket("Bob Williams");

    std::cout << "Tickets sold: " << n << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << "Ticket: " << i << " Passenger: " << tickets[i]->getName() << std::endl;
    }

    std::cout << "--------------------" << std::endl;

    try {
        for (int i = n; i < 60; i++) {
            tickets[i] = new Ticket("Passenger");
            n++;
            if (i > 56) {
                std::cout << "Tickets sold: " << n << std::endl;
                std::cout << "Ticket: " << i << " Passenger: " << tickets[i]->getName() << i << std::endl;
            }
        }
        
     tickets[n] = new Ticket("Passenger");
    }
    catch (const std::overflow_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    for (int i = 0; i < n; i++) {
        delete tickets[i];
    }

    return 0;
}
