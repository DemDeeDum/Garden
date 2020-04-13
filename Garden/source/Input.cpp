#include "headers/Input.h"
#include <algorithm>

string Input::Trim(string str, char character)
{
    for (int i = 0; i < strlen(str.c_str()); i++)
        if (str[i] == character)
            str.erase(str.begin() + i);
        else break;

    for (int i = strlen(str.c_str()) - 1; i >= 0; i--)
        if (str[i] == character)
            str.erase(str.begin() + i);
        else break;

    return str;
}

void Input::InputLine()
{
    cin.ignore(cin.rdbuf()->in_avail()); //запретные технологии ввода строки с пробелами из потока cin
    getline(cin, input);
    
    input = Trim(input, ' ');
    SetFlags();
}

void Input::SetFlags()
{
    only_letter = all_of(input.begin(), input.end()
        , [](char x) { return (x > 64 && x < 91) || (x > 96 && x < 123) || (x > -65 && x < 0) || x == 32; }); 

    only_digit = all_of(input.begin(), input.end()
        , [](char x) { return (x > 47 && x < 58); });
}

int Input::GetInputSize()
{
    return strlen(input.c_str());
}

string Input::GetInput()
{
    return input;
}

bool Input::OnlyDigits()
{
    return only_digit;
}

bool Input::OnlyLetters()
{
    return only_letter;
}

void Input::Clear()
{
    input.clear();
}