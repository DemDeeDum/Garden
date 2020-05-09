#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>

//menu_id
#define MAIN 9

using namespace std;
class Input;
class Plant;
class Race;
class Appointment;
enum class PlantFamily;
enum class PlantSpecies;

class GardenManager
{
private:
	//константы
	const string PlantRacesAddress = "data//races.txt";
	const string PlantsAddress = "data//plants.txt";

	//поля 
	Input* input; //для работы с вводом
	string message; //для показа сообщений

	//общие методы
	void ClearScreen(); //очистка консоли
	vector<string> Strtok(string input, char separator); //для того чтобы парсить строку при считывании из файла
	bool ObjectExist(string name, string address); //проверка наличия объекта в файлах

	//методы меню
	vector<string> GetMenu(int menu_id); //получить меню из файла

	//методы растений
	void CreatePlant(); //создать растение
	string CreatePlantName();
	int GivePlantFamily();
	int GivePlantSpecie();
	void SetPlantRace(Plant* newPlant);
	Appointment CreateAppointment();
	int SetPlantCount();
	vector<PlantSpecies> SetCompatibles();
	void PrintPlants(vector<Plant>);


	//методы родов
	void AddingPlantsToRace(Race* newRace);
	void CreateRace(); //создать род
	string CreateRaceName(); //создать имя рода
	void PrintRaces(vector<Race>);

	//подргузка с файлов
	vector<Plant> SearchPlants();
	Plant GetPlant(string name, Race * owner);
	Plant CreatePlantFromFile(vector<string> values, Race * owner);
	void SavePlant(Plant newPlant);
	vector<Race> SearchRaces();
	Race GetRace(string name, Plant * owner);
	Race CreateRaceFromFile(vector<string>values, Plant* owner);
	void SaveRace(Race newRace);
public:
	//конструкторы
	GardenManager(); // конструктор по умолчанию( без параметров)

	//методы меню
	void Menu(); //показать меню
};

