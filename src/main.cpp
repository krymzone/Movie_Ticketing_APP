#include "EventLocation.h"
#include "Event.h"
#include "Ticket.h"
#include <iostream>

int main() {
    // Create an event location
    EventLocation location;
    location.setMaxSeats(100);
    location.setNumRows(10);
    location.setNumZones(3);
    location.setSeatsPerRow({ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 });

    // Display event location information
    EventLocation::printLocationInfo(location);

    // Create an event
    Event event("Movie Night", "2023-12-01", "18:00");

    // Display event information
    Event::printEventInfo(event);

    // Generate tickets
    Ticket vipTicket("VIP");
    Ticket lawnTicket("Lawn");
    Ticket tribuneTicket("Tribune");

    // Display ticket information
    Ticket::printTicketInfo(vipTicket);
    Ticket::printTicketInfo(lawnTicket);
    Ticket::printTicketInfo(tribuneTicket);

    // Validate tickets
    std::cout << "Validating tickets:" << std::endl;
    std::cout << "VIP Ticket is " << (vipTicket == vipTicket ? "valid" : "invalid") << std::endl;
    std::cout << "Lawn Ticket is " << (lawnTicket == vipTicket ? "valid" : "invalid") << std::endl;

    return 0;
}
