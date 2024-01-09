#include "EventLocation.h"
#include <iostream>
#include <fstream>

EventLocation::EventLocation() : maxSeats(0), numRows(0), numZones(0) {}

EventLocation::EventLocation(int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow)
    : maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow) {}

int EventLocation::getMaxSeats() const { return maxSeats; }

int EventLocation::getNumRows() const { return numRows; }

int EventLocation::getNumZones() const { return numZones; }

const std::vector<int>& EventLocation::getSeatsPerRow() const { return seatsPerRow; }

void EventLocation::displaySeatingArrangement() const {
    std::cout << "Seating Arrangement:" << std::endl;
    for (int row = 0; row < numRows; ++row) {
        for (int seat = 0; seat < seatsPerRow[row]; ++seat) {
            std::cout << (isSeatAvailable(row, seat) ? '0' : '1') << " ";
        }
        std::cout << std::endl;
    }
}

int EventLocation::getAvailableSeats() const {
    int availableSeats = 0;
    for (int row = 0; row < numRows; ++row) {
        for (int seat = 0; seat < seatsPerRow[row]; ++seat) {
            if (isSeatAvailable(row, seat)) {
                ++availableSeats;
            }
        }
    }
    return availableSeats;
}

bool EventLocation::isSeatAvailable(int row, int seat) const {
    if (row < 1 || row > numRows || seat < 1 || seat > seatsPerRow[row - 1]) {
        return false; // Invalid row or seat
    }

    return !seatingArrangement[row - 1][seat - 1]; // Check if the seat is occupied
}

void EventLocation::markSeatOccupied(int row, int seat) {
    // Mark the seat as occupied
    seatingArrangement[row - 1][seat - 1] = true;
}

void EventLocation::setMaxSeats(int maxSeats) {
    if (maxSeats > 0) {
        this->maxSeats = maxSeats;
    }
    else {
        std::cerr << "Error: Maximum seats must be greater than 0." << std::endl;
    }
}

void EventLocation::setNumRows(int numRows) {
    if (numRows > 0) {
        this->numRows = numRows;
    }
    else {
        std::cerr << "Error: Number of rows must be greater than 0." << std::endl;
    }
}

void EventLocation::setNumZones(int numZones) {
    if (numZones > 0) {
        this->numZones = numZones;
    }
    else {
        std::cerr << "Error: Number of zones must be greater than 0." << std::endl;
    }
}

void EventLocation::setSeatsPerRow(const std::vector<int>& seatsPerRow) {
    this->seatsPerRow = seatsPerRow;
}

void EventLocation::printLocationInfo() const {
    std::cout << "Location Information:" << std::endl;
    std::cout << "Max Seats: " << maxSeats << std::endl;
    std::cout << "Number of Rows: " << numRows << std::endl;
    std::cout << "Number of Zones: " << numZones << std::endl;
    std::cout << "Seats per Row: ";
    for (const auto& seats : this->seatsPerRow) {  // Use this->seatsPerRow
        std::cout << seats << " ";
    }
    std::cout << std::endl;
}

void EventLocation::saveTickets(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file for saving tickets." << std::endl;
        return;
    }

    // Serialize and save location-specific ticket information to the file
    outFile.write(reinterpret_cast<const char*>(this), sizeof(EventLocation));

    outFile.close();
}

void EventLocation::loadTickets(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file for loading tickets." << std::endl;
        return;
    }

    inFile.read(reinterpret_cast<char*>(&maxSeats), sizeof(maxSeats));
    inFile.read(reinterpret_cast<char*>(&numRows), sizeof(numRows));
    inFile.read(reinterpret_cast<char*>(&numZones), sizeof(numZones));

    for (auto& seatsInRow : this->seatsPerRow) {  // Use this->seatsPerRow
        inFile.read(reinterpret_cast<char*>(&seatsInRow), sizeof(seatsInRow));
    }

    inFile.close();
}
