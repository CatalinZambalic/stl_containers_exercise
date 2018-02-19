//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//

#include "stdafx.h"
#include "../include/Person.h"
#include "../include/VectorApi.h"
#include "../include/ListApi.h"
#include "../include/QueueApi.h"
#include "../include/StackApi.h"
#include "../include/MapApi.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <conio.h>

void MakeFile(const std::string&);
void WriteToFile(const std::vector<Person>&, const std::string&);

PersonPtr ReturnPerson(std::string);

int main(int argc, char* argv[])
{
	const std::string kNameFile = "data.txt";
	MakeFile(kNameFile);

	//For build solution
	//*argv[1] = '1'; 0 but need access to write

	switch (*argv[1])
	{
	case '1':
	{
		//////////////////////////// Using VectorAPI ///////////////////////////////

		VectorApi vector_api = VectorApi();
		vector_api.ReadFromFile(kNameFile);
		vector_api.DisplayData();
		std::cout << "Resolved using VectorApi." << std::endl; _getch();
		break;
	}

	case '2':
	{
		//////////////////////////// Using ListAPI ///////////////////////////////

		ListApi list_api = ListApi();
		list_api.ReadFromFile(kNameFile);
		list_api.DisplayData();
		std::cout << "Resolved using ListApi." << std::endl; _getch();
		break;
	}

	case '3':
	{
		//////////////////////////// Using QueueAPI ///////////////////////////////

		QueueApi queue_api = QueueApi();
		queue_api.ReadFromFile(kNameFile);
		queue_api.DisplayData();
		std::cout << "Resolved using QueueApi." << std::endl; _getch();
		break;
	}

	case '4':
	{
		//////////////////////////// Using StackAPI ///////////////////////////////

		StackApi stack_api = StackApi();
		stack_api.ReadFromFile(kNameFile);
		stack_api.DisplayData();
		std::cout << "Resolved using StackApi." << std::endl; _getch();
		break;
	}

	case '5':
	{
		//////////////////////////// Using MapAPI ///////////////////////////////

		MapApi map_api = MapApi();
		map_api.ReadFromFile(kNameFile);
		map_api.DisplayData();
		std::cout << "Resolved using MapApi." << std::endl; _getch();
		break;
	}

	default:
		std::cout << "Option unavailable!" << std::endl;
	}

	return 0;
}

/////////////////////////////////////// Start Writing File //////////////////////////////////////////
void MakeFile(const std::string& file_name)
{
	std::vector<Person> people;

	people.push_back(Person("Alex", "Cosmin", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Alex", "Andrei", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Alfred", "Alexandru", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Gabriel", "Salateanu", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Alex", "Cosmin", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Alex", "Cosmin", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Alex", "Cosmin", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Alex", "Cosmin", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));
	people.push_back(Person("Alex", "Cosmin", 23, kGender_Male, 1.73f, 72.5, false, "Str.Gheorghe Doja|nr.1|bl.12|ap.4", "0758145234", "alex.cosmin@gmail.com"));

	WriteToFile(people, file_name);
}

void WriteToFile(const std::vector<Person>& people, const std::string& file_name)
{
	std::ofstream outfile;
	outfile.open(file_name, std::ios_base::out);

	for (int i = 0; i < people.size(); i++)
	{
		outfile << people[i].GetFirstName() << "," << people[i].GetLastName() << "," << people[i].GetAge() << "," << (people[i].GetGender() == kGender_Male ? "Male" : "Female") << ","
			<< people[i].GetHeight() << "," << people[i].GetWeight() << "," << (people[i].IsMarried() ? "true" : "false") << "," << people[i].GetAddress() << ","
			<< people[i].GetPhoneNumber() << "," << people[i].GetEmail() << '\n';
	}

	outfile.close();
}
//////////////////////////////////////// End Writing File /////////////////////////////////////////////