#include "stdafx.h"
#include "MapImplementation.h"


MapImplementation::MapImplementation()
{
}

void MapImplementation::ReadFromFile(const std::string & file_name)
{
  std::ifstream input_file(file_name);
  std::string line;
  const int kNumberOfArgsPerLine = 10;

  if (!input_file.is_open())
  {
    std::cout << "Unable to open file!";
    return;
  }
    
  while (std::getline(input_file, line))
  {
    std::vector<std::string> vector_strings;
    std::stringstream stream_line(line);
    std::string token;

    while (std::getline(stream_line, token, ','))
    {
      vector_strings.push_back(token);
    }

    if (vector_strings.size() == kNumberOfArgsPerLine)
    {
      std::string first_name = vector_strings[0];
      std::string last_name = vector_strings[1];
      std::string address = vector_strings[7];
      std::string phone_number = vector_strings[8];
      std::string email = vector_strings[9];
      int age = std::stoi(vector_strings[2]);
      float height = std::stof(vector_strings[4]);
      double weight = std::stod(vector_strings[5]);

      bool married = (vector_strings[6].compare("true") == 0);
      Person::Gender gender = (vector_strings[3].compare("Male") == 0) ? Person::kGender_Male : Person::kGender_Female;

      Person person(first_name, last_name, age, gender, height, weight, married, address, phone_number, email);
      _persons.insert(std::make_pair(first_name + " " + last_name, std::make_shared<Person>(person)));
    }
  }
 
  input_file.close();
}

void MapImplementation::DisplayPersons()
{
  for (auto it = _persons.begin(); it != _persons.end(); ++it)
  {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "KEY |" << it->first << "|" << std::endl;
    std::cout << "First name: " << it->second->GetFirstName() << std::endl;
    std::cout << "Last name: " << it->second->GetLastName() << std::endl;
    std::cout << "Age: " << it->second->GetAge() << std::endl;
    std::cout << "Gender: " << (it->second->GetGender() == Person::kGender_Male ? "Male" : "Female") << std::endl;
    std::cout << "Heigth: " << it->second->GetHeight() << std::endl;
    std::cout << "Weigth: " << it->second->GetWeight() << std::endl;
    std::cout << "Married: " << (it->second->GetMarried() ? "true" : "false") << std::endl;
    std::cout << "Address: " << it->second->GetAddress() << std::endl;
    std::cout << "Phone: " << it->second->GetPhoneNumber() << std::endl;
    std::cout << "Email: " << it->second->GetEmail() << std::endl << std::endl;
  }
}


