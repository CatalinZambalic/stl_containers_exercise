
#pragma once
#include "stdafx.h"
#include "Person.h"

class QueueImplementation
{
public:
  QueueImplementation();
  void ReadFromFile(const std::string & file_name);
  void DisplayPersons();

private:
  std::queue <PersonPtr> _persons;
};

