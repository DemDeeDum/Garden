#include "headers/Race.h"
#include "headers/Plant.h"
#include <algorithm>

Race::Race	(string name)
	:
	name(name)
{
	TypeSetter();
}

Race::Race()
	:
	name("unnammed")
{
	TypeSetter();
}

void Race::TypeSetter()
{
	if (plants.size() == 0)
		type = RaceType::EMPTY;
	else if (plants.size() == 1)
		type = RaceType::MONOTYPIC;
	else if (plants.size() < 5)
		type = RaceType::OLIGOTYPIC;
	else
		type = RaceType::POLYTYPE;
}

string Race::AddPlants(vector<Plant*> plants)
{
	string res = "";
	for (auto plant : plants)
		res += AddPlant(plant);
	return res;
}

string Race::AddPlant(Plant* plant)
{
	if (plant == nullptr)
		return "��� ������� ��������� �������� � ������� ���������";

	try
	{												 //���� ������ �� �������� ������ �������� 
		*find(plants.begin(), plants.end(), plant);  //�� ��� �������������� ������� ����������
		return "��������� " + plant->GetName() + " ��� ����������� � ���� " + name;
	}
	catch (...)
	{
		plants.push_back(plant);
	}
	TypeSetter();
	return "��������� " + plant->GetName() + " ������� �������� ��� " + name + " !";
}

string Race::RemovePlant(string plant_name)
{
	if (plant_name == "")
		return "���� �������� ������ ��� ��������";

	for (auto plant : plants)
	{
		if (plant->GetName() == plant_name)
		{
			remove(plants.begin(), plants.end(), plant);
			return "�������� " + plant_name + " ���� ������� ������� �� ���� " + name;
		}
	}

	TypeSetter();
	return "�� ������� ����� �������� " + plant_name + " � ���� " + name;
}


//�������
string Race::GetName()
{
	return name;
}

RaceType Race::GetType()
{
	return type;
}

vector<Plant*> Race::GetPlants()
{
	return plants;
}

//�������
void Race::SetName(string name)
{
	if (name != "")
		this->name = name;
}