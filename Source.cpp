#include "Reservoir.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;


void ShowAllInfo(Reservoir*& reservoir, int size)
{
	if (size == 0) return;
	cout << "\n================================���������� �������� [" << size << "]=========================================\n\n";
	for (int i = 0; i < size; i++)
	{
		cout << i + 1 << ". ";
		
		reservoir[i].ShowAllParams();
		cout << endl;
	}
	cout << "\n================================================================================================\n";
}

void FindResevoir(Reservoir*& reservoir, int size, int index)
{
	if (size == 0) return;
	int count = 1;
	for (int i = 0; i < size; i++)
	{
		if (reservoir[i].GetTypeIndex() == index)
		{
			cout << count++ << ". ";
			reservoir[i].ShowAllParams();
			cout << endl;
		}
	}
}


void AddReservoir(Reservoir*& reservoir, int& size)
{
	Reservoir r;
	string name;
	int h;
	r.SetType();
	cin.clear();
	cin.ignore();

	do
	{
		cout << "\n��� �������: ";
		cin >> name;
	} while (!r.SetName(name));


	do
	{
		cout << "\n����� �������:";
		cin >> h;
		cin.clear();
		cin.ignore();

	} while (!r.SetHeight(h));

	do
	{
		cout << "\n������ �������:";
		cin >> h;
		cin.clear();
		cin.ignore();
	} while (!r.SetWidth(h));
	do
	{
		cout << "\n������� �������:";
		cin >> h;
		cin.clear();
		cin.ignore();
	} while (!r.SetMaxDepth(h));
	Reservoir* tmp = new Reservoir[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = reservoir[i];
	}
	tmp[size] = r;
	delete[] reservoir;
	size++;
	reservoir = tmp;
	system("cls");
}

void RemoveReservoir(Reservoir*& reservoir, int& size)
{
	bool check = false;
	if (size == 0 or reservoir == nullptr) return;
	string name;
	cout << "\n��� ������� ��� ��������: ";
	cin >> name;
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		if (reservoir[i].GetName() == name)
		{
			check = true;
		}
	}
	if (check)
	{
		Reservoir* tmp = new Reservoir[size - 1];
		for (int i = 0; i < size; i++)
		{
			if (reservoir[i].GetName() == name) continue;
			tmp[count++] = reservoir[i];
		}
		delete[] reservoir;
		size--;
		reservoir = tmp;
	}
	system("cls");
}



void Save(Reservoir*& reservoir, int& size)
{
	Reservoir r;
	string name = r.GetFileName();
	ofstream save(name, ios::binary);
	save.write((char*)& size, sizeof(int));
	for (int i = 0; i < size; i++)
	{
		reservoir[i].Save(save);
	}
	save.close();
}

void Load(Reservoir*& reservoir, int& size)
{
	Reservoir r;
	int a;
	string name = r.GetFileName();
	ifstream load(name, ios::binary);
	load.read((char*)& a, sizeof(int));
	if (size > 0) delete[] reservoir;
	reservoir = new Reservoir[a];
	for (int i = 0; i < a; i++)
	{
		reservoir[i].Load(load);
	}
	size = a;
	load.close();
}




void CheckTypes(const Reservoir* reservoir, const int size)
{
	if (size == 0) return;
	string name, name2;
	string tmp = "1", tmp2 = "11";
	int count = 0;
	cout << "\n������� ���1 ������� ��� �������� �� �����: ";
	cin >> name;
	cout << "\n������� ���2 ������� ��� �������� �� �����: ";
	cin >> name2;

	for (int i = 0; i < size; i++)
	{
		if (reservoir[i].GetName() == name)
		{
			tmp = reservoir[i].GetType();
		}
		if (reservoir[i].GetName() == name2)
		{
			tmp2 = reservoir[i].GetType();
		}
	}
	if (tmp == tmp2)
	{
		cout << "\n� �������� ���������� ���!\n";
	}
	else cout << "\n ������� ������ �����!";
}



int main()
{

	setlocale(LC_ALL, "");
	int size = 0;
	string n, name;
	int h;
	Reservoir* reservoir = new Reservoir[size];
	char choice;
	while (true)
	{
		do
		{

			cout << "\n1. �������� ��� �������";
			cout << "\n2. �������� ��� ������� ������ ����";
			cout << "\n3. �������� ������";
			cout << "\n4. ������� ������";
			cout << "\n5. ��������� ������������� ����� ��������";	
			cout << "\n6. ��������� � ����";
			cout << "\n7. ��������� �� �����";

			choice = _getch();

		} while (choice < 0 and choice > 7);

		switch (choice)
		{
		case '1': system("cls");  ShowAllInfo(reservoir, size); break;
		case '2': system("cls");
			do
			{
				cout << "\n1. ����� \n2. ���� \n3. ����� \n4. ����";
				choice = _getch();
			} while (choice < 0 and choice > 4);
			h = choice - 48;
			system("cls");
			FindResevoir(reservoir, size, h);
			break;
		case '3':
			system("cls");
			AddReservoir(reservoir, size);
			break;
		case '4':
			system("cls");
			RemoveReservoir(reservoir, size);
			break;
		case '5':
			system("cls");
			CheckTypes(reservoir, size);
			break;

		case '6':
			system("cls");
			Save(reservoir, size);
			break;
		case '7':
			system("cls");
			Load(reservoir, size);
			break;
		}

	}


}