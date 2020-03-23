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
		return "Был передан указатель растения с нулевым значением";

	try
	{												 //если вектор не содержит данное значение 
		*find(plants.begin(), plants.end(), plant);  //то при раззадрессации вылетит исключение
		return "Расстение " + plant->GetName() + " уже принадлежит к роду " + name;
	}
	catch (...)
	{
		plants.push_back(plant);
	}
	type_setter();
	return "Расстению " + plant->GetName() + " успешно присвоен род " + name + " !";
}

string Race::remove_plant(string plant_name)
{
	if (plant_name == "")
		return "Было передано пустое имя растения";

	for (auto plant : plants)
	{
		if (plant->GetName() == plant_name)
		{
			remove(plants.begin(), plants.end(), plant);
			return "Растение " + plant_name + " было успешно удалено из рода " + name;
		}
	}

	type_setter();
	return "Не удалось найти растение " + plant_name + " в роду " + name;
}


//геттеры
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

//сеттеры
void Race::SetName(string name)
{
	if (name != "")
		this->name = name;
}