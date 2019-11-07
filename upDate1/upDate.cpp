//  upDate.cpp
//  upDate
//  Class CECS282 FALL 2019
//  Created by AIMI ROSS on 11/3/19.
//  Copyright © 2019 AIMI ROSS. All rights reserved.
//

#include "upDate.h"
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int upDate::count = 0;

// pass in the Month, Day, Year and return Julian number
int Greg2Julian(int month, int day, int year) {
    double a = (month + 9)/12;
    int intA = a;
    double b = 7*(year + intA)/4;
    int intB = b;
    double c = (275*month)/9;
    int intC = c;
    //cout << "INTEGERS!!!"<< intA << " " << intB<< " " << intC<< endl;
    
    double UT = 12/24;
    double doublesin = 0.5*sin(100*year + month-19002.5);
    double roundUT = round(UT+doublesin);
    int intUT = roundUT;
    //cout << " Sign!!!!!!" << doublesin << endl;
    
    int JD = 367*year - intB + intC + day + 1721013.5 + intUT + 0.5;
    //cout << JD << endl;
    return JD;
}

// pass in the Julian Date, and get the correct Month, Day and Year through the parameter list-pass by reference.
void Julian2Greg(int JD, int &month, int &day, int &year){
    int p,q,r,s,t,u,v;
    p = JD + 68569;
    q = 4*p/146097;
    r = p - (146097*q + 3)/4;
    s = 4000*(r+1)/1461001;
    t = r - 1461*s/4 + 31;
    u = 80*t/2447;
    v = u/11;
    
    year = 100*(q-49)+s+v;
    month = u + 2 - 12*v;
    day = t - 2447*u/80;
}

// a default constructor.
upDate::upDate(){
    count++;
    constructor();
}

// myDate constructor. set values in variables.
upDate::upDate(int M, int D, int Y){
    count++;
    if ((M >0 && M <13) && (D > 0 && D < 32)){
        dptr = new int[3];
        *(dptr+0) = M;
        *(dptr+1) = D;
        *(dptr+2) = Y;
    }
    else{
        constructor();
        //myDate();
    }
}

upDate::upDate(const upDate &D){
    count++;
    dptr = new int[3];
    dptr[0] = D.dptr[0];
    dptr[1] = D.dptr[1];
    dptr[2] = D.dptr[2];
}

void upDate:: operator=(const upDate &d){
    this->dptr[0] = d.dptr[0];
    this->dptr[1] = d.dptr[1];
    this->dptr[2] = d.dptr[2];
}

upDate::~upDate(){
    count--;
    delete []dptr;
    //cout << "Destructor is called!!!!!!" << count << " remain" << endl;
}

void upDate::constructor(){
    dptr = new int[3];
    *(dptr+0) = 5;
    *(dptr+1) = 11;
    *(dptr+2) = 1959;
}

int upDate::counter(){
    static int i = 0;  // using "static" to keep the value outside of the {}
    return i++;
}
// ************************************************* Overloading operators ***********************************************************


upDate upDate:: operator+(int i){
    upDate temp(*this);
    temp.increaseDate(i);
    return temp;
}

upDate operator+(int i, const upDate &d){
    upDate temp(d);
    temp.increaseDate(i);
    return temp;
}

upDate upDate:: operator++(int){
    upDate temp(*this);
    this->increaseDate(1);
    return temp;
}

upDate upDate:: operator++(){
    //upDate temp(*this);
    this->increaseDate(1);
    return *this;
}

upDate upDate:: operator+=(int i){
    this->increaseDate(i);
    return *this;
}


upDate upDate:: operator-(int i){
    upDate temp(*this);
    temp.decreaseDate(i);
    return temp;
}

int &upDate:: operator-(const upDate &d)const{
    int i;
    return i = - this->daysBetween(d);
}

upDate upDate:: operator--(){
    this->decreaseDate(1);
    return *this;
}

upDate upDate:: operator--(int){
    upDate temp(this->dptr[0],this->dptr[1],this->dptr[2]);
    this->decreaseDate(1);
    return temp;
}

upDate upDate:: operator-=(int i){
    this->decreaseDate(i);
    return *this;
}

bool upDate::operator==(const upDate &d) const{
    int i = this->daysBetween(d);
    if (i == 0)
        return true;
    else
        return false;
}

bool upDate::operator<(const upDate &d) const{
    int i = this->daysBetween(d);
    //cout << i << endl;
    if (i > 0)
        return false;
    else
        return true;
}

bool upDate::operator>(const upDate &d) const{
    int i = this->daysBetween(d);
    //cout << i << endl;
    if (i < 0)
        return false;
    else
        return true;
}

// ************************************************* operators ***********************************************************

//int getMonthName() const;

string upDate::getMonthName()const{
    string monthString;
    if(*(dptr+0) == 1)
        monthString = "January";
    else if(*(dptr+0) == 2)
        monthString = "Febuary";
    else if(*(dptr+0) ==3)
        monthString = "March";
    else if(*(dptr+0) == 4)
        monthString = "April";
    else if(*(dptr+0) == 5)
        monthString = "May";
    else if(*(dptr+0) == 6)
        monthString = "June";
    else if(*(dptr+0) == 7)
        monthString = "July";
    else if(*(dptr+0) == 8)
        monthString = "August";
    else if(*(dptr+0) == 9)
        monthString = "September";
    else if(*(dptr+0) == 10)
        monthString = "October";
    else if(*(dptr+0) == 11)
        monthString = "Nobember";
    else
        monthString = "December";
    return monthString;
}

// display as September 27, 2019 if 9,27,2019
void upDate::display(){
    string monthString;
    if(*(dptr+0) == 1)
        monthString = "January";
    else if(*(dptr+0) == 2)
        monthString = "Febuary";
    else if(*(dptr+0) ==3)
        monthString = "March";
    else if(*(dptr+0) == 4)
        monthString = "April";
    else if(*(dptr+0) == 5)
        monthString = "May";
    else if(*(dptr+0) == 6)
        monthString = "June";
    else if(*(dptr+0) == 7)
        monthString = "July";
    else if(*(dptr+0) == 8)
        monthString = "August";
    else if(*(dptr+0) == 9)
        monthString = "September";
    else if(*(dptr+0) == 10)
        monthString = "October";
    else if(*(dptr+0) == 11)
        monthString = "Nobember";
    else if(*(dptr+0) == 12)
        monthString = "December";
    else
        upDate();
    cout << monthString << " " << *(dptr+1) << ", " << *(dptr+2);
}

// increase date by passing value.
void upDate::increaseDate(int N){
    int JD = Greg2Julian(*(dptr+0), *(dptr+1), *(dptr+2));
    JD += N;
    Julian2Greg(JD, *(dptr+0),*(dptr+1),*(dptr+2));
}

// decrease date by pasing value
void upDate::decreaseDate(int N){
    int JD = Greg2Julian(*(dptr+0),*(dptr+1),*(dptr+2));
    JD -= N;
    Julian2Greg(JD, *(dptr+0),*(dptr+1),*(dptr+2));
}

// calculate the dates between myDate and passing Dates.
int upDate::daysBetween(const upDate &D)const{
    int thisJD = Greg2Julian(*(dptr+0),*(dptr+1),*(dptr+2));
    int otherJD = Greg2Julian(D.dptr[0], D.dptr[1], D.dptr[2]);
    
    return otherJD - thisJD;
}

// returning the Month
int upDate::getMonth()const{
    return dptr[0];
}

// returning the Day
int upDate::getDay()const{
    return dptr[1];
}

// returning the Year
int upDate::getYear()const{
    return dptr[2];
}

// returning the number of days since the current year began.
int upDate::dayOfYear(){
    int leap[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int nonLeap[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};
    int theDayOfYear = 0;
    
    //int JD = Greg2Julian(month, day, year);
    if (((*(dptr+2) % 4 == 0) && (*(dptr+2) % 100 != 0)) || (*(dptr+2) % 400 == 0))
        for (int x = 0; x < *(dptr+0); x++){
            theDayOfYear += nonLeap[x];
        }
    else
        for(int x = 0; x<*(dptr+0);x++){
            theDayOfYear += leap[x];
        }
    theDayOfYear += *(dptr+1);
    
    return theDayOfYear;
}

// returning name of the day.
string upDate::dayName(){
    int JD = Greg2Julian(*(dptr+0),*(dptr+1),*(dptr+2));
    if(JD%7==0)
        return "Monday";
    else if(JD%7==1)
        return "Tuesday";
    else if(JD%7==2)
        return "Wednesday";
    else if(JD%7==3)
        return "Thursday";
    else if(JD%7==4)
        return "Friday";
    else if(JD%7==5)
        return "Saturday";
    else
        return "Sunday";
}

int upDate::GetDateCount(){
    return count;
}

int upDate::julian(){
    return Greg2Julian(*(dptr+0),*(dptr+1),*(dptr+2));
}

ostream & operator<<(ostream&out,const upDate&d){
    //cout << "this get here?" << endl;
    out << d.getMonthName();
    out << " " << d.getDay();
    out << "," << d.getYear();
    return out;
}



