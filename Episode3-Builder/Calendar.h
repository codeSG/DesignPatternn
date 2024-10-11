#ifndef CALENDAR_H
#define CALENDAR_H
#include<bits/stdc++.h>
#include"DateTime.h"
#include"Meeting.h"
using namespace std;
class Meeting;
class Calendar {
public:
    // Static method to provide access to the single instance.
    static Calendar* getCalendar() {
        if(instance_==nullptr) {
            instance_ = new Calendar();
        }
        return instance_;
    }

    // Delete copy constructor ans assigment operator to enforce singleton property
    Calendar(const Calendar&) = delete;
    Calendar& operator=(const Calendar&) = delete;

    void addMeeting(int id, std::unique_ptr<Meeting> meeting){
       meetings[id] = std::move(meeting);
    }

    void updateMeeting(const int id, std::unique_ptr<Meeting> meeting);

    void viewAllMeetings(){
        for (const auto& pair : meetings) {
            auto& meeting = pair.second;
            meeting->display();
       }
    }

    void viewDay(const DateTime& date);

    void viewMonth(const DateTime& date);
    static int generateMeetingId(){
        return meeting_id_++;
    }

private:
    Calendar() = default;
    static Calendar* instance_;
    static int meeting_id_;
    map<int, std::unique_ptr<Meeting>> meetings;
};

Calendar* Calendar::instance_ = nullptr;
int Calendar::meeting_id_ = 0;
#endif