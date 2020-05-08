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
	//���������
	const string PlantRacesAddress = "data//races.txt";
	const string PlantsAddress = "data//plants.txt";

	//���� 
	Input* input; //��� ������ � ������
	string message; //��� ������ ���������

	//����� ������
	void ClearScreen(); //������� �������
	vector<string> Strtok(string input, char separator); //��� ���� ����� ������� ������ ��� ���������� �� �����
	bool ObjectExist(string name, string address); //�������� ������� ������� � ������

	//������ ����
	bool MakeChoice(int choice, int& menu_id); //��������� ������
	vector<string> GetMenu(int &menu_id); //�������� ���� �� �����

	//������ ��������
	void CreatePlant(); //������� ��������
	string CreatePlantName();
	int GivePlantFamily();
	int GivePlantSpecie();
	Race* SetPlantRace();
	Appointment CreateAppointment();
	//int SetCount();
	//vector<PlantSpecies> SetCompatibles();
	//vector<Plant> SearchPlant(string name);
	void SavePlant(Plant newPlant);

	//������ �����
	void SaveRace(Race newRace);
	void AddingPlantsToRace(Race newRace);
	void CreateRace(); //������� ���
	string CreateRaceName(); //������� ��� ����

	//��������� � ������
	vector<Plant> SearchPlants();
	Plant GetPlant(string name);
	vector<Race> SearchRaces();
	Race GetRace(string name);
	Race CreateRaceFromFile(vector<string>values);
public:
	//������������
	GardenManager(); // ����������� �� ���������( ��� ����������)

	//������ ����
	void Menu(int menu_id); //�������� ����
};

