#pragma once
#include <string>
#include <iostream>
using namespace std;
class Input
{
private:
	string input;
	bool only_digit;
	bool only_letter;
	string Trim(string str, char character); //������� ��������� ������ � ����� ������
	void SetFlags(); //������������� ��� ����������
public:
	//������ ������
	void InputLine();

	//��������
	void Clear();

	//�������
	int GetInputSize();
	string GetInput();
	bool OnlyDigits();
	bool OnlyLetters();
};

