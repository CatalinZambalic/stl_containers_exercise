#pragma once
#include "stdafx.h"
#include "Person.h"

class ListImplementation
{
public:
  ListImplementation();

  void ReadFromFile(const std::string & file_name);
  void DisplayPersons();

private:
  std::list<PersonPtr> _persons;
};

