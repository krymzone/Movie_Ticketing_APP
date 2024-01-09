#ifndef EVENTLOCATION_H
#define EVENTLOCATION_H

#include "TicketManager.h"
#include <vector>

class EventLocation : public TicketManager {
private:
    int maxSeats;
    int numRows;
    int numZones;
    std::vector<int> seatsPerRow;
    std::vector<std::vector<bool>> seatingArrangement;

public:
    EventLocation();
    EventLocation(int maxSeats, int numRows, int numZones, const std::vector<int>& seatsPerRow);

    int getMaxSeats() const;
    int getNumRows() const;
    int getNumZones() const;
    const std::vector<int>& getSeatsPerRow() const;

    void setMaxSeats(int maxSeats);
    void setNumRows(int numRows);
    void setNumZones(int numZones);
    void setSeatsPerRow(const std::vector<int>& seatsPerRow);

    void printLocationInfo() const;
    void displaySeatingArrangement() const;
    int getAvailableSeats() const;
    bool isSeatAvailable(int row, int seat) const;
    void markSeatOccupied(int row, int seat);

    void saveTickets(const std::string& filename) const override;
    void loadTickets(const std::string& filename) override;
};

#endif
