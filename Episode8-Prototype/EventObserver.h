#ifndef EVENT_OBSERVER_H
#define EVENT_OBSERVER_H
#include<bits/stdc++.h>
using namespace std;
class EventObserver {
public:
    virtual void update(const std::string& message,const int meeting_id, const DateTime date) = 0;
    virtual ~EventObserver() = default;
};

#endif