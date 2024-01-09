#include "EventLocation.h"
#include "Event.h"
#include "Ticket.h"
#include "VIPEvent.h"
#include "TicketManagerImpl.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

// Function to clear the terminal screen (Linux/Unix and Windows)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to display available seats and current seating arrangement
void displayAvailableSeats(const EventLocation& location) {
    std::cout << "Number of available seats: " << location.getAvailableSeats() << std::endl;
    location.displaySeatingArrangement();
}

// Function to generate tickets interactively
void generateTickets(EventLocation& location) {
    // Generate tickets

    int numSeats;
    std::cout << "Enter the number of seats you want: ";
    std::cin >> numSeats;

    for (int i = 0; i < numSeats; ++i) {
        int row, seat;
        std::cout << "Enter the coordinates for seat " << i + 1 << " (row seat): ";
        std::cin >> row >> seat;

        // Check if the seat is available
        if (location.isSeatAvailable(row, seat)) {
            location.markSeatOccupied(row, seat);

            // Display the ticket information
            Ticket ticket("Custom Ticket", row, seat);
            ticket.printTicketInfo();
        }
        else {
            std::cout << "Seat is already occupied or invalid. Choose another seat." << std::endl;
            --i;  // Decrement i to re-enter coordinates for the same seat
        }
    }

    // Display available seats after generating tickets
    displayAvailableSeats(location);
}

int main() {
    // Create an event location
    EventLocation location;
    location.setMaxSeats(100);
    location.setNumRows(10);
    location.setNumZones(3);
    location.setSeatsPerRow({ 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 });

    // Create an event
    Event event("Movie Night", "2023-12-01", "18:00");

    // Generate tickets
    Ticket vipTicket("VIP");
    Ticket lawnTicket("Lawn");
    Ticket tribuneTicket("Tribune");

    // Validate tickets
    std::cout << "Validating tickets:" << std::endl;
    std::cout << "VIP Ticket is " << (vipTicket == vipTicket ? "valid" : "invalid") << std::endl;
    std::cout << "Lawn Ticket is " << (lawnTicket == vipTicket ? "valid" : "invalid") << std::endl;

    // Create an instance of VIPEvent
    VIPEvent vipEvent("VIP Movie Night", "2023-12-01", "18:00");

    // Add VIP tickets to the VIPEvent
    vipEvent.addVIPTicket(vipTicket);
    vipEvent.addVIPTicket(Ticket("VIP"));

    // Create an instance of TicketManagerImpl for saving/loading tickets
    TicketManagerImpl ticketManager;

    int choice = 0;

    while (choice != 8) {
        // Clear the screen before displaying the menu
        clearScreen();

        // Display the menu
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Display event location information" << std::endl;
        std::cout << "2. Display event information" << std::endl;
        std::cout << "3. Generate tickets and display ticket information" << std::endl;
        std::cout << "4. Validate tickets" << std::endl;
        std::cout << "5. Display VIP Event information and tickets" << std::endl;
        std::cout << "6. Save tickets to file" << std::endl;
        std::cout << "7. Load tickets from file" << std::endl;
        std::cout << "8. Exit" << std::endl;

        // Get user choice
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            // Display event location information
            location.printLocationInfo();
            break;

        case 2:
            // Display event information
            event.printEventInfo();
            break;

        case 3:
            // Generate tickets
            displayAvailableSeats(location);
            generateTickets(location);
            break;

        case 4:
            // Validate tickets
            std::cout << "VIP Ticket is " << (vipTicket == vipTicket ? "valid" : "invalid") << std::endl;
            std::cout << "Lawn Ticket is " << (lawnTicket == vipTicket ? "valid" : "invalid") << std::endl;
            break;

        case 5:
            // Display VIP Event information and tickets
            event.printEventInfo();
            vipEvent.printVIPTickets();
            break;

        case 6:
            // Save tickets to file
            ticketManager.saveTickets("ticket_data.bin");
            std::cout << "Tickets saved to file." << std::endl;
            break;

        case 7:
            // Load tickets from file
            ticketManager.loadTickets("ticket_data.bin");
            std::cout << "Tickets loaded from file." << std::endl;
            break;

        case 8:
            // Exit
            std::cout << "Exiting the program." << std::endl;
            break;

        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }

        // Wait for the user to press Enter before clearing the screen
        std::cout << "Press Enter to continue...";
        std::cin.ignore();
        std::cin.get();
    }

    return 0;
}
