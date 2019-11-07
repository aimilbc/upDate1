//
//  upDate.h
//  upDate
//  Class CECS282 FALL 2019
//  Created by AIMI ROSS on 11/3/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#ifndef UPDATE_H
#define UPDATE_H
#include <iostream>
using namespace std;

class upDate {
    int *dptr;
    static int count;
public:
    upDate();
    upDate(int, int, int);
    upDate(const upDate &);
    void operator=(const upDate &);
    ~upDate();
    void constructor();
    void display();
    void increaseDate(int);
    void decreaseDate(int);
    int daysBetween(const upDate &)const;
    string getMonthName() const;
    int getMonth() const;
    int getDay()const;
    int getYear()const;
    int dayOfYear();
    int counter();
    static int GetDateCount();
    string dayName();
    int &operator-(const upDate &)const;
    int julian();
    
    upDate operator+(int);
    friend upDate operator+(int, const upDate &);
    upDate operator+=(int);
    upDate operator++(int); // d4 = d2++;
    upDate operator++();  // d4 = ++d2;
    upDate operator-(int);
    upDate operator-=(int);
    upDate operator--(int);
    upDate operator--();
    upDate operator=(int);
    bool operator==(const upDate &)const;
    bool operator>(const upDate &)const;
    bool operator<(const upDate &)const;
    friend ostream & operator<<(ostream &o,const upDate&c);
};

#endif /* upDate_h */

