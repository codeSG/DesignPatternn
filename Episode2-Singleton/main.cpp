#include<bits/stdc++.h>
#include"Calendar.h"
#include"DateTime.h"
#include"Meeting.h"
#include"User.h"
using namespace std;
int main(){
    // Initiate calender
    Calendar* calendar1 = Calendar::getCalendar();
    Calendar* calendar2 = Calendar::getCalendar();
    if (calendar1 == calendar2) {
        std::cout << "Both are the same instance!" << std::endl;
    }
    // Create Users

    // Create Meetings

    // Update Meetings

    // View Meetings 
    return 0;
}