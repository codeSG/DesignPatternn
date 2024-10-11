#ifndef EVENT_OBSERVER_H
#define EVENT_OBSERVER_H
#include<bits/stdc++.h>
using namespace std;
class EventObserver {
public:
    virtual void update(const std::string& message) = 0;
    virtual ~EventObserver() = default;
};

#endif