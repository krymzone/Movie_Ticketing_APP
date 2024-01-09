#include "VIPEvent.h"
#include <iostream>
#include <fstream>

VIPEvent::VIPEvent(const std::string& eventName, const std::string& eventDate, const std::string& eventTime)
    : Event(eventName, eventDate, eventTime) {}

void VIPEvent::addVIPTicket(const Ticket& ticket) {
    vipTickets.push_back(ticket);
}

void VIPEvent::printVIPTickets() const {
    std::cout << "VIP Tickets Information:" << std::endl;
    for (const auto& ticket : vipTickets) {
        std::cout << "Ticket ID: " << ticket.getTicketID() << ", Type: " << ticket.getTicketType() << std::endl;
    }
}

void VIPEvent::saveTickets(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file for saving tickets." << std::endl;
        return;
    }

    outFile.write(reinterpret_cast<const char*>(this), sizeof(VIPEvent));

    outFile.close();
}

void VIPEvent::loadTickets(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file for loading VIP event tickets." << std::endl;
        return;
    }

    Ticket vipTicket;

    while (inFile.read(reinterpret_cast<char*>(&vipTicket), sizeof(Ticket))) {
        vipTickets.push_back(vipTicket);
    }

    inFile.close();
}
