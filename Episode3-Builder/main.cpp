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
    std::unique_ptr<User> user1 = std::make_unique<User>("Alice", "alice@gmail.com");
    user1->createMeeting("Project discussion", "Discuss on the plan", DateTime(16,7,2024), DateTime(18,7,2024));
    user1->createMeeting("Project discussion2", "Discuss on the plan", DateTime(26,7,2024), DateTime(18,7,2024));
    

    calendar1->viewAllMeetings();
    // Create Meetings

    // Update Meetings

    // View Meetings 
    return 0;
}