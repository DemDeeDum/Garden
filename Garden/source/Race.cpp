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


string Race::AddPlant(Plant* plant)
{

	for(auto cur : plants)
		if(cur->GetName() == plant->GetName())
			return "Расстение " + plant->GetName() + " уже принадлежит к роду " + name;


	plants.push_back(plant);
	TypeSetter();
	return "Расстению " + plant->GetName() + " успешно присвоен род " + name + " !";
}

string Race::RemovePlant(string plant_name)
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

	TypeSetter();
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