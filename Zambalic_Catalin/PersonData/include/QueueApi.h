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
#include <queue>
#include "..\include\Person.h"

class QueueApi
{
public:

	QueueApi();

	std::queue<PersonPtr> GetPeople() const { return _people; }
	PersonPtr ReturnPerson(std::string);
	void ReadFromFile(const std::string&);
	void DisplayData();

private:
	std::queue<PersonPtr> _people;
};