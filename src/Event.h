#ifndef EVENT_H
#define EVENT_H

#include <string>

class Event {
private:
    const std::string eventName;
    std::string eventDate;
    std::string eventTime;
    // Add other event-related attributes as needed

public:
    Event();
    Event(const std::string& eventName, const std::string& eventDate, const std::string& eventTime);

    // Accessors
    const std::string& getEventName() const;
    const std::string& getEventDate() const;
    const std::string& getEventTime() const;

    // Validation functions
    void setEventDate(const std::string& eventDate);
    void setEventTime(const std::string& eventTime);

    // Other methods
    static void printEventInfo(const Event& event);
    void processEventData();
};

#endif // EVENT_H
