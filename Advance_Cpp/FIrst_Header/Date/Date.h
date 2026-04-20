#pragma once
#include <iostream>

using namespace std;

class Date{
    public:
    int date, month, year;
    Date(int date = 14, int month = 2, int year = 2026);
    void display();
};