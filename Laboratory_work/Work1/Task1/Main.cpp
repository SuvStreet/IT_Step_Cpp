#include "Student.h"
#include <iostream>

Student dima("0", "0", "0", 0);

void init();
void print();
void choice();


int main()
{
	init();

	std::cout << "According to your information, a business card was created."; // Согласно вашей информации, была создана визитная карточка
	print();

	choice();

	return 0;
}

void choice()
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
				  std::string city;
				  std::cout << "\nEnter new place of registration: "; // Введите новое место прописки
				  std::cin >> city;
				  dima.setCity(city);
				  system("cls");

				  std::cout << "Your changed data."; // Ваши измененные данные
				  print();

				  break;
		}
		case 2:
		{
				  std::string university;
				  std::cout << "\nEnter a new name for the University institution: "; // Введите новое название учебного заведения
				  std::cin >> university;
				  dima.setUniversity(university);
				  system("cls");

				  std::cout << "Your changed data."; // Ваши измененные данные
				  print();

				  break;
		}
		case 3:
		{
				  std::string group;
				  std::cout << "\nEnter new group number: "; // Введите новый номер группы
				  std::cin >> group;
				  dima.setGroup(group);
				  system("cls");

				  std::cout << "Your changed data."; // Ваши измененные данные
				  print();

				  break;
		}
		case 4:
		{
				  std::string phone;
				  std::cout << "\nEnter a new phone number: "; // Введите новый номер телефона
				  std::cin >> phone;
				  dima.setPhone(phone);
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

void init()
{
	std::cout << "Welcome. I the result of your first laboratory work.\n"; // Добро пожаловать. Я результат вашей первой лабораторной работы.
	std::cout << "Please enter your details.\n\n"; // Пожалуйста, введите свои данные.

	std::string name;
	std::cout << "Enter your name: "; // Введите ваше имя
	std::cin >> name;
	dima.setName(name);

	std::string surname;
	std::cout << "Enter your last name: "; // Введите свою фамилию
	std::cin >> surname;
	dima.setSurname(surname);

	std::string patronymic;
	std::cout << "Enter your patronymic: "; // Введите ваше отчество
	std::cin >> patronymic;
	dima.setPatronymic(patronymic);

	size_t year;
	std::cout << "Enter your year of birth: "; // Введите свой год рождения
	std::cin >> year;
	dima.setYear(year);

	std::string phone;
	std::cout << "Enter your contact number: "; // Введите свой контактный номер
	std::cin >> phone;
	dima.setPhone(phone);

	std::string city;
	std::cout << "Enter the name of the city where you registered: "; // Введите название города, в котором вы прописаны
	std::cin >> city;
	dima.setCity(city);

	std::string university;
	std::cout << "Enter the name of the institution where you study: "; // Введите название учебного завидения в котором вы учитесь
	std::cin >> university;
	dima.setUniversity(university);

	std::string group;
	std::cout << "Finally, enter your group number: "; // Наконец, введите номер своей группы
	std::cin >> group;
	dima.setGroup(group);

	system("cls");
}

void print()
{
	std::cout << "\nYour name, surname, patronymic: "; // Ваше имя, фамилия, отчество
	std::cout << dima.getName() + " " + dima.getSurname() + " " + dima.getPatronymic() << std::endl;

	std::cout << "Your year of birth: " << dima.getYear() << std::endl; // Ваш год рождения

	std::cout << "Your contact phone number: " << dima.getPhone() << std::endl; // Ваш контактный номер телефона

	std::cout << "The name of the city in which you are registered: "; // Название города в котором Вы прописаны
	std::cout << dima.getCity() << std::endl;

	std::cout << "Name of the University institution in which you study: "; // Название учебного заведения, в котором вы учитесь
	std::cout << dima.getUniversity() << std::endl;

	std::cout << "Number of your group in an University institution: "; // Номер вашей группы в учебном заведении
	std::cout << dima.getGroup() << "\n" << std::endl;
}
