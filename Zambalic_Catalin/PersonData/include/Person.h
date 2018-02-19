//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//
#pragma once

#include <memory>
#include <string>

enum Gender
{
	kGender_Male,
	kGender_Female
};

class Person
{
public:
	Person(const std::string& first_name, const std::string& last_name, int age, Gender gender, float height, double weight, bool married, const std::string& address, const std::string& phone_number, const std::string& email);

	std::string GetFirstName() const { return _first_name; }
	std::string GetLastName() const { return _last_name; }
	std::string GetAddress() const { return _address; }
	std::string GetPhoneNumber() const { return _phone_number; }
	std::string GetEmail() const { return _email; }
	int GetAge() const { return _age; }
	float GetHeight() const { return _height; }
	double GetWeight() const { return _weight; }
	bool IsMarried() const { return _married; }
	Gender GetGender() const { return _gender; }

private:
	std::string _first_name;
	std::string _last_name;
	std::string _address;
	std::string _phone_number;
	std::string _email;
	int _age;
	float _height;
	double _weight;
	bool _married;
	Gender _gender;
};

typedef std::shared_ptr<Person> PersonPtr;
