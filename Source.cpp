#include "Reservoir.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;


void ShowAllInfo(Reservoir*& reservoir, int size)
{
	if (size == 0) return;
	cout << "\n================================КОЛИЧЕСТВО ВОДОЕМОВ [" << size << "]=========================================\n\n";
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
		cout << "\nИмя водоема: ";
		cin >> name;
	} while (!r.SetName(name));


	do
	{
		cout << "\nДлину водоема:";
		cin >> h;
		cin.clear();
		cin.ignore();

	} while (!r.SetHeight(h));

	do
	{
		cout << "\nШирину водоема:";
		cin >> h;
		cin.clear();
		cin.ignore();
	} while (!r.SetWidth(h));
	do
	{
		cout << "\nГлубину водоема:";
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
	cout << "\nИмя водоема для удаления: ";
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
	cout << "\nВведите имя1 водоема для проверки их типов: ";
	cin >> name;
	cout << "\nВведите имя2 водоема для проверки их типов: ";
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
		cout << "\nУ водоемов одинаковый тип!\n";
	}
	else cout << "\n Водоемы разных типов!";
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

			cout << "\n1. Показать все водоемы";
			cout << "\n2. Показать все водоемы одного типа";
			cout << "\n3. Добавить водоем";
			cout << "\n4. Удалить водоем";
			cout << "\n5. Проверить совместимость типов водоемов";	
			cout << "\n6. Сохранить в файл";
			cout << "\n7. Загрузить из файла";

			choice = _getch();

		} while (choice < 0 and choice > 7);

		switch (choice)
		{
		case '1': system("cls");  ShowAllInfo(reservoir, size); break;
		case '2': system("cls");
			do
			{
				cout << "\n1. Океан \n2. Море \n3. Озеро \n4. Пруд";
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