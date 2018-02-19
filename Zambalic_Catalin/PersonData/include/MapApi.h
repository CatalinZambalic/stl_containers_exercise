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
#include <map>
#include "..\include\Person.h"

class MapApi
{
public:

	MapApi();

	std::map<std::string, PersonPtr> GetPeople() const { return _people; }
	PersonPtr ReturnPerson(std::string);
	void ReadFromFile(const std::string&);
	void DisplayData();

private:
	std::map<std::string, PersonPtr> _people;
};