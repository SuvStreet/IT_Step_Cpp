#include"Area.h"

int main()
{
	Area a;
	a.menu();
	std::cout << "Вы посчитали площадь " << Area::getCounter() << " раз.\n" << std::endl;
	return 0;
}
