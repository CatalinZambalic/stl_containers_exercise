//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//


#include "stdafx.h"
#include "VectorImplementation.h"
#include "ListImplementation.h"
#include "QueueImplementation.h"
#include "StackImplementation.h"
#include "MapImplementation.h"

enum Option
{
  kVECTOR = 1,
  kLIST = 2,
  kQUEUE = 3,
  kSTACK = 4,
  kMAP = 5
};


int main(int argc, const char * argv[])
{
  if (argc != 2)
  {
    std::cerr << "No parameter!" << std::endl;
    return -1;
  }
  
  int my_choise = std::stoi(argv[1]);
  std::string file_name = "input.txt";

  if (std::experimental::filesystem::exists(file_name))
  {
    switch (my_choise)
    {
    case kVECTOR:
    {
      std::cout << "\tVector implementation" << std::endl;
      VectorImplementation vect;
      vect.ReadFromFile(file_name);
      vect.DisplayPersons();
      break;
    }
    case kLIST:
    {
      std::cout << "\tList implementation" << std::endl;
      ListImplementation list;
      list.ReadFromFile(file_name);
      list.DisplayPersons();
      break;
    }
    case kQUEUE:
    {
      std::cout << "\tQueue implementation" << std::endl;
      QueueImplementation queue;
      queue.ReadFromFile(file_name);
      queue.DisplayPersons();
      break;
    }
    case kSTACK:
    {
      std::cout << "\tStack implementation" << std::endl;
      StackImplementation stack;
      stack.ReadFromFile(file_name);
      stack.DisplayPersons();
      break;
    }
    case kMAP:
    {
      std::cout << "\tMap implementation" << std::endl;
      MapImplementation map;
      map.ReadFromFile(file_name);
      map.DisplayPersons();
      break;
    }
    default:
      std::cerr << "Invalid parameter!" << std::endl;
      break;
    }
  }
  else
  {
    std::cerr << "No file!" << std::endl;
  }

  return 0;
}

