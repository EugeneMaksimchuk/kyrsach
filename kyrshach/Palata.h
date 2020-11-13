#pragma once
#include <iostream>
#include <string>
#include "Patient.h"
#include "Doctor.h"
using namespace std;

struct Palata
{
	int CountOfPatients;
	Date* date;
	Palata* palats;
	Patient* patients;
	void Fill();
	int allpatients=0;
	int CountOfDeletedPatinets=0;
	Doctor doctor;
	void PrintPalata(int, int);
	void PrintZvit(int);
	void PrintForDel();
	void AddPatient();
	void DeletePatient(int del);
	void PrintPricePalata();
	void PrintDovZvit();
};
