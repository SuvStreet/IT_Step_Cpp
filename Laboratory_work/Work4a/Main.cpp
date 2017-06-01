#include "Text.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	std::string name;
	std::cout << "Введите название файла которого хотите прочесть: ";
	std::cin >> name;
	Text test(name);
	std::cout << "Самое длинное слово в файле: " << test.get_max_word() << std::endl;
	std::cout << "Количество букв в самом длинном слове: " << test.get_max_len() << std::endl;
	return 0;
}
