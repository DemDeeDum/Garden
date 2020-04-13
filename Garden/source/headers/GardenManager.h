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
	//поля 
	Input* input; //для работы с вводом
	string message; //для показа сообщений

	//общие методы
	void ClearScreen(); //очистка консоли
	vector<string> Strtok(string input, char separator); //для того чтобы парсить строку при считывании из файла

	//методы меню
	bool MakeChoice(int choice, int& menu_id); //обработка выбора
	vector<string> GetMenu(int &menu_id); //получить меню из файла

	//методы растений
	vector<Plant*> SearchPlant(string name);

	//методы родов
	void SaveRace(Race newRace);
	bool RaceExist(string name);
	void AddingPlantsToRace(Race newRace);
public:
	//конструкторы
	GardenManager(); // конструктор по умолчанию( без параметров)

	//методы меню
	void Menu(int menu_id); //показать меню

	//методы для растений
	void CreatePlant(); //создать растение

	//методы для родов
	void CreateRace();

};

