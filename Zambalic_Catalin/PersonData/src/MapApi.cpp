//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//

#include "stdafx.h"
#include "..\include\MapApi.h"
#include <fstream>
#include <iostream>
#include <string>


MapApi::MapApi() {}

void MapApi::ReadFromFile(const std::string& file_name)
{
	while (!_people.empty())
	{
		_people.clear();
	}

	std::string line;
	std::ifstream myFile(file_name);

	if (myFile.is_open())
	{
		int i = 0;
		while (getline(myFile, line))
		{
			if (line == "")
				break;

			PersonPtr _person = ReturnPerson(line);
			_people[std::to_string(i)] = _person;
			i++;
		}
	}
	else
	{
		std::cout << "Unable to open file.";
	}
	myFile.close();
}

PersonPtr MapApi::ReturnPerson(std::string text_line)
{
	std::string delimiter = ",";

	//Sets First Name
	std::string first_name = text_line.substr(0, text_line.find_first_of(delimiter));
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets Last Name
	std::string last_name = text_line.substr(0, text_line.find_first_of(delimiter));
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets Age
	int age = stoi(text_line.substr(0, text_line.find_first_of(delimiter)));
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets Gender
	Gender gender = text_line.substr(0, text_line.find_first_of(delimiter)) == "Male" ? kGender_Male : kGender_Female;
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets Height
	float height = stof(text_line.substr(0, text_line.find_first_of(delimiter)));
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets Weight
	double weight = stod(text_line.substr(0, text_line.find_first_of(delimiter)));
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets PersonalState
	bool married = text_line.substr(0, text_line.find_first_of(delimiter)) == "true" ? true : false;
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets Address
	std::string address = text_line.substr(0, text_line.find_first_of(delimiter));
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets Phone Number
	std::string phone_number = text_line.substr(0, text_line.find_first_of(delimiter));
	text_line = text_line.substr(text_line.find_first_of(delimiter) + 1);

	//Sets E-mail Adress
	std::string email = text_line;

	return std::make_shared<Person>(first_name, last_name, age, gender, height, weight, married, address, phone_number, email);
}

void MapApi::DisplayData()
{
	int length = _people.size();

	for (int i = 0; i < length; i++)
	{
		std::string index = std::to_string(i);

		std::cout << _people[index]->GetFirstName() << "," << _people[index]->GetLastName() << "," << _people[index]->GetAge() << "," << (_people[index]->GetGender() == kGender_Male ? "Male" : "Female") << ","
			<< _people[index]->GetHeight() << "," << _people[index]->GetWeight() << "," << (_people[index]->IsMarried() == true ? "true" : "false") << "," << _people[index]->GetAddress() << ","
			<< _people[index]->GetPhoneNumber() << "," << _people[index]->GetEmail() << std::endl << std::endl;
	}
}