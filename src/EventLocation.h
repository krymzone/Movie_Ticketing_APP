#ifndef EVENTLOCATION_H
#define EVENTLOCATION_H

#include <vector>

class EventLocation {
private:
    int maxSeats;
    int numRows;
    int numZones;
    std::vector<int> seatsPerRow;

public:
    EventLocation();
    EventLocation(int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow);

    // Accessors
    int getMaxSeats() const;
    int getNumRows() const;
    int getNumZones() const;
    const std::vector<int>& getSeatsPerRow() const;

    // Validation functions
    void setMaxSeats(int maxSeats);
    void setNumRows(int numRows);
    void setNumZones(int numZones);
    void setSeatsPerRow(const std::vector<int>& seatsPerRow);

    // Other methods
    static void printLocationInfo(const EventLocation& location);
    void processLocationData();
};

#endif // EVENTLOCATION_H
