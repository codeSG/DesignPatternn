#ifndef USER_H
#define USER_H
#include<bits/stdc++.h>
#include"DateTime.h"
#include"Meeting.h"
using namespace std;

class User {
public:
    User(const string& name): name_(name){}

    void createMeeting();

    void updateMeeting();

    void viewDay(const DateTime& date) const;

    void viewMonth(const DateTime& date) const;
private:
    string name_;
    string email_;
};
#endif