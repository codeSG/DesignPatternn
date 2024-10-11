#ifndef CALENDAR_VIEW_H
#define CALENDAR_VIEW_H
#include<bits/stdc++.h>
#include"DateTime.h"
#include"Meeting.h"
using namespace std;
class Meeting;

enum class ViewType{
    DAY,
    MONTH,
    ALL
};

class CalendarView {
public:
    virtual void Display(const vector<pair<int, DateTime>>& meetings, const DateTime& date) const = 0;
    virtual ~CalendarView() = default;
};

class DayView : public CalendarView {
public:
    void Display(const vector<pair<int, DateTime>>& meetings, const DateTime& date) const override {
        cout << "Meetings on " << date.toString() << ":" << endl;
        for (const auto& meeting : meetings) {
            if (DateTime::isSameDay(meeting.second, date)) {
                cout << "- " << meeting.first << " at " << meeting.second.toString() << endl;
            }
        }
    }
};

class MonthView : public CalendarView {
public:
    void Display(const vector<pair<int, DateTime>>& meetings, const DateTime& date) const override {
        cout << "Meetings in " << date.getMonth() << "/" << date.getYear() << ":" << endl;
        for (const auto& meeting : meetings) {
            if (DateTime::isSameMonth(meeting.second, date)) {
                cout << "- " << meeting.first << " on " << meeting.second.toString() << endl;
            }
        }
    }
};

class CalendarViewFactory {
    public: 
    static std::unique_ptr<CalendarView> create(ViewType viewType){
       std::unique_ptr<CalendarView> view;
        if (viewType == ViewType::DAY) {
            return std::make_unique<DayView>();
        } else if (viewType == ViewType::MONTH) {
            return std::make_unique<MonthView>();
        }
    }
};


#endif