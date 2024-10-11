#ifndef CALENDAR_H
#define CALENDAR_H
#include<bits/stdc++.h>
#include"DateTime.h"
#include"Meeting.h"
using namespace std;

class Calendar {
public:
    Calendar(){}
    
    void addMeeting(const int id, std::unique_ptr<Meeting> meeting);

    void updateMeeting(const int id, std::unique_ptr<Meeting> meeting);

    void viewDay(const DateTime& date);

    void viewMonth(const DateTime& date);

private:
    int meeting_id;
    map<int, std::unique_ptr<Meeting>> meetings;
};
#endif