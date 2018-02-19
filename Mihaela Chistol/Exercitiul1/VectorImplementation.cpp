#include "stdafx.h"
#include "VectorImplementation.h"

VectorImplementation::VectorImplementation()
{}

std::vector<PersonPtr> VectorImplementation::GetPersons() const
{
  return _persons;
}

void VectorImplementation::ReadFromFile(const std::string & file_name)
{
  std::ifstream input_file(file_name);
  std::string line;
  const int kNumberOfArgsPerLine = 10;

  if (!input_file.is_open())
  {
    std::cout << "Unable to open file!";
    return;
  }
  _persons.clear();
  while (std::getline(input_file, line))
  {
    std::vector<std::string> vector_string;
    std::stringstream stream_line(line);
    std::string token;

    while (std::getline(stream_line, token, ','))
    {
      vector_string.push_back(token);
    }

    if (vector_string.size() == kNumberOfArgsPerLine)
    {
      std::string first_name = vector_string[0];
      std::string last_name = vector_string[1];
      std::string address = vector_string[7];
      std::string phone_number = vector_string[8];
      std::string email = vector_string[9];
      int age = std::stoi(vector_string[2]);
      float height = std::stof(vector_string[4]);
      double weight = std::stod(vector_string[5]);

      bool married = (vector_string[6].compare("true") == 0);
      Person::Gender gender = (vector_string[3].compare("Male") == 0) ? Person::kGender_Male : Person::Gender::kGender_Female;

      PersonPtr person = std::make_shared<Person>(first_name, last_name, age, gender, height, weight, married, address, phone_number, email);
      _persons.push_back(person);
    }
  }

  input_file.close();
}

void VectorImplementation::DisplayPersons()
{
  int number_persons = _persons.size();

  for (int i = 0; i < number_persons; i++)
  {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "FISRT NAME: " << _persons[i]->GetFirstName() << std::endl;
    std::cout << "LAST NAME: " << _persons[i]->GetLastName() << std::endl;
    std::cout << "AGE: " << _persons[i]->GetAge() << std::endl;
    std::cout << "GENDER: " << (_persons[i]->GetGender() == Person::Gender::kGender_Male ? "Male" : "Female") << std::endl;
    std::cout << "HEIGTH: " << _persons[i]->GetHeight() << std::endl;
    std::cout << "WEIGTH: " << _persons[i]->GetWeight() << std::endl;
    std::cout << "MARRIED: " << (_persons[i]->GetMarried() ? "true" : "false") << std::endl;
    std::cout << "ADDRESS: " << _persons[i]->GetAddress() << std::endl;
    std::cout << "PHONE: " << _persons[i]->GetPhoneNumber() << std::endl;
    std::cout << "EMAIL: " << _persons[i]->GetEmail() << std::endl;
  }
}





