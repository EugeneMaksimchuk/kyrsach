#include "Patient.h"

void Patient::Fill()
{
    string sn[10] = { "Melnik", "Shevchenko", "Boyko", "Kovalenko", "Bondarenko", "Tkachenko", "Kovalchuk", "Kravchenko", "Oliynuk", "Shevchuk" };
    string n[10] = { "Olexiy", "Alexandr", "Maxim", "Boris", "Yriy", "Andriy", "Eugene", "Anna", "Diana", "Nastya" };
    a = rand() % 9;
    b = rand() % 9;
    c = rand() % 19;
    d = rand() % 9;
    FirstName = n[a];
    LastName = sn[b];
    date.FillDate(1960, 2004);
    date.DayArrivedToHospital(2018,2020);
    date.DayGoneFromHospital(2019,2021);
    string D[20] = { "Arythmia","Grip","Zastyda","Coronavirus","Rak","Yazva","Perelom","Nasmark","Strys mozky","Vich","Otravlennya","Serceva nedostatnist'","Avitaminoz","Bylimia","Geymorit","Diabet","Karies","Malyaria","Radikylit","Chuma" };
    Diagnose = D[c];
    PriceForHealing = 2000 + rand() % 8000;
    NumberOfInsurance = 1000 + rand() % 9000;
    if (d==1)
    {
        status = { "VIPISANO" };
    }
    else
    {
        status = {"NE VIPISANO"};
    }
}

void Patient::Print()
{
    cout << endl;
    cout << "First name\tLast name\tDay.Month.Year\t\n";
    cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
    cout << "Diagnose:"<< Diagnose << endl;
    cout << "Day when patient arrived to the hospital: " << date.dayarr<<"."<<date.montharr<<"."<<date.yeararr << endl;
    if (status == "VIPISANO")
    {
        cout << "Day when patient gone from hospital: " << date.daygone << "." << date.monthgone << "." << date.yeargone << endl;

    }
    cout << "Price for healing: "<< PriceForHealing << endl;
    cout << "Status:"<< status << endl;
    cout << "Number of insurance: " << NumberOfInsurance << endl;
}
void Patient::Zvit()
{
        cout << endl;
        cout << "First name\tLast name\tDay.Month.Year\t\n";
        cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
        cout << "Number of insurance: " << NumberOfInsurance << endl;
        cout << "Price for healing: " <<PriceForHealing << endl;
}
void Patient::PrintForDel()
{
    cout  << endl;
    cout << "First name\tLast name\tDay.Month.Year\t\n";
    cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
}
void Patient::PrintPrice()
{
    cout << endl;
    cout << "Price for healing: " << PriceForHealing << endl;
}

void Patient::PrintDovZvit()
{
    cout << endl;
    cout << "First name\tLast name\tDay.Month.Year\t\n";
    cout << FirstName << "\t\t" << LastName << "\t\t" << date.day << "." << date.month << "." << date.year << endl;
    cout << "Diagnose:" << Diagnose << endl;
    cout << "Number of insurance: " << NumberOfInsurance << endl;
    cout << "Price for healing: " << PriceForHealing << endl;
}

