#ifndef EVENT_H
#define EVENT_H

#include "TicketManager.h"
#include <string>

class Event : public TicketManager {
private:
    std::string eventName;
    std::string eventDate;
    std::string eventTime;

public:
    Event();
    Event(const std::string& eventName, const std::string& eventDate, const std::string& eventTime);

    const std::string& getEventName() const;
    const std::string& getEventDate() const;
    const std::string& getEventTime() const;

    void setEventDate(const std::string& eventDate);
    void setEventTime(const std::string& eventTime);

    void printEventInfo() const;

    // Implement pure virtual methods from TicketManager
    void saveTickets(const std::string& filename) const override;
    void loadTickets(const std::string& filename) override;

private:
    bool isValidDateFormat(const std::string& date) const;
    bool isValidTimeFormat(const std::string& time) const;
};

#endif
