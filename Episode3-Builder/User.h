#ifndef USER_H
#define USER_H
#include<bits/stdc++.h>
#include"Calendar.h"
#include"DateTime.h"
#include"Meeting.h"
using namespace std;

class Meeting;
class Calendar;

class User {
public:
    User(const string& name, const string&email): name_(name), email_(email){}

    void createMeeting(const string& title, const string& details, const DateTime& start, const DateTime& end){
        // Generate a unique ID for the meeting
        int meeting_id = Calendar::getCalendar()->generateMeetingId();
        std::unique_ptr<Meeting> meeting = std::make_unique<Meeting>(meeting_id);
        meeting->setTitle(title);
        meeting->setDetails(details);
        meeting->setDate(start, end);
        Calendar::getCalendar()->addMeeting(meeting_id, std::move(meeting));
    }

    void updateMeeting();

    void viewDay(const DateTime& date) const;

    void viewMonth(const DateTime& date) const;
private:
    string name_;
    string email_;
};
#endif