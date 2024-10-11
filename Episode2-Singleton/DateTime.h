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

private:
    int day_, month_, year_;
};
#endif