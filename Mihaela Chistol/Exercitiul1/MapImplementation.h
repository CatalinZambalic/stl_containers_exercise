#pragma once
#include "stdafx.h"
#include "Person.h"

class MapImplementation
{
public:
  MapImplementation();
  void ReadFromFile(const std::string & file_name);
  void DisplayPersons();

private:
  std::map <std::string, PersonPtr> _persons;
};

