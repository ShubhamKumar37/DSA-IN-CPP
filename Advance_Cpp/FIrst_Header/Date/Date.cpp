#include "Date.h"

Date :: Date(int date, int month, int year)
{
    this -> date = date;
    this -> month = month;
    this -> year = year;
}

void Date :: display()
{
    cout << date << "/" << month << "/" << year << endl;
}