#include "EventLocation.h"
#include <iostream>

EventLocation::EventLocation() : maxSeats(0), numRows(0), numZones(0) {}

EventLocation::EventLocation(int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow)
    : maxSeats(maxSeats), numRows(numRows), numZones(numZones), seatsPerRow(seatsPerRow) {}

int EventLocation::getMaxSeats() const { return maxSeats; }

int EventLocation::getNumRows() const { return numRows; }

int EventLocation::getNumZones() const { return numZones; }

const std::vector<int>& EventLocation::getSeatsPerRow() const { return seatsPerRow; }

void EventLocation::setMaxSeats(int maxSeats) {
    if (maxSeats > 0) {
        this->maxSeats = maxSeats;
    } else {
        std::cerr << "Error: Maximum seats must be greater than 0." << std::endl;
    }
}

void EventLocation::setNumRows(int numRows) {
    if (numRows > 0) {
        this->numRows = numRows;
    } else {
        std::cerr << "Error: Number of rows must be greater than 0." << std::endl;
    }
}

void EventLocation::setNumZones(int numZones) {
    if (numZones > 0) {
        this->numZones = numZones;
    } else {
        std::cerr << "Error: Number of zones must be greater than 0." << std::endl;
    }
}

void EventLocation::setSeatsPerRow(const std::vector<int>& seatsPerRow) {
    // Validation logic can be added based on specific requirements
    this->seatsPerRow = seatsPerRow;
}

void EventLocation::printLocationInfo(const EventLocation& location) {
    // Print location information based on requirements
    std::cout << "Location Information:" << std::endl;
    // Print other details...
}

void EventLocation::processLocationData() {
    // Perform processing based on specific requirements
}

// Implement other methods and operators as needed...
