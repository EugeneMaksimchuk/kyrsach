#pragma once
#include <iostream>
#include <string>
using namespace std;

struct Date
{
    int day, dayarr, daygone;
    int month, montharr, monthgone;
    int year, yeararr, yeargone;
    void DayArrivedToHospital(int, int);
    void DayGoneFromHospital(int, int);
    void PrintDate();
    void FillDate(int min, int max);
};