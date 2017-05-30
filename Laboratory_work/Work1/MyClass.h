#pragma once
#include<string>
#include<iostream>

class Student
{
	std::string name, surname, patronymic;
	std::string city, educational, group;
	int year, phone;
public:
	Student() {};
	~Student() = default;

	void setName(const std::string value);
	void setSurname(const std::string value);
	void setPatronymic(const std::string value);
	void setCity(const std::string value);
	void setEducational(const std::string value);
	void setGroup(const std::string value);
	void setYear(const int value);
	void setPhone(const int value);

	std::string getName() const;
	std::string getSurname() const;
	std::string getPatronymic() const;
	std::string getCity() const;
	std::string getEducational() const;
	std::string getGroup() const;
	int getYear() const;
	int getPhone() const;

	void init();
	void print();
	void choice();
};
