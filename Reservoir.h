#pragma once
#include <iostream>
#include <conio.h>
#include <fstream>
using namespace std;
class Reservoir
{
	string reservoir_name;
	string reservoir_type;
	float width;
	float height;
	float max_depth;
	const static string filename_for_save;
public:
	///SET GET
	bool SetName(string name);
	string GetName() const;

	bool SetType(string name);
	void SetType();
	string GetType() const;
	int GetTypeIndex() const;



	bool SetWidth(float param);
	float Width() const;

	bool SetHeight(float param);
	float Getheight() const;


	bool SetMaxDepth(float param);
	float GetMaxDepth() const;


	void ShowAllParams() const;


	static string GetFileName();
	void Save(ofstream&of);
	void Load(ifstream&load);
	//////////////////	
	float ReservoirVolume() const;
	float RevervoirSquare() const;
	bool GetType(string name) const;//сравниваю типы и возвращаю буул результат, равны или нет

	//сравниваю площадь водоемов одного типа, если равна то возврат 0, если this < возврат -1, если this >  то возврат 1
	int CheckSquareReservoirOneType(Reservoir& src) const;



	explicit Reservoir(string name = "def", string type = "Океан", float width = 1, float height = 1, float max_depth = 1);
	Reservoir(const Reservoir& src);
	Reservoir& operator =(const Reservoir& src);

};

