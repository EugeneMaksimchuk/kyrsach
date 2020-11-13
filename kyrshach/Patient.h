#pragma once
#include <iostream>
#include <string>
#include "Date.h"

using namespace std;

struct Patient
{
    string FirstName;
    string LastName;
    Date date;
    string Diagnose;
    int PriceForHealing;
    int NumberOfInsurance;
    string status;
    int a, b, c, d;
    void Fill();
    void Print();
    void Zvit();
    void PrintForDel();
    void PrintPrice();
    void PrintDovZvit();

};