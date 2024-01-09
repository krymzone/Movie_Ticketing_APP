#ifndef TICKETMANAGERIMPL_H
#define TICKETMANAGERIMPL_H

#include "TicketManager.h"
#include "Ticket.h"
#include <vector>
#include <string>

class TicketManagerImpl : public TicketManager {
private:
    std::vector<Ticket> tickets;

public:

    const std::vector<Ticket>& getTickets() const;

    void saveTickets(const std::string& filename) const override;
    void loadTickets(const std::string& filename) override;

private:
    void serializeTicket(std::ostream& stream, const Ticket& ticket) const;
    bool deserializeTicket(std::istream& stream, Ticket& ticket) const;
};

#endif // TICKETMANAGERIMPL_H
