#pragma once
#include <iostream>
#include <string>
#include "Date.h"
using namespace std;


struct Doctor
{

    string FirstName;
    string LastName;
    Date date;


    void FillDoctor()
    {
        string sn[5] = { "Ivanchuk", "Melnychuk", "Tkach", "Zelenskiy", "Stolyar" };
        string n[5] = { "Dmitro", "Vadim", "Maxim", "Nazar", "Stanislav" };
        int a, b;
        a = rand() % 4;
        b = rand() % 4;
        FirstName = n[a];
        LastName = sn[b];
        date.FillDate(1965, 1990);
    }
    void PrintDoctor()
    {
        cout << "First name\tLast name\tDay.Month.Year\t\n";
        cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
        date.PrintDate();
    }

};