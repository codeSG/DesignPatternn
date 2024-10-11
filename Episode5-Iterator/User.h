#ifndef USER_H
#define USER_H
#include<bits/stdc++.h>
#include<memory>
#include"Calendar.h"
#include"DateTime.h"
#include"Meeting.h"
#include"EventObserver.h"
using namespace std;

class Meeting;
class Calendar;

class User : public EventObserver, public std::enable_shared_from_this<User>{
public:
    User(const string& name, const string&email): name_(name), email_(email){}

    void createMeeting(const string& title, const string& details, const DateTime& start, const DateTime& end, const std::vector<std::shared_ptr<User>>& participants){
        // Generate a unique ID for the meeting
        int meeting_id = Calendar::getCalendar()->generateMeetingId();
        std::unique_ptr<Meeting> meeting = std::make_unique<Meeting>(meeting_id);
        meeting->setTitle(title);
        meeting->setDetails(details);
        meeting->setDate(start, end);
        meeting->addParticipant(shared_from_this()); // Add the user as a participant
        for (const auto& participant : participants) {
            meeting->addParticipant(participant);
        }
        meeting->sendMeetingInfo();
        Calendar::getCalendar()->addMeeting(meeting_id, std::move(meeting));

    }

    void updateMeeting();

    void viewDay(const DateTime& date) const {
        for(auto iter = my_meetings_.begin();iter!=my_meetings_.end();iter++)
        {
            if(DateTime::isSameDay(date, iter->first))
                cout<<iter->second<<endl;
        }
    }

    void viewMonth(const DateTime& date) const{
        for(auto iter = my_meetings_.begin();iter!=my_meetings_.end();iter++)
        {
            if(DateTime::isSameMonth(date,iter->first))
                cout<<iter->second<<endl;
        }
    }

    void update(const std::string& message, const int meeting_id, const DateTime date) override {
        std::cout << "User " << name_ << " received notification: " << message <<meeting_id<<" - "<<date.toString()<<std::endl;
        my_meetings_.push_back({date,meeting_id});
    }
private:
    string name_;
    string email_;
    vector<pair<DateTime, int>> my_meetings_;
};
#endif