#include "TicketManagerImpl.h"
#include <iostream>
#include <fstream>

const std::vector<Ticket>& TicketManagerImpl::getTickets() const {
    return tickets;
}

void TicketManagerImpl::saveTickets(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file for saving tickets." << std::endl;
        return;
    }

    // Serialize and save ticket information to the file
    for (const Ticket& ticket : tickets) {
        serializeTicket(outFile, ticket);
    }

    outFile.close();
}

void TicketManagerImpl::loadTickets(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file for loading tickets." << std::endl;
        return;
    }

    // Deserialize and load ticket information from the file
    Ticket ticket;
    while (deserializeTicket(inFile, ticket)) {
        tickets.push_back(ticket);
    }

    inFile.close();
}

void TicketManagerImpl::serializeTicket(std::ostream& stream, const Ticket& ticket) const {
    stream.write(reinterpret_cast<const char*>(&ticket), sizeof(Ticket));
}

bool TicketManagerImpl::deserializeTicket(std::istream& stream, Ticket& ticket) const {
    if (stream.read(reinterpret_cast<char*>(&ticket), sizeof(Ticket))) {
        return true;
    }
    return false;
}
