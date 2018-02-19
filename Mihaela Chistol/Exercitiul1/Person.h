#pragma once

#include "stdafx.h"

class Person
{
public:
  enum Gender
  { 
    kGender_Male,
    kGender_Female
  };

  Person(const std::string first_name, const std::string last_name, int age, Gender gender, float heigth, double weight, bool married, const std::string address, const std::string phone_number, const std::string email);

  int GetAge() const;
  float GetHeight() const;
  double GetWeight() const;
  bool GetMarried() const;
  std::string GetFirstName() const;
  std::string GetLastName() const;
  std::string GetAddress() const;
  std::string GetPhoneNumber() const;
  std::string GetEmail() const;
  Gender GetGender() const;

private:
  int _age;
  float _heigth;
  double _weight;
  bool _married;
  std::string _first_name;
  std::string _last_name;
  std::string _address;
  std::string _phone_number;
  std::string _email;

  Gender _gender;
};

typedef std::shared_ptr<Person> PersonPtr;

