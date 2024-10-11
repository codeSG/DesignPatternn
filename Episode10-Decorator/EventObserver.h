#ifndef EVENT_OBSERVER_H
#define EVENT_OBSERVER_H
#include<bits/stdc++.h>
using namespace std;
class EventObserver {
public:
    virtual void update(const std::string& message,const int meeting_id, const DateTime& date) = 0;
    virtual ~EventObserver() = default;
};

class NotificationDecorator : public EventObserver {
protected:
    std::shared_ptr<EventObserver> wrapped;

public:
    NotificationDecorator(std::shared_ptr<EventObserver> observer) : wrapped(observer) {}
    virtual void update(const std::string& message,const int meeting_id, const DateTime& date) = 0;
};

class EmailNotification : public NotificationDecorator {
private:
    std::string email;

public:
    EmailNotification(std::shared_ptr<EventObserver> observer, const std::string& email)
        : NotificationDecorator(observer), email(email) {}

    void update(const std::string& message,const int meeting_id, const DateTime& date) override {
        std::cout << "Notifying via Email (" << email << "): " << message << " on " << date.toString()
                  << " with id: " << meeting_id << std::endl;
        //NotificationDecorator::update(message, meeting_id, date);
    }
};

class MobileNotification : public NotificationDecorator {
private:
    std::string mobileNumber;

public:
    MobileNotification(std::shared_ptr<EventObserver> observer, const std::string& mobileNumber)
        : NotificationDecorator(observer), mobileNumber(mobileNumber) {}

    void update(const std::string& message,const int meeting_id, const DateTime& date) override {
        std::cout << "Notifying via Mobile (" << mobileNumber << "): " << message << " on " << date.toString()
                  << " with id: " << meeting_id << std::endl;
         //NotificationDecorator::update(message, meeting_id, date);
    }
};


#endif