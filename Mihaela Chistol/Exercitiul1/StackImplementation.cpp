#include "stdafx.h"
#include "StackImplementation.h"


StackImplementation::StackImplementation()
{
}

void StackImplementation::ReadFromFile(const std::string & file_name)
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
      _persons.push(std::make_shared<Person>(person));
      }
    }

  input_file.close();
}

void StackImplementation::DisplayPersons()
{
  while (!_persons.empty())
  {
    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "First name: " << _persons.top()->GetFirstName() << std::endl;
    std::cout << "Last name: " << _persons.top()->GetLastName() << std::endl;
    std::cout << "Age: " << _persons.top()->GetAge() << std::endl;
    std::cout << "Gender: " << (_persons.top()->GetGender() == Person::kGender_Male ? "Male" : "Female") << std::endl;
    std::cout << "Heigth: " << _persons.top()->GetHeight() << std::endl;
    std::cout << "Weigth: " << _persons.top()->GetWeight() << std::endl;
    std::cout << "Married: " << (_persons.top()->GetMarried() ? "true" : "false") << std::endl;
    std::cout << "Address: " << _persons.top()->GetAddress() << std::endl;
    std::cout << "Phone: " << _persons.top()->GetPhoneNumber() << std::endl;
    std::cout << "Email: " << _persons.top()->GetEmail() << std::endl;
    
    _persons.pop();
  }
}


