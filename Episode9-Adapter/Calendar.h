#ifndef CALENDAR_H
#define CALENDAR_H
#include<bits/stdc++.h>
#include"DateTime.h"
#include"Meeting.h"
using namespace std;
class Meeting;
class Calendar : EventNotifier{
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

    void addMeeting(int id, std::shared_ptr<Meeting> meeting){
       meetings[id] = std::move(meeting);
       //notifyObservers("Meeting creaed: ", 1, DateTime(12,1,1));
    }

    void addRecuuringMeeting(std::shared_ptr<Meeting> meeting, const DateTime& recurStartDate,
     const DateTime& recurEndDate, int recurIntervalDays) {
        DateTime nextStartDate = recurStartDate.addDays(recurIntervalDays);
        DateTime nextEndDate = recurStartDate.addDays(recurIntervalDays);

        while (nextStartDate.getYear() < recurEndDate.getYear() || 
            (nextStartDate.getYear() == recurEndDate.getYear() && nextStartDate.getMonth() < recurEndDate.getMonth()) ||
            (nextStartDate.getYear() == recurEndDate.getYear() && nextStartDate.getMonth() == recurEndDate.getMonth() && nextStartDate.getDay() <= recurEndDate.getDay())) {    
            std::shared_ptr<Meeting> next_meeting = meeting->clone();  
            next_meeting->setDate(nextStartDate, nextEndDate);
            int new_meeting_id = Calendar::getCalendar()->generateMeetingId();
            next_meeting->setId(new_meeting_id);
            next_meeting->sendMeetingInfo();
            addMeeting(new_meeting_id, next_meeting);
            nextStartDate = nextStartDate.addDays(recurIntervalDays);
            nextEndDate = nextEndDate.addDays(recurIntervalDays);
        }
     }

    void updateMeeting(const int id, std::unique_ptr<Meeting> meeting);

    void viewAllMeetings(){
        for (const auto& pair : meetings) {
            auto& meeting = pair.second;
            meeting->display();
       }
    }

    static int generateMeetingId(){
        return meeting_id_++;
    }

private:
    Calendar() = default;
    static Calendar* instance_;
    static int meeting_id_;
    map<int, std::shared_ptr<Meeting>> meetings;
};

Calendar* Calendar::instance_ = nullptr;
int Calendar::meeting_id_ = 0;
#endif