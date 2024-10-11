#include<bits/stdc++.h>
#include"DateTime.h"
#include"Calendar.h"
#include"Meeting.h"
#include "User.h"
using namespace std;
int main(){
    // Initiate calender
    Calendar* calendar1 = Calendar::getCalendar();
    Calendar* calendar2 = Calendar::getCalendar();
    if (calendar1 == calendar2) {
        std::cout << "Both are the same instance!" << std::endl;
    }
    // Create Users
    std::shared_ptr<User> user1 = std::make_shared<User>("Alice", "alice@gmail.com");
    std::shared_ptr<User> user2 = std::make_shared<User>("Bob", "bob@gmail.com");
    std::shared_ptr<User> user3 = std::make_shared<User>("Charlie", "charlie@gmail.com");
    
    // Create Meetings
    user1->createMeeting("Project discussion", "Discuss on the plan", DateTime(16,7,2024), DateTime(18,7,2024),{user2});
    user1->createMeeting("Project discussion2", "Discuss on the plan", DateTime(26,7,2024), DateTime(18,7,2024),{user2, user3});
    calendar1->viewAllMeetings();
    // Update Meetings

    // View Meetings
    user1->viewDay(DateTime(16,7,2024)); 
    user2->viewMonth(DateTime(16,7,2024)); 
    return 0;
}