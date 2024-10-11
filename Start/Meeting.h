#ifndef MEETING_H
#define MEETING_H
#include<bits/stdc++.h>
#include"DateTime.h"
#include"User.h"
using namespace std;

class Meeting {
public: 
    Meeting();

    void display() const {
       cout<< "Meeting details: " <<id_<<": "<< title_ <<endl;
       cout<<"Date: " << start_.toString() <<" - "<<end_.toString()<< std::endl;
    }
private:
    int id_;
    string title_;
    string details_;
    DateTime start_, end_;
    vector<std::shared_ptr<User>> participants_;
};
#endif
