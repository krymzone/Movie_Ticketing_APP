#ifndef VIPEVENT_H
#define VIPEVENT_H

#include "Event.h"
#include "Ticket.h"
#include "TicketManager.h"
#include <vector>

class VIPEvent : public Event, public TicketManager {
private:
    std::vector<Ticket> vipTickets;

public:
    VIPEvent(const std::string& eventName, const std::string& eventDate, const std::string& eventTime);

    void addVIPTicket(const Ticket& ticket);
    void printVIPTickets() const;

    void saveTickets(const std::string& filename) const override;
    void loadTickets(const std::string& filename) override;
};

#endif
