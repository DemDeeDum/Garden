#pragma once
#include <string>
using namespace std;

//�������������� ��������
struct Appointment
{
	//����
	bool is_oxygen_maker;  //������ ��������� ������
	bool has_therapeutic_benefit;  //������������ � ��������
	bool has_food_value;  //���������� ��� ���
	bool has_aesthetic_value;  //����� ������������ ��������
	bool is_endangered_specie;  //���������� ���
	string additional_info;  //�������������� ����������

	//������������
	Appointment(bool is_oxygen_maker, bool has_therapeutic_benefit, bool has_food_value, bool has_aesthetic_value,
		bool is_endangered_specie, string additional_info);
	Appointment();
};

