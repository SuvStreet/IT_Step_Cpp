#include<iostream>
#include<map>
#include<string>

int main()
{
	setlocale(LC_ALL, "Russian");
	std::map<size_t, size_t> mp{ { 1, 1 }, { 2, 4 }, { 3, 9 }, { 4, 16 }, { 5, 25 },
	{ 6, 36 }, { 7, 49 }, { 8, 64 }, { 9, 81 } };
	// 1) Создали контейнер типа std::map и вставили в него пары { 1, 1 }, { 2, 4 }, { 3, 9 },
	// { 4, 16 }, { 5, 25 }, { 6, 36 }, { 7, 49 }, { 8, 64 }, { 9, 81 }

	std::cout << "2) Содержимое словаря:\n";
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		std::cout << "[" << it->first << "] " << it->second << std::endl;
	}
	std::cout << std::endl;
	// 2) Вывели содержимое словаря в консоль в формате key => value

	std::cout << "3) Замена значения по ключу 7:\n";
	mp[7] = 14;
	for (auto& node : mp) {
		std::cout << "[" << node.first << "] " << node.second << std::endl;
	}
	std::cout << std::endl;
	// 3) Заменили значение по ключу 7 на 14

	std::cout << "4) Вставка в словарь новой пары { 10, 30 }:\n";
	mp.insert({ 10, 30 });
	for (auto& node : mp) {
		std::cout << "[" << node.first << "] " << node.second << std::endl;
	}
	std::cout << std::endl;
	// 4) Вставили в словарь пару {10, 30}

	std::cout << "5) Удаление из словоря пары с ключём 5:\n";
	mp.erase(5);
	for (auto& node : mp) {
		std::cout << "[" << node.first << "] " << node.second << std::endl;
	}
	std::cout << std::endl;
	// 5) Удалили из словаря пару с ключом 5

	std::cout << "6) Увеличили значение по каждому ключу на величину ключа:\n";
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		it->second += it->first;
	}
	for (auto& node : mp) {
		std::cout << "[" << node.first << "] " << node.second << std::endl;
	}
	std::cout << std::endl;
	// 6) Увеличили значение по каждому ключу на величину ключа

	std::cout << "7) Удалили из словаря пары со значениями 21 и 42:\n";
	size_t index = 0;
	for (auto it = mp.begin(); it != mp.end();) {
		if (it->second == 21 || it->second == 42) {
			mp.erase(it++);
		}
		else { ++it; }
	}
	for (auto& node : mp) {
		std::cout << "[" << node.first << "] " << node.second << std::endl;
	}
	std::cout << std::endl;
	// 7) Удалили из словаря пары со значениями 21 и 42

	std::cout << "8) Проверили, содержится ли в словаре пара с ключом 7, и если нет, то вставили в словарь пару{ 7, 5 }:\n";
	if (mp.count(7)) {
		mp[7] = 5;
	}
	else mp[7] = 5;
	for (auto& node : mp) {
		std::cout << "[" << node.first << "] " << node.second << std::endl;
	}
	std::cout << std::endl;
	// 8) Проверили, содержится ли в словаре пара с ключом 7, и если нет, то вставили в словарь пару{ 7, 5 }

	std::cout << "9) Произведение значений словаря по нечетным ключам:\n";
	size_t multi = 1;
	for (auto it = mp.begin(); it != mp.end(); ++it)
	if (it->first % 2 != 0) multi *= it->second;
	std::cout << multi << std::endl;
	std::cout << std::endl;
	// 9) Вычислили произведение всех значений словаря по нечетным ключам и вывели его в консоль

	std::cout << "10) Вывели содержимое словаря в консоль в формате key => value:\n";
	for (auto it = mp.begin(); it != mp.end(); ++it) {
		std::cout << "[" << it->first << "] " << it->second << std::endl;
	}
	// 10) Вывели содержимое словаря в консоль в формате key => value

	std::cout << std::endl;
	return 0;
}
