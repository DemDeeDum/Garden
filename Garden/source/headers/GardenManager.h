#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
#include <fstream>

//menu_id
#define MAIN 9
#define PLANTS 1
#define SALES 2
#define RACES 3

using namespace std;
class Input;
class Plant;
class Race;
class Appointment;

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
	bool MakeChoice(int choice, int& menu_id); //обработка выбора
	vector<string> GetMenu(int &menu_id); //получить меню из файла

	//методы растений
	void CreatePlant(); //создать растение
	string CreatePlantName();
	int GivePlantFamily();
	int GivePlantSpecie();
	Race* SetPlantRace();
	Appointment CreateAppointment();
	//int SetCount();
	//vector<PlantSpecies> SetCompatibles();
	//vector<Plant> SearchPlant(string name);
	void SavePlant(Plant newPlant);

	//методы родов
	void SaveRace(Race newRace);
	void AddingPlantsToRace(Race newRace);
	void CreateRace(); //создать род
	string CreateRaceName(); //создать имя рода

	//подргузка с файлов
	vector<Plant> SearchPlants();
	Plant GetPlant(string name);
	vector<Race> SearchRaces();
	Race GetRace(string name);
	Race CreateRaceFromFile(vector<string>values);
public:
	//конструкторы
	GardenManager(); // конструктор по умолчанию( без параметров)

	//методы меню
	void Menu(int menu_id); //показать меню
};

