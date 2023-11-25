#ifndef TICKET_H
#define TICKET_H

#include <vector>
#include <string>

class Ticket {
private:
    static int nextTicketID;
    const int ticketID;
    std::string ticketType;
    // Add other ticket-related attributes as needed

public:
    Ticket();
    Ticket(const std::string& ticketType);

    // Accessors
    int getTicketID() const;
    const std::string& getTicketType() const;

    // Validation functions
    void setTicketType(const std::string& ticketType);

    // Other methods
    static void printTicketInfo(const Ticket& ticket);
    void processTicketData();

    // Overloaded operators
    bool operator==(const Ticket& other) const;
    // Add other overloaded operators as needed...
};

#endif // TICKET_H
