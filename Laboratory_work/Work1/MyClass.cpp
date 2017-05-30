#include "MyClass.h"

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
void Student::setEducational(const std::string value)
{
	educational = value;
}
void Student::setGroup(const std::string value)
{
	group = value;
}
void Student::setYear(const int value)
{
	year = value;
}
void Student::setPhone(const int value)
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
std::string Student::getEducational() const
{
	return educational;
}
std::string Student::getGroup() const
{
	return group;
}
int Student::getYear() const
{
	return year;
}
int Student::getPhone() const
{
	return phone;
}

void Student::init()
{
	std::string name, surname, patronymic;
	std::string city, educational, group;
	int year, phone;

	std::cout << "Введите Ваше имя: ";
	setlocale(LC_ALL, ".866");
	std::cin >> name;
	setName(name);

	setlocale(LC_ALL, "Russian");
	std::cout << "Введите Вашу фамилию: ";
	setlocale(LC_ALL, ".866");
	std::cin >> surname;
	setSurname(surname);

	setlocale(LC_ALL, "Russian");
	std::cout << "Введите Ваше отчество: ";
	setlocale(LC_ALL, ".866");
	std::cin >> patronymic;
	setPatronymic(patronymic);

	setlocale(LC_ALL, "Russian");
	std::cout << "Введите Ваш год рождения: ";
	std::cin >> year;
	setYear(year);

	std::cout << "Укажите Ваш контактный номер: ";
	std::cin >> phone;
	setPhone(phone);

	std::cout << "Введите название города в котором прописаны: ";
	setlocale(LC_ALL, ".866");
	std::cin >> city;
	setCity(city);

	setlocale(LC_ALL, "Russian");
	std::cout << "Введите название учебного завидения в котором Вы учитесь: ";
	setlocale(LC_ALL, ".866");
	std::cin >> educational;
	setEducational(educational);

	setlocale(LC_ALL, "Russian");
	std::cout << "И последнее, введите номер вашей группы: ";
	setlocale(LC_ALL, ".866");
	std::cin >> group;
	setGroup(group);
}

void Student::print()
{
	setlocale(LC_ALL, "Russian");
	std::cout << "\nВаше имя, фамилия, отчество: ";
	setlocale(LC_ALL, ".866");
	std::cout << getName() + " " + getSurname() + " " + getPatronymic() << std::endl;

	setlocale(LC_ALL, "Russian");
	std::cout << "Ваш год рождения: " << getYear() << std::endl;

	std::cout << "Ваш контактный телефон: " << getPhone() << std::endl;

	std::cout << "Название города в котором Вы прописаны: ";
	setlocale(LC_ALL, ".866");
	std::cout << getCity() << std::endl;

	setlocale(LC_ALL, "Russian");
	std::cout << "Название учебного заведения в котором Вы учитесь: ";
	setlocale(LC_ALL, ".866");
	std::cout << getEducational() << std::endl;

	setlocale(LC_ALL, "Russian");
	std::cout << "Номер Вашей группы в учебном заведении: ";
	setlocale(LC_ALL, ".866");
	std::cout << getGroup() << std::endl << std::endl;
}

void Student::choice()
{
	bool done = true;
	while (done)
	{
		setlocale(LC_ALL, "Russian");
		std::cout << "Вы хотите что нибудь изменить?\n1 - Место прописки;\n2 - Учебное заведение;\n\
3 - Номер группы;\n4 - Телефон;\n0 - Меня всё устраивает.\nВаш выбор: ";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{
			std::cout << "\nВведите новое место прописки: ";
			setlocale(LC_ALL, ".866");
			std::cin >> city;
			setCity(city);

			setlocale(LC_ALL, "Russian");
			std::cout << "\nВаши изменённые данные.";
			print();

			break;
		}
		case 2:
		{
			std::cout << "\nВведите новое название учебного заведения: ";
			setlocale(LC_ALL, ".866");
			std::cin >> educational;
			setEducational(educational);

			setlocale(LC_ALL, "Russian");
			std::cout << "\nВаши изменённые данные.";
			print();

			break;
		}
		case 3:
		{
			std::cout << "\nВведите новый номер группы: ";
			setlocale(LC_ALL, ".866");
			std::cin >> group;
			setGroup(group);

			setlocale(LC_ALL, "Russian");
			std::cout << "\nВаши изменённые данные.";
			print();

			break;
		}
		case 4:
		{
			std::cout << "\nВведите новый номер телефона: ";
			setlocale(LC_ALL, ".866");
			std::cin >> phone;
			setPhone(phone);

			setlocale(LC_ALL, "Russian");
			std::cout << "\nВаши изменённые данные.";
			print();

			break;
		}
		case 0:
		{
			std::cout << "\nВвывод на печать, нажмите Enter, что бы выйти из программы.\n\n";
			
			std::cin.get();
			done = false;
			break;
		}
		default:
			std::cout << "\nНет такого пункта в меню!\n" << std::endl;
		}
	}
}
