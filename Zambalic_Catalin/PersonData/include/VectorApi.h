#pragma once
//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//

#pragma once

#include <iostream>
#include <vector>
#include "..\include\Person.h"

class VectorApi
{
public:

	VectorApi();

	std::vector<PersonPtr> GetPeople() const { return _people; }
	std::string GetData(std::string data, int comma);
	PersonPtr ReturnPerson(std::string);
	void ReadFromFile(const std::string&);
	void DisplayData();

private:
	std::vector<PersonPtr> _people;
};