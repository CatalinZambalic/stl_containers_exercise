//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//

#include "stdafx.h"
#include "..\include\QueueApi.h"
#include <fstream>
#include <iostream>
#include <string>


QueueApi::QueueApi() {}

void QueueApi::ReadFromFile(const std::string& file_name)
{
	while (!_people.empty())
	{
		_people.pop();
	}

	std::string line;
	std::ifstream myFile(file_name);

	if (myFile.is_open())
	{
		while (getline(myFile, line))
		{
			if (line == "")
				break;

			PersonPtr _person = ReturnPerson(line);
			_people.push(_person);
		}
	}
	else
	{
		std::cout << "Unable to open file.";
	}
	myFile.close();
}

PersonPtr QueueApi::ReturnPerson(std::string text_line)
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

void QueueApi::DisplayData()
{
	auto tempQueue = _people;

	while (!tempQueue.empty())
	{
		std::cout << tempQueue.front()->GetFirstName() << "," << tempQueue.front()->GetLastName() << "," << tempQueue.front()->GetAge() << "," << (tempQueue.front()->GetGender() == kGender_Male ? "Male" : "Female") << ","
			<< tempQueue.front()->GetHeight() << "," << tempQueue.front()->GetWeight() << "," << (tempQueue.front()->IsMarried() == true ? "true" : "false") << "," << tempQueue.front()->GetAddress() << ","
			<< tempQueue.front()->GetPhoneNumber() << "," << tempQueue.front()->GetEmail() << std::endl << std::endl;

		tempQueue.pop();
	}
}