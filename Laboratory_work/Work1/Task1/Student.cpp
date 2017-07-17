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

void Student::init()
{
	std::cout << "Welcome. I the result of your first laboratory work.\n"; // Добро пожаловать. Я результат вашей первой лабораторной работы.
	std::cout << "Please enter your details.\n\n"; // Пожалуйста, введите свои данные.

	std::cout << "Enter your name: "; // Введите ваше имя
	std::cin >> name;
	setName(name);

	std::cout << "Enter your last name: "; // Введите свою фамилию
	std::cin >> surname;
	setSurname(surname);

	std::cout << "Enter your patronymic: "; // Введите ваше отчество
	std::cin >> patronymic;
	setPatronymic(patronymic);

	std::cout << "Enter your year of birth: "; // Введите свой год рождения
	std::cin >> year;
	setYear(year);

	std::cout << "Enter your contact number: "; // Введите свой контактный номер
	std::cin >> phone;
	setPhone(phone);

	std::cout << "Enter the name of the city where you registered: "; // Введите название города, в котором вы прописаны
	std::cin >> city;
	setCity(city);

	std::cout << "Enter the name of the institution where you study: "; // Введите название учебного завидения в котором вы учитесь
	std::cin >> university;
	setUniversity(university);

	std::cout << "Finally, enter your group number: "; // Наконец, введите номер своей группы
	std::cin >> group;
	setGroup(group);

	system("cls");
}

void Student::print()
{
	std::cout << "\nYour name, surname, patronymic: "; // Ваше имя, фамилия, отчество
	std::cout << getName() + " " + getSurname() + " " + getPatronymic() << std::endl;

	std::cout << "Your year of birth: " << getYear() << std::endl; // Ваш год рождения

	std::cout << "Your contact phone number: " << getPhone() << std::endl; // Ваш контактный номер телефона

	std::cout << "The name of the city in which you are registered: "; // Название города в котором Вы прописаны
	std::cout << getCity() << std::endl;

	std::cout << "Name of the University institution in which you study: "; // Название учебного заведения, в котором вы учитесь
	std::cout << getUniversity() << std::endl;

	std::cout << "Number of your group in an University institution: "; // Номер вашей группы в учебном заведении
	std::cout << getGroup() << "\n" << std::endl;
}

void Student::choice()
{
	bool done = true;
	while (done)
	{
		std::cout << "Do you want to change something?\n1 - Place of registration;\n2 - University institution;\n3 - Group number;\n4 - Phone; \n0 - I'm satisfied with everything.\nYour choice: ";
		// Вы хотите что-то изменить? 1 - Место прописки 2 - Учебное заведение 3 - Номер группы 4 - Телефон 0 - Я доволен всем. Ваш выбор:

		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
				  std::cout << "\nEnter new place of registration: "; // Введите новое место прописки
				  std::cin >> city;
				  setCity(city);
				  system("cls");

				  std::cout << "Your changed data."; // Ваши измененные данные
				  print();

				  break;
		}
		case 2:
		{
				  std::cout << "\nEnter a new name for the University institution: "; // Введите новое название учебного заведения
				  std::cin >> university;
				  setUniversity(university);
				  system("cls");

				  std::cout << "Your changed data."; // Ваши измененные данные
				  print();

				  break;
		}
		case 3:
		{
				  std::cout << "\nEnter new group number: "; // Введите новый номер группы
				  std::cin >> group;
				  setGroup(group);
				  system("cls");

				  std::cout << "Your changed data."; // Ваши измененные данные
				  print();

				  break;
		}
		case 4:
		{
				  std::cout << "\nEnter a new phone number: "; // Введите новый номер телефона
				  std::cin >> phone;
				  setPhone(phone);
				  system("cls");

				  std::cout << "Your changed data."; // Ваши измененные данные
				  print();

				  break;
		}
		case 0:
		{
				  std::cout << "\nTo print, press Enter to exit the program.\n"; // Печать, нажмите Enter что бы выйти из программы

				  std::cin.get();
				  std::cin.get();
				  done = false;
				  break;
		}
		default:
			std::cout << "\nThere is no such item in the menu!\n" << std::endl; // В меню нет такого элемента!
		}
	}
}
