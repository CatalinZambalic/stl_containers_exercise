//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//

#include "stdafx.h"
#include "..\include\VectorApi.h"
#include <fstream>
#include <iostream>
#include <string>

VectorApi::VectorApi() {}

void VectorApi::ReadFromFile(const std::string& file_name)
{
	_people.clear();
	std::string line;
	std::ifstream myFile(file_name);

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			if (line == "")
				break;

			PersonPtr _person = ReturnPerson(line);
			_people.push_back(_person);
		}
	}
	else
	{
		std::cout << "Unable to open file.";
	}
	myFile.close();
}

PersonPtr VectorApi::ReturnPerson(std::string text_line)
{
	/*std::vector<std::string> result;
	for (size_t i = text_line.find(' '); i < std::string::npos; i = text_line.find(' ', i))
	{
		result.push_back(text_line.substr(i, text_line.find_first_of(",")));
	}

	std::string first_name = result[0];
	std::string last_name = result[1];
	int age = stoi(result[2]);
	Gender gender = result[3] == "Male" ? kGender_Male : kGender_Female;
	float height = stof(result[4]);
	double weight = stod(result[5]);
	bool married = result[6] == "true" ? true : false;
	std::string address = result[7];
	std::string phone_number = result[8];
	std::string email = result[9];*/


	std::string first_name = GetData(text_line,1);
	std::string last_name = GetData(text_line,2);
	int age = stoi(GetData(text_line,3));
	Gender gender = GetData(text_line,4) == "Male" ? kGender_Male : kGender_Female;
	float height = stof(GetData(text_line,5));
	double weight = stod(GetData(text_line,6));
	bool married = GetData(text_line,7) == "true" ? true : false;
	std::string address = GetData(text_line,8);
	std::string phone_number = GetData(text_line,9);
	std::string email = text_line.substr(text_line.find_last_of(",") + 1);

	return std::make_shared<Person>(first_name, last_name, age, gender, height, weight, married, address, phone_number, email);
}

std::string VectorApi::GetData(std::string data,int comma)
{
	std::string data_resulted;
	for (int i = 0; i < comma; i++)
	{
		data_resulted = data.substr(0, data.find_first_of(","));
		data = data.substr(data.find_first_of(",") + 1);
	}
	return data_resulted;
}

void VectorApi::DisplayData()
{
	int length = _people.size();

	for (int i = 0; i < length; i++)
	{
		std::cout << _people[i]->GetFirstName() << "," << _people[i]->GetLastName() << "," << _people[i]->GetAge() << "," << (_people[i]->GetGender() == kGender_Male ? "Male" : "Female") << ","
			<< _people[i]->GetHeight() << "," << _people[i]->GetWeight() << "," << (_people[i]->IsMarried() == true ? "true" : "false") << "," << _people[i]->GetAddress() << ","
			<< _people[i]->GetPhoneNumber() << "," << _people[i]->GetEmail() << std::endl << std::endl;
	}
}