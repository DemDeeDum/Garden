#include "headers/Race.h"
#include "headers/Plant.h"
#include <algorithm>

Race::Race	(string name)
	:
	name(name)
{
	type_setter();
}

Race::Race()
	:
	name("unnammed")
{
	type_setter();
}

void Race::type_setter()
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

string Race::add_plant(Plant* plant)
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
	type_setter();
	return "��������� " + plant->GetName() + " ������� �������� ��� " + name + " !";
}

string Race::remove_plant(string plant_name)
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

	type_setter();
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