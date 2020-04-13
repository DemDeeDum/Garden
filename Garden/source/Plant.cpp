#include "headers/Plant.h"
#include "headers/Race.h"

//инициализация статического поля
int Plant::count = 0;

//статик методы
void Plant::SetCount(int new_count)
{
	if (new_count > 0)
		count = new_count;
}

int Plant::GetCount()
{
	return count;
}

void Plant::IncCount()
{
	count++;
}

void Plant::DecCount()
{
	if (count > 0)
		count--;
}

//конструкторы
Plant::Plant(PlantFamily _family, PlantSpecies _specie, string _name, Appointment _appointment, Race _race
	, vector<PlantSpecies> _compatible)
	: 
	family(_family),
	specie(_specie),
	name(_name),
	appointment(_appointment),
	compatible_species(vector<PlantSpecies>(_compatible)),
	race(_race)
{}

//сеттеры
void Plant::SetRace(Race _race)
{
	race = _race;
}

void Plant::SetAppointment(Appointment _appointment)
{
	appointment = _appointment;
}

void Plant::SetFamily(PlantFamily _family)
{
	family = _family;
}

void Plant::SetSpecie(PlantSpecies _specie)
{
	specie = _specie;
}

void Plant::SetName(string _name)
{
	if (_name != "")
		name = _name;
}

//геттеры
Race Plant::GetRace()
{
	return Race(race);
}

Appointment Plant::GetAppointment()
{
	return appointment;
}

PlantFamily Plant::GetFamily()
{
	return family;
}

PlantSpecies Plant::GetSpecie()
{
	return specie;
}

string Plant::GetName()
{
	return name;
}

vector<PlantSpecies>& Plant::GetCompatible()
{
	return compatible_species;
}