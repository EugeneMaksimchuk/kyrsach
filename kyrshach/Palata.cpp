#include "Palata.h"

void Palata::Fill()
{
	CountOfPatients = 2 + rand() % 8;
	patients = new Patient[CountOfPatients];
	for (int i = 0; i < CountOfPatients; i++)
	{
		patients[i].Fill();
	}
	doctor.FillDoctor();   
}

void Palata::PrintPalata(int Number, int nomer)
{
    Number += 1;
    cout << "---------------" << Number << "---------------";
    cout << "----------------------------------------------" << endl;
    cout << "Doctor:" << endl;

    doctor.PrintDoctor();

    for (int i = 0; i < CountOfPatients; i++)
    {
        cout << "------------------------------------" << endl;
        cout << "Patient: " << endl;
        patients[i].Print();
    }
}
void Palata::PrintZvit(int nomer)
{
    
    for (int i = 0; i < CountOfPatients; i++)
    {
        cout << "------------------------------------" << endl;
        cout << "Patient:" << endl;
        patients[i].Zvit();
    }
}
void Palata::PrintForDel()
{
    for (int i = 0; i < CountOfPatients; i++)
    {
        patients[i].PrintForDel();
    }
   
}

void Palata::PrintDovZvit()
{
    for (int i = 0; i < CountOfPatients; i++)
    {
        cout << endl;
        patients[i].PrintDovZvit();
    }
}
void Palata::AddPatient()
{
    Patient* patients1 = new Patient[CountOfPatients+1];
    for (int i = 0; i < CountOfPatients; i++)
    {
        patients1[i] = patients[i];
    }
    patients1[CountOfPatients].Fill();
    delete[] patients;
    CountOfPatients++;
    patients = patients1;
}

void Palata::DeletePatient(int del)
{
    Patient* patients1 = new Patient[CountOfPatients - 1];
    CountOfPatients--;
  
    for (int i = 0; i < CountOfPatients; i++)
    {
        if (i<del)
        {
            patients1[i] = patients[i];
        }
        else if (i >= del)
        {
            patients1[i] = patients[i + 1];
            CountOfDeletedPatinets++;
        }
    }
    delete[] patients;
    patients = patients1;
}
void Palata::PrintPricePalata()
{
    for (int i = 0; i < CountOfPatients; i++)
    {
        patients[i].PrintPrice();
    }
}

