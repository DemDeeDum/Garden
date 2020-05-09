#include "headers/GardenManager.h"
#include "headers/Input.h"
#include "headers/Race.h"
#include "headers/Plant.h"

#define BACK 9

//������ ���� 
#define ADD_PLANT 1
#define ADD_RACE 2




//�����������
GardenManager::GardenManager()
    :
    input(new Input())
{}


//������ � ����
vector<string> GardenManager::GetMenu(int menu_id)
{
    string address;
    vector<string> menu_items;
    switch (menu_id)
    {
    case MAIN:
        address = "menus//main_menu.txt";
        break;
    }

    fstream file(address);

    if (file.is_open())
    {
        string buf;
        while (!file.eof())
        {
            getline(file, buf);
            menu_items.push_back(buf);
        }
    }
    else
        return vector<string>({ "�� ������ ���� ����" });
    return menu_items;
}

void GardenManager::Menu()
{
    auto menu = GetMenu(MAIN);
	while (true)
	{
        input->Clear();
        ClearScreen();
		cout << "\"������������ ���\"" << endl;
        for (auto item : menu)
            cout << item << endl;
        cout << (message.empty() ? "" : message + "\n");
        input->InputLine();
        if (!input->OnlyDigits() || input->GetInputSize() > 1)
        {
            message = "������������ ����!!";
            continue;
        }
        message.clear();
        switch (atoi(input->GetInput().c_str()))
        {
        case ADD_PLANT:
            CreatePlant();
            break;
        case ADD_RACE:
            CreateRace();
            break;
        case BACK:
            return;
        default:
            message = "������������ ����!!";
            continue;
        }
	}
}



//���� ���������� ����������
void GardenManager::CreatePlant()
{
    Plant newPlant;
    try
    {
        newPlant.SetName(CreatePlantName());
        newPlant.SetFamily(PlantFamily(GivePlantFamily()));
        newPlant.SetSpecie(PlantSpecies(GivePlantSpecie()));
        SetPlantRace(&newPlant);
        newPlant.SetAppointment(CreateAppointment());
        newPlant.SetCount(SetPlantCount());
        newPlant.SetCompatible(SetCompatibles());
    }
    catch (...)
    {
        return;
    }

    SavePlant(newPlant);
}

string GardenManager::CreatePlantName()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "������� �������� ��������: " << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw "Back";

        if (input->GetInputSize() < 2)
        {
            message = "�������� ������ �������� ��� ������� �� ���� ����!";
            continue;
        }


        if (ObjectExist(input->GetInput(), this->PlantsAddress))
        {
            message = "�������� � ����� ������ ��� �������";
            continue;
        }

        return (input->GetInput());
    }
}

int GardenManager::GivePlantFamily()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ��������� ��������: " << endl;

        for (int i = 0; i <= (int)PlantFamily::BLUEGRASS; i++)
            cout << i + 1 << ") " << Plant::GetFamilyStringValue(PlantFamily(i)) << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        try 
        {
            return (int)Plant::GetFamilyEnumValue(atoi(input->GetInput().c_str()));
        }
        catch (...)
        {
            message = "������� �������� �������� ���!";
        }
    }
}

int GardenManager::GivePlantSpecie()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ��� ��������: " << endl;

        for (int i = 0; i <= (int)PlantSpecies::FLOWERY; i++)
            cout << i + 1 << ") " << Plant::GetSpecieStringValue(PlantSpecies(i)) << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        try
        {
            return (int)Plant::GetSpecieEnumValue(atoi(input->GetInput().c_str()));
        }
        catch (...)
        {
            message = "������� �������� �������� ���!";
        }
    }
}

void GardenManager::SetPlantRace(Plant* newPlant)
{
    if (SearchRaces().size() < 1)
        return;

    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ��� ��������?\n�� - 1\n��� - 2 " << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        int val = atoi(input->GetInput().c_str());
        if(val == 1)
            break;
        else if (val == 2)
        {
            newPlant->SetRace(nullptr);
            return;
        }
        else
        {
            message = "������������ �������� �����";
            continue;
        }
    }

    while (true)
    {
        auto races = SearchRaces();
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "������� �������������� ����\n�������� ���� �� ���" << endl;

        for (int i = 0; i < races.size(); i++)
            cout << i + 1 << ") " << races[i].GetName() << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }


        if (atoi(input->GetInput().c_str()) <= races.size())
        {
            auto race = new Race(races[atoi(input->GetInput().c_str()) - 1]);
            message = race->AddPlant(newPlant);
            SaveRace(*race);
            newPlant->SetRace(race);
            return;
        }
        else
        {
            message = "������������ �������� �����";
            continue;
        }
    }
} 

Appointment GardenManager::CreateAppointment()
{
    Appointment Appointment;
    vector<string> characteristicts(
        {
            "�������� �� �������� ����������� ������?",
            "������������ �� ��� � ��������?",
            "������������ �� ��� � ����?",
            "����� �� ������������ ��������?",
            "���������� �� ��� ���?"
        });
    int i = 0;
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ����������" << endl;
        cout << characteristicts[i] << endl;
        cout << "�� - 1\n��� - 2" << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����!";
            continue;
        }

        int value = atoi(input->GetInput().c_str());
        if (value == 1 || value == 2)
        {
            switch (i)
            {
            case 0:
                Appointment.is_oxygen_maker = value == 1;
                break;
            case 1:
                Appointment.has_therapeutic_benefit = value == 1;
                break;
            case 2:
                Appointment.has_food_value = value == 1;
                break;
            case 3:
                Appointment.has_aesthetic_value = value == 1;
                break;
            case 4:
                Appointment.is_endangered_specie = value == 1;
                break;
            }
        }
        else
        {
            message = "������������ �������� �����!";
            continue;
        }


        if (++i == characteristicts.size())
            break;
    }

    input->Clear();
    ClearScreen();
    cout << "\"������������ ���\"" << endl;
    cout << "�������� ��������" << endl;
    cout << "����� � ���� - 9" << endl;
    cout << (message.empty() ? "" : message + "\n");
    message.clear();
    cout << "�������� ����������" << endl;
    cout << "������� �������������� ����������:" << endl;

    input->InputLine();
    if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
        throw("Back");

    Appointment.additional_info = input->GetInput();
    return Appointment;
}

int GardenManager::SetPlantCount()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "������� ���������� ����������� ������� �������� � ����: ";

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (!input->OnlyDigits())
        {
            message = "������������ ����";
            continue;
        }

        return atoi(input->GetInput().c_str());
    }

}

vector<PlantSpecies> GardenManager::SetCompatibles()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� ����������� ���� (\"�����\" \"�������\" \"������\" \"�����\" ...)" << endl;

        for (int i = 0; i <= (int)PlantSpecies::FLOWERY; i++)
            cout << i + 1 << ") " << Plant::GetSpecieStringValue(PlantSpecies(i)) << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (input->OnlyLetters())
        {
            message = "������������ ����";
            continue;
        }

        try
        {
            vector<PlantSpecies> species;
            for (auto choice : Strtok(input->GetInput(), ','))
            {
                if (choice[0] == ' ')
                    choice = choice.substr(1, strlen(choice.c_str()) - 1);
                species.push_back(PlantSpecies(atoi(choice.c_str())));
            }
            return species;
        }
        catch (...)
        {
            message = "������������ ������ �����";
            continue;
        }
    }
}

void GardenManager::SavePlant(Plant newPlant)
{
    vector<Plant> c = SearchPlants();
    for (auto it = c.begin(); it < c.end(); it++)
        if (it->GetName() == newPlant.GetName())
        {
            c.erase(it);
            break;
        }
    c.push_back(newPlant);
    ofstream file(this->PlantsAddress, ios::trunc);
    if (file.is_open())
        for (auto plant : c)
        {
            file << plant.GetName() << '$' << (plant.GetRace() == nullptr ? "X" :
                plant.GetRace()->GetName()) << "$" << plant.GetCount()  << "$"
                << (int)plant.GetFamily() << "$" << (int)plant.GetSpecie()
                << "$" << plant.GetAppointment().is_oxygen_maker << "|"
                << plant.GetAppointment().has_therapeutic_benefit << "|"
                << plant.GetAppointment().has_food_value << "|"
                << plant.GetAppointment().has_aesthetic_value << "|"
                << plant.GetAppointment().is_endangered_specie << "|"
                << plant.GetAppointment().additional_info << "$";

            for (auto i : plant.GetCompatible())
                file << (int)i << "|";
            file << endl;
        }
    file.close();
    this->message = "�������� " + newPlant.GetName() + " ������� ������� ��� ��������!";
}


//���� ���������� ������
void GardenManager::CreateRace()
{
    Race newRace;

    try
    {
        newRace.SetName(CreateRaceName());
        AddingPlantsToRace(&newRace);
    }
    catch (...)
    {
        return;
    }
 
    SaveRace(newRace);
}

string GardenManager::CreateRaceName()
{
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "������� �������� ����: " << endl;

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw "Back";

        if (!input->OnlyLetters())
        {
            message = "�������� ������ ��������� ������ �����!";
            continue;
        }

        if (input->GetInputSize() < 3)
        {
            message = "�������� ������ �������� ��� ������� �� ���� ����!";
            continue;
        }

        if (ObjectExist(input->GetInput(), this->PlantRacesAddress))
        {
            message = "��� � ����� ������ ��� �������";
            continue;
        }

        return input->GetInput();
    }

}

void GardenManager::SaveRace(Race newRace)
{
    string plants = "";
    auto races = SearchRaces();
    for(auto it = races.begin(); it < races.end(); it++)
        if (it->GetName() == newRace.GetName())
        {
            races.erase(it);
            break;
        }
    races.push_back(newRace);
    ofstream file(this->PlantRacesAddress, ios::trunc);
    if (file.is_open())
        for (auto race : races)
        {
            file << race.GetName() << '$';

            if (race.GetPlants().size() != 0)
            {
                for (auto plant : race.GetPlants())
                    plants += plant->GetName() + '|';
                plants.pop_back();
                file << plants;
            }
            file << endl;
            plants.clear();
        }
    file.close();
    this->message = "��� " + newRace.GetName() + " ������� ������ ��� �������!";
}

void GardenManager::AddingPlantsToRace(Race* newRace)
{
    auto objs = SearchPlants();
    int count = 0;
    for (auto obj : objs)
        if (obj.GetRace() == nullptr)
            count++;
    if (count == 0)
        return;

    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty() ? "" : message + "\n");
        message.clear();
        cout << "�������� �������� � ���?" << endl;
        cout << "1 - ��\n";
        cout << "2 - ���\n";

        input->InputLine();

        if (!input->OnlyDigits() || input->GetInputSize() > 1)
        {
            message = "������������ ����";
            continue;
        }

        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            return;

        if (input->GetInput() == "1")
            break;

        if (input->GetInput() == "2")
            return;
    }
    while (true)
    {
        input->Clear();
        ClearScreen();
        cout << "\"������������ ���\"" << endl;
        cout << "�������� ���� ��������" << endl;
        cout << "����� � ���� - 9" << endl;
        cout << (message.empty()? "" : message + "\n");
        message.clear();
        cout << "�������� �������� (\"�����\" \"�������\" \"������\" \"�����\" ...)" << endl;

        ifstream file(this->PlantsAddress);
        vector<string> plantNames;
        string buf;
        int i = 1;
        if (file.is_open())
        {
            while (!file.eof())
            {
                getline(file, buf);
                if (!buf.empty())
                {
                    auto plant = Strtok(buf, '$');
                    if (plant[1] == "X")
                    {
                        plantNames.push_back(plant[0]);
                        cout << i++ << ") " << plant[0] << endl;
                    }
                }
            }
        }
        file.close();

        input->InputLine();
        if (input->OnlyDigits() && atoi(input->GetInput().c_str()) == BACK)
            throw("Back");

        if (input->OnlyLetters())
        {
            message = "������������ ����";
            continue;
        }

        auto values = Strtok(input->GetInput(), ',');
        for (auto value : values)
        {
            if (value[0] == ' ')
                value = value.substr(value[1], strlen(value.c_str()) - 1);
            if (atoi(value.c_str()) > plantNames.size())
                continue;
            auto plant = GetPlant(plantNames[atoi(value.c_str()) - 1], nullptr);
            message += newRace->AddPlant(new Plant(plant)) + "\n";
            plant.SetRace(newRace);
            SavePlant(plant);
        }
        return;
    }
}


//����� ������
void GardenManager::ClearScreen() //� ���������
{
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
}

vector<string> GardenManager::Strtok(string input, char separator)
{
    vector<string> res;
    string buf;
    for (auto i : input)
    {
        if (i == separator)
        {
            if (!buf.empty())
            {
                res.push_back(buf);
                buf.clear();
            }
            continue;
        }
        buf.push_back(i);
    }
    if (!buf.empty())
        res.push_back(buf);
    return res;
}

bool GardenManager::ObjectExist(string name, string address)
{
    ifstream file(address);
    string buf;
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, buf);
            if (!buf.empty())
                if (Strtok(buf, '$')[0] == name)
                    return true;
        }
    }

    return false;
}


//������ ��������� �� ������
vector<Plant> GardenManager::SearchPlants()
{
    string buf;
    vector<Plant> res;
    ifstream file(this->PlantsAddress);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, buf);
            if (!buf.empty())
            {
                auto plant = Strtok(buf, '$');
                res.push_back(CreatePlantFromFile(plant, nullptr));
            }
        }
    }
    file.close();
    return res;
}

Plant GardenManager::GetPlant(string name, Race * owner)
{
    string buf;
    ifstream file(this->PlantsAddress);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, buf);
            auto plant = Strtok(buf, '$');
            if (!buf.empty() && plant[0] == name)
            {
                file.close();
                return CreatePlantFromFile(plant, owner);
            }
        }
    }
    file.close();
    throw("NON plant");
}

Plant GardenManager::CreatePlantFromFile(vector<string> values, Race * owner)
{
    Plant plant;
    plant.SetName(values[0]);
    plant.SetRace(owner != nullptr ? owner : 
        values[1] == "X" ? nullptr : new Race(move(GetRace(values[1], &plant))));
    plant.SetCount(atoi(values[2].c_str()));
    plant.SetFamily(PlantFamily(atoi(values[3].c_str())));
    plant.SetSpecie(PlantSpecies(atoi(values[4].c_str())));

    Appointment appointment;
    auto app_values = Strtok(values[5], '|');
    appointment.is_oxygen_maker = app_values[0] == "1";
    appointment.has_therapeutic_benefit = app_values[1] == "1";
    appointment.has_food_value = app_values[2] == "1";
    appointment.has_aesthetic_value = app_values[3] == "1";
    appointment.is_endangered_specie = app_values[4] == "1";
    appointment.additional_info = app_values[5];

    plant.SetAppointment(appointment);

    vector<PlantSpecies> c;
    for (auto value : Strtok(values[6], '|'))
        c.push_back(PlantSpecies(atoi(value.c_str())));

    plant.SetCompatible(c);
    return plant;
}

vector<Race> GardenManager::SearchRaces()
{
    string buf;
    vector<Race> res;
    ifstream file(this->PlantRacesAddress);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, buf);
            if (!buf.empty())
            {
                auto race = Strtok(buf, '$');
                res.push_back(CreateRaceFromFile(race, nullptr));
            }
        }
    }
    return res;
}

Race GardenManager::GetRace(string name, Plant * owner)
{
    string buf;
    ifstream file(this->PlantRacesAddress);
    if (file.is_open())
    {
        while (!file.eof())
        {
            getline(file, buf);
            auto race = Strtok(buf, '$');
            if (!buf.empty() && race[0] == name)
            {
                file.close();
                return CreateRaceFromFile(race, owner);
            }
        }
    }
    file.close();
    throw("Non race");
}

Race GardenManager::CreateRaceFromFile(vector<string> values, Plant* owner)
{
    Race res(values[0]);
    if (values.size() > 1)
        for (auto plant : Strtok(values[1], '|'))
        {
            if (owner != nullptr && owner->GetName() == plant)
                res.AddPlant(owner);
            else
            {
                try
                {
                    res.AddPlant(new Plant(move(GetPlant(plant, &res))));
                }
                catch (...)
                {}
            }
        }

    return res;
}

