//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//

#include "stdafx.h"
#include "..\include\ListApi.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>

ListApi::ListApi() {}

void ListApi::ReadFromFile(const std::string& file_name)
{
	_people.clear();
	std::string line;
	std::ifstream myFile(file_name);

	if (myFile.is_open())
	{
		while (std::getline(myFile, line))
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

PersonPtr ListApi::ReturnPerson(std::string text_line)
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

void ListApi::DisplayData()
{
	for (auto it = _people.begin(); it != _people.end(); ++it)
	{
		std::cout << (*it)->GetFirstName() << "," << (*it)->GetLastName() << "," << (*it)->GetAge() << "," << ((*it)->GetGender() == kGender_Male ? "Male" : "Female") << ","
			<< (*it)->GetHeight() << "," << (*it)->GetWeight() << "," << ((*it)->IsMarried() == true ? "true" : "false") << "," << (*it)->GetAddress() << ","
			<< (*it)->GetPhoneNumber() << "," << (*it)->GetEmail() << std::endl << std::endl;
	}
}