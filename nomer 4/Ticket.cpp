#include "Ticket.h"
#include <stdexcept>

int Ticket::count = 0;

Ticket::Ticket(const std::string& name) {
    if (count >= MAX_SEATS) {
        throw std::overflow_error("No seats available in the train car.");
    }
    passengerName = name;
    count++;
}

Ticket::~Ticket() {
    if (count > 0) count--;
}

std::string Ticket::getName() const {
    return passengerName;
}
