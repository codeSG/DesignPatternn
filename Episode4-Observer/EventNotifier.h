#ifndef EVENT_NOTIFIER_H
#define EVENT_NOTIFIER_H
#include<bits/stdc++.h>
#include"EventObserver.h"
using namespace std;

class EventNotifier {
public:
    void addObserver(shared_ptr<EventObserver> observer) {
        observers.push_back(observer);
        //cout<<observers.size();
    }

    void notifyObservers(const std::string& message) const {
        cout<<observers.size()<<endl;
        for (const auto& observer : observers) {
            cout<<"message"<<endl;
            observer->update(message);
        }
    }

private:
    std::vector<std::shared_ptr<EventObserver>> observers;
};
#endif