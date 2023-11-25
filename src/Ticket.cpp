#include "Ticket.h"
#include <iostream>

int Ticket::nextTicketID = 1;

Ticket::Ticket() : ticketID(nextTicketID++) {}

Ticket::Ticket(const std::string& ticketType) : ticketID(nextTicketID++), ticketType(ticketType) {}

int Ticket::getTicketID() const { return ticketID; }

const std::string& Ticket::getTicketType() const { return ticketType; }

void Ticket::setTicketType(const std::string& ticketType) {
    // Add validation logic for ticket type
    this->ticketType = ticketType;
}

void Ticket::printTicketInfo(const Ticket& ticket) {
    // Print ticket information based on requirements
    std::cout << "Ticket Information:" << std::endl;
    // Print other details...
}

void Ticket::processTicketData() {
    // Perform processing based on specific requirements
}

bool Ticket::operator==(const Ticket& other) const {
    return (this->ticketID == other.ticketID);
}

// Implement other methods and operators as needed...
