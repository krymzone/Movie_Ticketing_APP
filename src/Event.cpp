#include "Event.h"
#include <iostream>
#include <fstream>

Event::Event() : eventName("Default Event") {}

Event::Event(const std::string& eventName, const std::string& eventDate, const std::string& eventTime)
    : eventName(eventName), eventDate(eventDate), eventTime(eventTime) {}

const std::string& Event::getEventName() const { return eventName; }

const std::string& Event::getEventDate() const { return eventDate; }

const std::string& Event::getEventTime() const { return eventTime; }

bool Event::isValidDateFormat(const std::string& date) const {
    return (date.length() == 10 &&
        std::isdigit(date[0]) && std::isdigit(date[1]) &&
        std::isdigit(date[2]) && std::isdigit(date[3]) &&
        date[4] == '-' &&
        std::isdigit(date[5]) && std::isdigit(date[6]) &&
        date[7] == '-' &&
        std::isdigit(date[8]) && std::isdigit(date[9]));
}

void Event::setEventDate(const std::string& eventDate) {
    if (isValidDateFormat(eventDate)) {
        this->eventDate = eventDate;
    }
    else {
        std::cout << "Invalid date format. Please use YYYY-MM-DD." << std::endl;
    }
}

void Event::setEventTime(const std::string& eventTime) {
    if (isValidTimeFormat(eventTime)) {
        this->eventTime = eventTime;
    }
    else {
        std::cerr << "Error: Invalid event time format. Please use HH:mm format." << std::endl;
    }
}

bool Event::isValidTimeFormat(const std::string& time) const {
    return (time.size() == 5 && time[2] == ':' &&
        isdigit(time[0]) && isdigit(time[1]) && isdigit(time[3]) && isdigit(time[4]));
}

void Event::printEventInfo() const {
    std::cout << "Event Information:" << std::endl;
    std::cout << "Event Name: " << eventName << std::endl;
    std::cout << "Event Date: " << eventDate << std::endl;
    std::cout << "Event Time: " << eventTime << std::endl;
}

void Event::saveTickets(const std::string& filename) const {
    std::ofstream outFile(filename, std::ios::binary | std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error: Unable to open the file for saving tickets." << std::endl;
        return;
    }

    // Serialize and save event-specific ticket information to the file
    outFile.write(reinterpret_cast<const char*>(this), sizeof(Event));

    outFile.close();
}

void Event::loadTickets(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);

    if (!inFile.is_open()) {
        std::cerr << "Error: Unable to open the file for loading tickets." << std::endl;
        return;
    }

    std::getline(inFile, eventName);
    std::getline(inFile, eventDate);
    std::getline(inFile, eventTime);

    // Load additional event-specific ticket information if needed
    // ...

    inFile.close();
}

