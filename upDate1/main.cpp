//
//  main.cpp
//  upDate
//  Class CECS282 FALL 2019
//  Created by AIMI ROSS on 11/3/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include <iostream>
#include "upDate.h"
using namespace std;

int main(int argc, const char * argv[]) {
    upDate Bday;
    upDate duedate(11,5,2019);
    upDate today(duedate);
    
    
    cout << endl;
    cout << "Today is " << today << endl;
    cout << "This program is due on " << duedate;
    cout << endl;
    
    cout << "(3)Right now there are "<<upDate::GetDateCount() << " upDate objects\n";
    {
        upDate d1, d2, d3, d4;
        cout << "(7)Inside this block there are "<<upDate::GetDateCount() << " upDate objects\n";
    }
    cout << "(3)Outside the block there are "<<upDate::GetDateCount() << " upDate objects\n";
    
    upDate dtemp(duedate);
    dtemp++;
    cout << "If you turn this assignment in on "<<dtemp<<" then is will be late.\n";
    cout << "It is due on "<<--dtemp<<" so don't be late.\n";
    cout << "One week from due date is "<<duedate+7<<endl;
    cout << "One week from due date is "<<7+duedate<<endl;
    cout << "One week earlier from due date is "<<duedate-7<<endl;
    
    cout << "Your professor was born on "<<Bday<<" : ";
    cout << "Master Gold is "<< duedate - Bday << " days old today\n";
    
    cout << "Today is Julian date "<<duedate.julian()<<endl;;
    cout << "Tomorrrow is Julian date "<<(++duedate).julian()<<endl;;
    
    cout << "The very first Julian date was " << upDate(11,1,2018)-upDate(11,1,2018).julian()<<endl;
    
    cout << "The very first Julian date was " << today - today.julian()<<endl;
    
    
    upDate yesterday, tomorrow;
    yesterday = today-1;
    tomorrow = today+1;
    
    cout << "Yesterday was "<<yesterday << endl;
    cout << "Today is "<<today<<endl;
    cout << "Tomorrow is "<<tomorrow<<endl;
    
    cout << "Today is ";
    cout << ((today>tomorrow)?"greater than":"not greater than");
    cout << " than tomorrow\n";
    
    cout << "Today is ";
    cout << ((today<tomorrow)?"less than":"not less than");
    cout << " than tomorrow\n";
    
    cout << "Today is ";
    cout << ((today==tomorrow)?"equal to":"not equal to");
    cout << " tomorrow\n";
    
    getchar();
    
    
    
    //    upDate Bday;
    //    upDate duedate(11,5,1970);
    //    upDate check = duedate;
    //    Bday.display();
    //    cout << endl;
    //    duedate.display();
    //    cout << endl;
    //    check.display();
    //    cout << endl;
    //    cout << "checking cout operation: " << endl;
    //    cout << Bday << endl;
    //    cout << "checking get operation: " << endl;
    //    cout << Bday.getYear() << endl;
    //    cout << "\nchecking Bday++ operation: " << endl;
    //    duedate = Bday++;
    //    cout << "Bday is " << Bday << " and duedate is " << duedate << endl;
    //    cout << "checking ++Bday operation: " << endl;
    //    duedate = ++Bday;
    //    cout << "Bday is " << Bday << " and duedate is " << duedate << endl;
    //    cout << "\nchecking Bday-- operation: " << endl;
    //    duedate = Bday--;
    //    cout << "Bday is " << Bday << " and duedate is " << duedate << endl;
    //    cout << "checking --Bday operation: " << endl;
    //    duedate = --Bday;
    //    cout << "Bday is " << Bday << " and duedate is " << duedate << endl;
    //    cout << "checking += operation: " << endl;
    //    Bday+=3;
    //    cout << Bday<<endl;
    //    cout << "checking -= operation: " << endl;
    //    Bday-=3;
    //    cout << Bday << endl;
    //    cout << "checking = operation: " << endl;
    //    check = Bday;
    //    cout << check << endl;
    //    cout << "checking + operation: " << endl;
    //    check = Bday + 3;
    //    cout << check << endl;
    //    cout << "checking - operation: " << endl;
    //    check = Bday - 3;
    //    cout << "checking check = 5 + Bday operation: " << endl;
    //    cout << "Before: " << check << endl;
    //    check = 5 + Bday;
    //    cout << "After: " << check << endl;
    //    cout << upDate::getDateCount() << endl;
    //    cout << duedate.julian() << endl;
    //    cout << "checking check < Bday " << endl;
    //    if(check < Bday)
    //        cout << "check is smaller number" << endl;
    //    else
    //        cout << "check is bigger number" << endl;
    //
    //    if(check > Bday)
    //        cout << "check is bigger number" << endl;
    //    else
    //        cout << "check is smaller number" << endl;
    //
    //    cout << "Before int days = check - Bday, check is " << check << " Bday is " << Bday<< endl;
    //    int days = check - Bday;
    //    cout << "After int days = check - Bday: " << days << endl;
    //    Bday += 5;
    //    cout << "Bday is now " << Bday << endl;
    //
    //    if(Bday == check)
    //        cout << "same!" << endl;
    
    return 0;
}

