
#pragma once
#include "stdafx.h"
#include "Person.h"

class VectorImplementation
{
public:
  VectorImplementation();
  void ReadFromFile(const std::string& file_name);
  void DisplayPersons();
  std::vector<PersonPtr> GetPersons() const;

private:
  std::vector<PersonPtr> _persons;
};

