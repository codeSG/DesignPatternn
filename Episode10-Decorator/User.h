#ifndef USER_H
#define USER_H
#include<bits/stdc++.h>
#include<memory>
#include"Calendar.h"
#include"DateTime.h"
#include"Meeting.h"
#include"EventObserver.h"
#include"CalendarView.h"
using namespace std;

class Meeting;
class Calendar;

class User : public EventObserver, public std::enable_shared_from_this<User>{
    User(const std::string& name, const std::string& email, const std::string& mobileNumber)
        : name_(name), email_(email), mobileNumber_(mobileNumber) {}

    void setupNotifications() {
        if (!email_.empty()) {
            notificationMethods_.push_back(std::make_shared<EmailNotification>(shared_from_this(), email_));
            cout<<"Email Notification Setup done for "<<name_<<endl;
        }
        if (!mobileNumber_.empty()) {
            notificationMethods_.push_back(std::make_shared<MobileNotification>(shared_from_this(), mobileNumber_));
            cout<<"Mobile Notification Setup done for "<<name_<<endl;
        }
    }
public:
    static std::shared_ptr<User> createUser(const std::string& name, const std::string& email = "", const std::string& mobileNumber = "") {
        auto user = std::shared_ptr<User>(new User(name, email, mobileNumber));
        user->setupNotifications(); // Set up notifications after construction
        return user;
    }

    std::shared_ptr<Meeting> createMeeting(const string& title, const string& details, 
        const DateTime& start, const DateTime& end, const std::vector<std::shared_ptr<User>>& participants){
        // Generate a unique ID for the meeting
        int meeting_id = Calendar::getCalendar()->generateMeetingId();
        std::shared_ptr<Meeting> meeting = std::make_shared<Meeting>(meeting_id);
        meeting->setTitle(title);
        meeting->setDetails(details);
        meeting->setDate(start, end);
        meeting->addParticipant(shared_from_this()); // Add the user as a participant
        for (const auto& participant : participants) {
            meeting->addParticipant(participant);
        }
        meeting->sendMeetingInfo();
        Calendar::getCalendar()->addMeeting(meeting_id, meeting);
        return meeting;
    }

    void createRecurringMeeting(const string& title, const string& details, 
        const DateTime& start, const DateTime& end, const std::vector<std::shared_ptr<User>>& participants,
        const DateTime& recurEndDate, int recurIntervalDays){
        // create one meeting instance as usual.
        std::shared_ptr<Meeting> meeting = createMeeting(title, details, start, end, participants);
        Calendar::getCalendar()->addRecuuringMeeting(meeting, start, recurEndDate, recurIntervalDays);
    }

    void updateMeeting();

    // user should not know which method to call, making it complete abstract
    void view(const DateTime& date, ViewType viewType){
        /*std::unique_ptr<CalendarView> view;
        if (viewType == ViewType::DAY) {
            view = std::make_unique<DayView>();
        } else if (viewType == ViewType::MONTH) {
            view = std::make_unique<MonthView>();
        }*/
        std::unique_ptr<CalendarView> view = CalendarViewFactory::create(viewType);
        view->Display(my_meetings_, date);
    }

    void update(const std::string& message, const int meeting_id, const DateTime& date) override {
        std::cout << "User " << name_ << " received notification: " << message <<meeting_id<<" - "<<date.toString()<<std::endl;
        my_meetings_.push_back({meeting_id, date});
        for (const auto& method : notificationMethods_) {
            method->update(message, meeting_id, date);
        }
    }
private:
    string name_;
    string email_;
    string mobileNumber_;
    vector<pair<int, DateTime>> my_meetings_;
    std::vector<std::shared_ptr<NotificationDecorator>> notificationMethods_;
};
#endif