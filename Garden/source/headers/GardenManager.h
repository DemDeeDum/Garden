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
	//���� 
	Input* input; //��� ������ � ������
	string message; //��� ������ ���������

	//����� ������
	void ClearScreen(); //������� �������
	vector<string> Strtok(string input, char separator); //��� ���� ����� ������� ������ ��� ���������� �� �����

	//������ ����
	bool MakeChoice(int choice, int& menu_id); //��������� ������
	vector<string> GetMenu(int &menu_id); //�������� ���� �� �����

	//������ ��������
	vector<Plant*> SearchPlant(string name);

	//������ �����
	void SaveRace(Race newRace);
	bool RaceExist(string name);
	void AddingPlantsToRace(Race newRace);
public:
	//������������
	GardenManager(); // ����������� �� ���������( ��� ����������)

	//������ ����
	void Menu(int menu_id); //�������� ����

	//������ ��� ��������
	void CreatePlant(); //������� ��������

	//������ ��� �����
	void CreateRace();

};

