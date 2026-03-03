#pragma once
#include <string>

class Ticket {
private:
    std::string passengerName;
    static int count;
    static const int MAX_SEATS = 60;

public:
    Ticket(const std::string& name);
    ~Ticket();
    std::string getName() const;
};
