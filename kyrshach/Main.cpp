#include <iostream>
#include <time.h>
#include "Palata.h"
#include <fstream>
#include <conio.h>
#include <windows.h>

using namespace std;

void SetColor(int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), col);
}

void SetPos(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Size_Console(int x, int y)
{
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD crd = { x, y };
	SMALL_RECT src = { 0, 0, crd.X , crd.Y };
	SetConsoleWindowInfo(out_handle, true, &src);
	SetConsoleScreenBufferSize(out_handle, crd);
}
int Menu(string menu_items[], int SIZE) {
	int key = 0;
	int code;
	do {
		key = (key + SIZE) % SIZE;
		for (int i = 0; i < SIZE; i++)
		{
			SetPos(20, 10 + i);
			if (key == i)
			{

				cout << " "; SetColor(6); cout << menu_items[i]; SetColor(3); cout << " " << endl; SetColor(15);
			}
			else
			{
				cout << " "; cout << menu_items[i]; cout << " " << endl;
			}

		}
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}






















void SortByDiagnose(Palata* palats, int countofpalatsf, int countofpatientsinpalate)
{
	int allpatientsf = 0;
	for (int i = 0; i < countofpalatsf; i++)
	{
		allpatientsf += palats[i].CountOfPatients;
	}
	Patient* allPatients = new Patient[allpatientsf];

	for (int i = 0, k = 0; i < countofpalatsf; i++)
	{
		for (int j = 0; j < palats[i].CountOfPatients; j++, k++)
		{
			allPatients[k] = palats[i].patients[j];
		}
	}
	
	for (int i = 0; i < allpatientsf; i++)
		for (int j = 0; j < allpatientsf-1; j++)
		{
			if (allPatients[j].Diagnose > allPatients[j + 1].Diagnose)
			{
				Patient temp = allPatients[j];
				allPatients[j] = allPatients[j + 1];
				allPatients[j + 1] = temp;
			}
		}
	for (int i = 0; i < allpatientsf; i++)
	{
		allPatients[i].Print();
	}
}

void FindCurrentPasient(Palata* palats, int countofpalatsf)
{
	int allpatientsf = 0;
	for (int i = 0; i < countofpalatsf; i++)
	{
		allpatientsf += palats[i].CountOfPatients;
	}

	cout << "Enter name of patient: " << endl;
	string findname;
	getline(cin, findname);
	cout << "Enter surname of patient: " << endl;
	string findsurname;
	getline(cin, findsurname);
	for (int i = 0; i < countofpalatsf; i++)
	{
		for (int j = 0; j < palats[i].CountOfPatients; j++)
		{
			if (palats[i].patients[j].FirstName == findname && palats[i].patients[j].LastName == findsurname)
			{
				palats[i].patients[j].Print();
			}
		}
	}
}

void Vibirka(Palata* palats, int allpatientsf, int countofpalatsf)
{
	cout << "Enter day when patient arrived to the hospital: " ;
	int Day;
	cin >> Day;
	cout << "Enter month when patient arrived to the hospital: " ;
	int Month;
	cin >> Month;
	cout << "Enter year when patient arrived to the hospital: ";
	int Year;
	cin >> Year;
	cout << "Enter diagnose of patient: " ;
	string diagn;
	cin.ignore();
	getline(cin, diagn);


	for (int i = 0; i < countofpalatsf; i++)
	{
		for (int j = 0; j < palats[i].CountOfPatients; j++)
		{
			if (palats[i].patients[j].date.dayarr == Day && palats[i].patients[j].date.montharr == Month && palats[i].patients[j].date.yeararr == Year && palats[i].patients[j].Diagnose == diagn)
			{
				palats[i].patients[j].Print();
			}
		}
	}
	
}

void Discharged(Palata* palats, int allpatientsf, int countofpalatsf)
{
	cout << "-------------Patients who was discharged: " << endl;
	for (int i = 0; i < countofpalatsf; i++)
	{
		for (int j = 0; j < palats[i].CountOfPatients; j++)
		{
			if (palats[i].patients[j].status == "VIPISANO")
			{
				palats[i].patients[j].Print();
			}
		}
	}
}

void CountAnd(Palata* palats, int countofpalatsf, int countofpatientsinpalate)
{
	int allpatientsf = 0;
	for (int i = 0; i < countofpalatsf; i++)
	{
		allpatientsf += palats[i].CountOfPatients;
	}
	for (int i = 0; i < countofpalatsf; i++)
	{
			cout << i+1 << " palata - " << palats[i].CountOfPatients << endl;
	}
}
void AndPrice(Palata* palats, int countofpalatsf, int countofpatientsinpalate)
{
	int allpatientsf = 0;
	for (int i = 0; i < countofpalatsf; i++)
	{
		allpatientsf += palats[i].CountOfPatients;
	}
	cout << "Enter name of patient: " << endl;
	string findname;
	getline(cin, findname);
	cout << "Enter surname of patient: " << endl;
	string findsurname;
	getline(cin, findsurname);
	for (int i = 0; i < countofpalatsf; i++)
	{
		for (int j = 0; j < palats[i].CountOfPatients; j++)
		{
			if (palats[i].patients[j].FirstName == findname && palats[i].patients[j].LastName == findsurname)
			{
				palats[i].patients[j].PrintPrice();
			}
		}
	}
}
void Correction(Palata* palats, int countofpalatsf, int countofpatientsinpalate)
{
	for (int i = 0; i < countofpalatsf; i++)
	{
		for (int j = 0; j < palats[i].CountOfPatients; j++)
		{
			if (palats[i].patients[j].date.yeargone<2020)
			{
				palats[i].DeletePatient(j);
			}
		}
	}
}
void PrintDovZvit(Palata* palats, int countofpalatsf)
{
	for (int i = 0; i < countofpalatsf; i++)
	{
		palats[i].PrintDovZvit();
	}
}


void Clear()
{
	system("Pause");
	system("CLS");
}


void main()
{
	srand(time(0));
	int countofpalats =1+ rand()%15;
	Palata* palats=new Palata[countofpalats];
	for (int i = 0; i != 13;)
	{
		string menu[] = { "Filling the database","View all patient data","Add patient","Delete patient", "Field ordering: diagnosis", "Search: all data about the patient", "Patients admitted on day X with a diagnosis of Y", "List of patients discharged","The number of patients in palate X", "The total cost of treatment of patient X", "Deletion of data on patients discharged last year", "List of patients grouped by palats", "Treatment bill", "Exit" };
		int m = Menu(menu, size(menu));
		Size_Console(100, 9001);
		i == m;

		if (m == 0)
		{
			for (int i = 0; i < countofpalats; i++)
			{
				palats[i].Fill();
			}
			cout << "The database was successfully filded" << endl;
			Clear();
		}
		if (m == 1)
		{
			for (int i = 0; i < countofpalats; i++)
			{
				palats[i].PrintPalata(i,i);
			}
			Clear();
		}
		if (m == 2)
		{
			palats->AddPatient();
			cout<< "Patient was succeedly added"<<endl;
			Clear();
		}
		if (m == 3)
		{
			
			for (int i = 0; i < countofpalats; i++)
			{
				cout << i + 1;
				palats[i].PrintForDel();
			}
			int del;
			cout << "Number of patient who you want to delete: ";
			cin >> del;
			palats->DeletePatient(del);
			cout << "Patient was deleted" << endl;
			Clear();
		}
		if (m == 4)
		{
			SortByDiagnose(palats, countofpalats, palats->CountOfPatients);
			Clear();
		}
		if (m == 5)
		{
			FindCurrentPasient(palats, countofpalats);
			Clear();
		}
		if (m == 6)
		{
			Vibirka(palats, palats->allpatients, countofpalats);
			Clear();
		}
		if (m == 7)
		{
			Discharged(palats, palats->allpatients, countofpalats);
			Clear();
		}
		if (m == 8)
		{
			CountAnd(palats, countofpalats, palats->CountOfPatients);
			Clear();
		}
		if (m == 9)
		{
			AndPrice(palats, countofpalats, palats->CountOfPatients);
			Clear();
		}
		if (m == 10)
		{
			Correction(palats, countofpalats, palats->CountOfPatients);
			cout << "Correction succeesful" << endl;
			Clear();
		}
		if (m == 11)
		{
			for (int i = 0; i < countofpalats; i++)
			{
				palats[i].PrintPalata(i,i);
				Clear();
			}
		}
		if (m == 12)
		{
			PrintDovZvit(palats, countofpalats);
			Clear();
		}
		if (m == 13)
			break;
	}
}