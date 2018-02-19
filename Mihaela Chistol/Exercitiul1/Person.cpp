#include "stdafx.h"
#include "Person.h"

Person::Person(const std::string first_name, const std::string last_name, int age, Gender gender, float heigth, double weight, bool married, const std::string address, const std::string phone_number, const std::string email)
  : _first_name(first_name),
    _last_name(last_name),
    _age(age),
    _gender(gender),
    _heigth(heigth),
    _weight(weight),
    _address(address),
    _phone_number(phone_number),
    _email(email)

{

}

int Person::GetAge() const
{
  return _age;
}

float Person::GetHeight() const
{
 return _heigth;
}

double Person::GetWeight() const
{
  return _weight;
}

bool Person::GetMarried() const
{
  return _married;
}

std::string Person::GetFirstName() const
{
  return _first_name;
}

std::string Person::GetLastName() const
{
  return _last_name;
}

std::string Person::GetAddress() const
{
  return _address;
}

std::string Person::GetPhoneNumber() const
{
  return _phone_number;
}

std::string Person::GetEmail() const
{
  return _email;
}

Person::Gender Person::GetGender() const
{
  return _gender;
}

