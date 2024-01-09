#ifndef TICKET_H
#define TICKET_H

#include "TicketManager.h"  // Include the new abstract class
#include <string>

class Ticket : public TicketManager {
private:
    static int nextTicketID;
    int ticketID;
    std::string ticketType;
    int row;
    int seat;

public:
    // Constructors
    Ticket();
    Ticket(const std::string& ticketType);  // New constructor
    Ticket(const std::string& ticketType, int row, int seat);

    // Accessors
    int getTicketID() const;
    const std::string& getTicketType() const;

    // Mutator
    void setTicketType(const std::string& ticketType);

    // Additional functions
    void printTicketInfo() const;
    bool operator==(const Ticket& other) const;

    // Implement pure virtual methods from TicketManager
    void saveTickets(const std::string& filename) const override;
    void loadTickets(const std::string& filename) override;

    // Destructor
    ~Ticket() = default; // Add a destructor

    // Add other overloaded operators as needed...
};

#endif // TICKET_H
