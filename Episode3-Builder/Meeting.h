#ifndef MEETING_H
#define MEETING_H
#include<bits/stdc++.h>
#include"DateTime.h"
class Calendar;
using namespace std;

class MeetingPrototype {
public: 
    //virtual MeetingPrototype() = default;
    virtual ~MeetingPrototype() = default;
    virtual void setTitle(const std::string& title) = 0;
    virtual void setDetails(const std::string& details) = 0;
    virtual void setDate(const DateTime& start, const DateTime& end) = 0;
    //virtual void addParticipants(vector<std::shared_ptr<User>> participants) = 0;
    virtual void display() const = 0;
};

class Meeting : public MeetingPrototype{
public: 
    Meeting(int id): id_(id), title_(""), details_(""),start_(0,0,0), end_(0,0,0){}

    void setTitle(const std::string& title) override{
        this->title_ = title;
    }
    void setDetails(const std::string& details) override {
        this->details_ = details;
    }
    void setDate(const DateTime& start, const DateTime& end) override{
        this->start_ = start;
        this->end_ = end;
    }

    //void addParticipants(vector<std::shared_ptr<User>> participants){
        //for(auto participant: participants)
        //    this->participants_.push_back(std::move(participant));
    //}

    void display() const override{
       cout<< "Meeting details: " <<id_<<": "<< title_ <<endl;
       cout<<"Date: " << start_.toString() <<" - "<<end_.toString()<< std::endl;
    }
private:
    int id_;
    string title_;
    string details_;
    DateTime start_, end_;
};
#endif
