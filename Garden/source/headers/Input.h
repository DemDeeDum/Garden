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
	string Trim(string str, char character); //убирает указанный символ с краев строки
	void SetFlags(); //устанавливаем бул переменные
public:
	//ввести строку
	void InputLine();

	//очистить
	void Clear();

	//геттеры
	int GetInputSize();
	string GetInput();
	bool OnlyDigits();
	bool OnlyLetters();
};

