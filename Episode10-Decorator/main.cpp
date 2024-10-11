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
    std::shared_ptr<User> user1 = User::createUser("Alice", "alice@example.com", "1234567890");
    std::shared_ptr<User> user2 = User::createUser("Bob", "bob@example.com");
    std::shared_ptr<User> user3 = User::createUser("Charlie", "charlie@example.com");
    // Create Meetings
    user1->createMeeting("Project discussion", "Discuss on the plan", DateTime(16,7,2024), DateTime(18,7,2024),{user2, user3});
    user1->createRecurringMeeting("Project discussion2", "Discuss", DateTime(26,7,2024), DateTime(28,7,2024),{user3}, DateTime(25,8,2024), 7);
    calendar1->viewAllMeetings();
    // Update Meetings

    // View Meetings
    user1->view(DateTime(16,7,2024), ViewType::DAY); 
    user1->view(DateTime(18,8,2024), ViewType::MONTH);
    return 0;
}