#ifndef CALENDAR_H
#define CALENDAR_H
#include<bits/stdc++.h>
#include"DateTime.h"
#include"Meeting.h"
using namespace std;

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

    void addMeeting(const int id, std::unique_ptr<Meeting> meeting);

    void updateMeeting(const int id, std::unique_ptr<Meeting> meeting);

    void viewDay(const DateTime& date);

    void viewMonth(const DateTime& date);

private:
    Calendar() = default;
    static Calendar* instance_;
    int meeting_id;
    map<int, std::unique_ptr<Meeting>> meetings;
};

Calendar* Calendar::instance_ = nullptr;
#endif