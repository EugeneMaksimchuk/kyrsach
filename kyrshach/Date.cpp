#include "Date.h"

void Date::DayArrivedToHospital(int min, int max)
{
    dayarr = 1 + rand() % 31;
    montharr = 1 + rand() % 12;
    yeararr = min + (rand() % (max - min));
}

void Date::DayGoneFromHospital(int min, int max)
{
    daygone = 1 + rand() % 31;
    monthgone = 1 + rand() % 12;
    yeargone = min + (rand() % (max - min));
}

void Date::PrintDate()
{
    cout << "Day:" << day << endl;
    cout << "Month:" << month << endl;
    cout << "Year:" << year << endl;
}

void Date::FillDate(int min, int max)
{
    day = 1 + rand() % 31;
    month = 1 + rand() % 12;
    year = min + (rand() % (max - min));
}
