#include "Student.h"
#include <iostream>

Student::Student(const std::string a, const std::string b, const std::string c, const size_t d) : name(a), surname(b), patronymic(c), year(d) {}

void Student::setName(const std::string value)
{
	name = value;
}

void Student::setSurname(const std::string value)
{
	surname = value;
}

void Student::setPatronymic(const std::string value)
{
	patronymic = value;
}

void Student::setCity(const std::string value)
{
	city = value;
}

void Student::setUniversity(const std::string value)
{
	university = value;
}

void Student::setGroup(const std::string value)
{
	group = value;
}

void Student::setYear(const size_t value)
{
	year = value;
}

void Student::setPhone(const std::string value)
{
	phone = value;
}

std::string Student::getName() const
{
	return name;
}

std::string Student::getSurname() const
{
	return surname;
}

std::string Student::getPatronymic() const
{
	return patronymic;
}

std::string Student::getCity() const
{
	return city;
}

std::string Student::getUniversity() const
{
	return university;
}

std::string Student::getGroup() const
{
	return group;
}

size_t Student::getYear() const
{
	return year;
}

std::string Student::getPhone() const
{
	return phone;
}
