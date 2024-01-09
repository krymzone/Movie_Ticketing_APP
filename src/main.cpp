#include "EventLocation.h"
#include "Event.h"
#include "Ticket.h"
#include "VIPEvent.h"
#include "TicketManagerImpl.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void displayAvailableSeats(const EventLocation& location) {
    std::cout << "Number of available seats: " << location.getAvailableSeats() << std::endl;
    location.displaySeatingArrangement();
}

void generateTickets(EventLocation& location) {

    int numSeats;
    std::cout << "Enter the number of seats you want: ";
    std::cin >> numSeats;

    for (int i = 0; i < numSeats; ++i) {
        int row, seat;
        std::cout << "Enter the coordinates for seat " << i + 1 << " (row seat): ";
        std::cin >> row >> seat;

        if (location.isSeatAvailable(row, seat)) {
            location.markSeatOccupied(row, seat);

            Ticket ticket("Custom Ticket", row, seat);
            ticket.printTicketInfo();
        }
        else {
            std::cout << "Seat is already occupied or invalid. Choose another seat." << std::endl;
            --i;
        }
    }

    displayAvailableSeats(location);
}

int main() {
    EventLocation location;
    location.setMaxSeats(100);
    location.setNumRows(10);
    location.setNumZones(3);
    location.setSeatsPerRow({ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 });

    Event event("Movie Night", "2023-12-01", "18:00");

    Ticket vipTicket("VIP");
    Ticket lawnTicket("Lawn");
    Ticket tribuneTicket("Tribune");

    std::cout << "Validating tickets:" << std::endl;
    std::cout << "VIP Ticket is " << (vipTicket == vipTicket ? "valid" : "invalid") << std::endl;
    std::cout << "Lawn Ticket is " << (lawnTicket == vipTicket ? "valid" : "invalid") << std::endl;

    VIPEvent vipEvent("VIP Movie Night", "2023-12-01", "18:00");

    vipEvent.addVIPTicket(vipTicket);
    vipEvent.addVIPTicket(Ticket("VIP"));

    TicketManagerImpl ticketManager;

    int choice = 0;

    while (choice != 8) {
        clearScreen();

        std::cout << "Menu:" << std::endl;
        std::cout << "1. Display event location information" << std::endl;
        std::cout << "2. Display event information" << std::endl;
        std::cout << "3. Generate tickets and display ticket information" << std::endl;
        std::cout << "4. Validate tickets" << std::endl;
        std::cout << "5. Display VIP Event information and tickets" << std::endl;
        std::cout << "6. Save tickets to file" << std::endl;
        std::cout << "7. Load tickets from file" << std::endl;
        std::cout << "8. Exit" << std::endl;

        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            location.printLocationInfo();
            break;

        case 2:
            event.printEventInfo();
            break;

        case 3:
            displayAvailableSeats(location);
            generateTickets(location);
            break;

        case 4:
            std::cout << "VIP Ticket is " << (vipTicket == vipTicket ? "valid" : "invalid") << std::endl;
            std::cout << "Lawn Ticket is " << (lawnTicket == vipTicket ? "valid" : "invalid") << std::endl;
            break;

        case 5:
            event.printEventInfo();
            vipEvent.printVIPTickets();
            break;

        case 6:
            ticketManager.saveTickets("ticket_data.bin");
            std::cout << "Tickets saved to file." << std::endl;
            break;

        case 7:
            ticketManager.loadTickets("ticket_data.bin");
            std::cout << "Tickets loaded from file." << std::endl;
            break;

        case 8:
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }

        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}
