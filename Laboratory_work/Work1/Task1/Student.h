#pragma once
#include<string>

class Student
{
	std::string name, surname, patronymic, city, university, group, phone;
	size_t year;
public:
	Student() = default;
	Student(const std::string, const std::string, const std::string, const size_t);
	~Student() = default;

	void setName(const std::string value);
	void setSurname(const std::string value);
	void setPatronymic(const std::string value);
	void setCity(const std::string value);
	void setUniversity(const std::string value);
	void setGroup(const std::string value);
	void setYear(const size_t value);
	void setPhone(const std::string value);

	std::string getName() const;
	std::string getSurname() const;
	std::string getPatronymic() const;
	std::string getCity() const;
	std::string getUniversity() const;
	std::string getGroup() const;
	size_t getYear() const;
	std::string getPhone() const;

	void init();
	void print();
	void choice();
};
