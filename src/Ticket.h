#ifndef TICKET_H
#define TICKET_H

#include "TicketManager.h"
#include <string>

class Ticket : public TicketManager {
private:
    static int nextTicketID;
    int ticketID;
    std::string ticketType;
    int row;
    int seat;

public:
    Ticket();
    Ticket(const std::string& ticketType);
    Ticket(const std::string& ticketType, int row, int seat);

    int getTicketID() const;
    const std::string& getTicketType() const;

    void setTicketType(const std::string& ticketType);

    void printTicketInfo() const;
    bool operator==(const Ticket& other) const;

    void saveTickets(const std::string& filename) const override;
    void loadTickets(const std::string& filename) override;

    ~Ticket() = default;

};

#endif
