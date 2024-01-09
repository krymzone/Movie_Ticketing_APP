#include "Ticket.h"
#include <iostream>
#include <fstream>

int Ticket::nextTicketID = 1;

// Default constructor definition
Ticket::Ticket() : ticketID(nextTicketID++), ticketType("Default"), row(0), seat(0) {}

Ticket::Ticket(const std::string& ticketType) : ticketID(nextTicketID++), ticketType(ticketType), row(0), seat(0) {}

// Parameterized constructor definition
Ticket::Ticket(const std::string& ticketType, int row, int seat)
    : ticketID(nextTicketID++), ticketType(ticketType), row(row), seat(seat) {}

int Ticket::getTicketID() const { return ticketID; }

const std::string& Ticket::getTicketType() const { return ticketType; }

void Ticket::setTicketType(const std::string& ticketType) {
    this->ticketType = ticketType;
}

void Ticket::printTicketInfo() const {
    std::cout << "Ticket Information:" << std::endl;
    std::cout << "Ticket ID: " << ticketID << std::endl;
    std::cout << "Ticket Type: " << ticketType << std::endl;
    std::cout << "Seat: " << seat << ", Row: " << row << std::endl;
}

bool Ticket::operator==(const Ticket& other) const {
    return (this->ticketID == other.ticketID);
}

void Ticket::saveTickets(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);  // Use std::ios::app to append to the file

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file for saving tickets." << std::endl;
        return;
    }

    // Serialize and save ticket-specific information to the file
    outFile.write(reinterpret_cast<const char*>(this), sizeof(Ticket));

    outFile.close();
}

void Ticket::loadTickets(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file for loading tickets." << std::endl;
        return;
    }

    // Deserialize and load ticket-specific information from the file
    inFile.read(reinterpret_cast<char*>(this), sizeof(Ticket));

    inFile.close();
}
