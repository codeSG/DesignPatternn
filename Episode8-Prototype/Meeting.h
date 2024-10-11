#ifndef MEETING_H
#define MEETING_H

#include <bits/stdc++.h>
#include "DateTime.h"
#include "EventNotifier.h"

class MeetingPrototype : public EventNotifier {
public:
    virtual ~MeetingPrototype() = default;
    virtual void setTitle(const std::string& title) = 0;
    virtual void setDetails(const std::string& details) = 0;
    virtual void setDate(const DateTime& start, const DateTime& end) = 0;
    virtual void addParticipant(std::shared_ptr<EventObserver> participant) = 0;
    virtual void sendMeetingInfo() = 0;
    virtual void display() const = 0;
    virtual void setId(int id) =0;
    //virtual std::shared_ptr<MeetingPrototype> clone() const = 0;
};

class Meeting : public MeetingPrototype {
public:
    Meeting(int id); // Constructor declaration
    void setTitle(const std::string& title) override;
    void setDetails(const std::string& details) override;
    void setDate(const DateTime& start, const DateTime& end) override;
    void addParticipant(std::shared_ptr<EventObserver> participant) override;
    void sendMeetingInfo() override;
    void display() const override;
    void setId(int id) override; 
    std::shared_ptr<Meeting> clone() const;

private:
    int id_;
    std::string title_;
    std::string details_;
    DateTime start_, end_;
    std::vector<std::shared_ptr<EventObserver>> participants_;
};


Meeting::Meeting(int id)
    : id_(id), title_(""), details_(""), start_(0, 0, 0), end_(0, 0, 0) {}

void Meeting::setTitle(const std::string& title) {
    this->title_ = title;
}

void Meeting::setDetails(const std::string& details) {
    this->details_ = details;
}

void Meeting::setDate(const DateTime& start, const DateTime& end) {
    this->start_ = start;
    this->end_ = end;
}


void Meeting::addParticipant(std::shared_ptr<EventObserver> participant) {
    this->participants_.push_back(participant);
    addObserver(participant);
}
void Meeting::sendMeetingInfo()  {
        cout<<"In Meeting Info: "<<endl;
        notifyObservers("Meeting created: ", id_, start_);
    }

void Meeting::display() const {
    std::cout << "Meeting details: " << id_ << ": " << title_ << std::endl;
    std::cout << "Date: " << start_.toString() << " - " << end_.toString() << std::endl;
}
void Meeting::setId(int id) {
    this->id_ = id;
}

std::shared_ptr<Meeting> Meeting::clone() const {
        return std::make_shared<Meeting>(*this);
    }

#endif
