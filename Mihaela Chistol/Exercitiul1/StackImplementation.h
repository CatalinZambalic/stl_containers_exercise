#pragma once
#include "stdafx.h"
#include "Person.h"

class StackImplementation
{
public:
  StackImplementation();
  void ReadFromFile(const std::string & file_name);
  void DisplayPersons();

private:
  std::stack <PersonPtr> _persons;
};

