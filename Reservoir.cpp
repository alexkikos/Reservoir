#include "Reservoir.h"


const string Reservoir::filename_for_save = "Revervoir.bin";


Reservoir::Reservoir(string name, string type, float width, float height, float max_depth)
{
	 reservoir_name=name;
	 reservoir_type=type;
	 this->width = width;
	 this->height = height;
	 this->max_depth = max_depth;
}

bool Reservoir::SetName(string name)
{
	if (name.size() > 0)
	{
		reservoir_name = name;
		return true;
	}
	else
		cout << "\n Check this param";

	return false;
}

string Reservoir::GetName() const
{
	return reservoir_name;
}

bool Reservoir::SetType(string name)
{
	if (name.size() > 0 and (name == "Океан" or name == "Море" or name == "Озеро" or name == "Пруд"))
	{
		reservoir_type = name;
		return true;
	}
	else
		cout << "\n Check this param";

	return false;
}

void Reservoir::SetType()
{
	int choice;
	do
	{
		cout << "\n1. Океан \n2. Море \n3. Озеро \n4. Пруд";
		cin >> choice;
		cin.clear();
		cin.ignore();
	} while (choice < 0 and choice > 4);
	int a =choice;//конвертирую в инт
	if (a == 1)
	{
		reservoir_type = "Океан";
	}
	else
		if (a == 2)
		{
			reservoir_type = "Море";
		}
		else
			if (a == 3)
			{
				reservoir_type = "Озеро";
			}
			else
				if (a == 4)
				{
					reservoir_type = "Пруд";
				}
}
bool Reservoir::GetType(string name) const
{
	if (this->reservoir_type == name) return true;
	else return false;
}

int Reservoir::CheckSquareReservoirOneType(Reservoir& src) const
{
	if (reservoir_type == src.reservoir_type)
	{
		auto a = RevervoirSquare();
		auto a1 = src.RevervoirSquare();
		if (a == a1) return 0;
		else if (a < a1) return -1;
		else if (a > a1) return 1;
	}
}

string Reservoir::GetType() const
{
	return reservoir_type;
}

int Reservoir::GetTypeIndex() const
{
	if (reservoir_type == "Океан")
	{
		return 1;
	}
	else
		if (reservoir_type == "Море")
		{
			return 2;
		}
		else
			if (reservoir_type == "Озеро")
			{
				return 3;
			}
			else
				if (reservoir_type == "Пруд")
				{
					return 4;
				}
}

bool Reservoir::SetWidth(float param)
{
	if (param > 0)
	{
		width = param;
		return true;
	}
	else
		cout << "\n Check this param";

	return false;
}

float Reservoir::Width() const
{
	return width;
}

bool Reservoir::SetHeight(float param)
{
	if (param > 0)
	{
		max_depth = height;
		return true;
	}
	else
		cout << "\n Check this param";


	return false;
}

float Reservoir::Getheight() const
{
	return 0.0f;
}

bool Reservoir::SetMaxDepth(float param)
{
	if (param > 0)
	{
		max_depth = param;
		return true;
	}
	else
		cout << "\n Check this param";

	return false;
}

float Reservoir::GetMaxDepth() const
{
	return max_depth;
}

void Reservoir::ShowAllParams() const
{
	cout << "Название водоема: [" << reservoir_name << "] Тип [" << reservoir_type << "] Ширина: [" << width << "] Длина: [" << height << "] Глубина: [" << max_depth << "] Площадь водоема: [" << RevervoirSquare() << "] Обьем: [" << ReservoirVolume() << "]";

}



string Reservoir::GetFileName()
{
	return filename_for_save;
}

void Reservoir::Save(ofstream& of)
{

		int sname = reservoir_name.length() + 1;
		of.write((char*)& sname, sizeof(int));
		of.write(reservoir_name.c_str(), sname);

		sname = reservoir_type.length() + 1;
		of.write((char*)& sname, sizeof(int));
		of.write(reservoir_type.c_str(), sname);

		of.write((char*) &width, sizeof(float));
		of.write((char*)& height, sizeof(float));
		of.write((char*)& max_depth, sizeof(float));


}

void Reservoir::Load(ifstream& load)
{
	
		int sname;
		load.read((char*)& sname, sizeof(int));
		char* buff = new char[sname];
		load.read((char*)buff, sname);
		reservoir_name = buff;

		load.read((char*)& sname, sizeof(int));
		char* buff2 = new char[sname];
		load.read((char*)buff2, sname);
		reservoir_type = buff2;


		float names;
		load.read((char*)& names, sizeof(float));
		width = names;
		load.read((char*)& names, sizeof(float));
		height = names;
		load.read((char*)& names, sizeof(float));
		max_depth = names;


}

float Reservoir::ReservoirVolume() const
{
	return 	 (width* height*max_depth);

}

float Reservoir::RevervoirSquare() const
{
	return (width * height);
}

Reservoir::Reservoir(const Reservoir& src)
{
	this->reservoir_name = src.reservoir_name;
	this->reservoir_type = src.reservoir_type;
	this->width = src.width;
	this->height = src.height;
}

Reservoir& Reservoir::operator=(const Reservoir& src)
{
	this->reservoir_name = src.reservoir_name;
	this->reservoir_type = src.reservoir_type;
	this->width = src.width;
	this->height = src.height;
	this->max_depth = src.max_depth;
	return *this;
}
