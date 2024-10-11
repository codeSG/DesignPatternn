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

    DateTime addDays(int days) const; 
protected:
    
private:
    int day_, month_, year_;
};

class DateTimeAdapter {
    public:
        DateTime addDays(const DateTime& date, int days) const {
            tm time_in = { 0, 0,0, date.getDay(), date.getMonth() - 1, date.getYear() - 1900 };
            time_t time_temp = mktime(&time_in);
            const time_t ONE_DAY = 24 * 60 * 60;
            time_temp += ONE_DAY * days;
            tm const* time_out = localtime(&time_temp);

            return DateTime(time_out->tm_mday, time_out->tm_mon + 1, time_out->tm_year + 1900);
        }
    };

DateTime DateTime::addDays(int days) const
{
    //return DateTime(this->getDay()+days,this->getMonth(), this->getYear());
    std::shared_ptr<DateTimeAdapter> adapter = make_shared<DateTimeAdapter>();
    return adapter->addDays(*this, days);
}
#endif