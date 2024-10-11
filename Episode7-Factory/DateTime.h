#ifndef DATETIME_H
#define DATETIME_H
#include<string>

using namespace std;
class DateTime {
public:
    DateTime(int d, int m, int y) : day_(d), month_(m), year_(y) {}

    int getDay() const { return day_; }
    int getMonth() const { return month_; }
    int getYear() const { return year_; }

    std::string toString() const {
        return std::to_string(day_)+ "/"+std::to_string(month_)+"/"+std::to_string(year_);
    }

    static bool isSameDay(const DateTime& date1, const DateTime& date2) {
        return date1.getDay() == date2.getDay() && date1.getMonth() == date2.getMonth() && date1.getYear() == date2.getYear();
    }

    static bool isSameMonth(const DateTime& date1, const DateTime& date2) {
        return date1.getMonth() == date2.getMonth() && date1.getYear() == date2.getYear();
    }
    
private:
    int day_, month_, year_;
};
#endif