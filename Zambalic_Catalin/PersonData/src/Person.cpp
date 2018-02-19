//
// Copyright(c) 2018 ASSIST Software
// http://assist-software.net
//
// For information about the licensing and copyright of this software please
// contact ASSIST Software at hello @ assist.ro
//

#include "stdafx.h"
#include "..\include\Person.h"

Person::Person(const std::string& first_name, const std::string& last_name, int age, Gender gender, float height, double weight, bool married, const std::string& address, const std::string& phone_number, const std::string& email)
{
	_first_name = first_name;
	_last_name = last_name;
	_age = age;
	_gender = gender;
	_height = height;
	_weight = weight;
	_married = married;
	_address = address;
	_phone_number = phone_number;
	_email = email;
}