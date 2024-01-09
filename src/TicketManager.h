#ifndef TICKETMANAGER_H
#define TICKETMANAGER_H

#include <string>

class TicketManager {
public:
    virtual ~TicketManager() = default;

    virtual void saveTickets(const std::string& filename) const = 0;
    virtual void loadTickets(const std::string& filename) = 0;
};

#endif // TICKETMANAGER_H
