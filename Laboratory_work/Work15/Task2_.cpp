#include<iostream>
#include<set>
#include<fstream>

int main()
{
	std::ifstream filein;
	filein.open("input.txt");
	if (!filein.is_open()) {
		std::cout << "File not found (input)" << std::endl;
		return 1;
	}
	std::multiset<int> mst;

	int temp;
	while (filein >> temp) {
		mst.insert(temp);
	}

	filein.close();
	filein.clear();

	filein.open("test.txt");
	if (!filein.is_open()) {
		std::cout << "File not found (test)" << std::endl;
		return 2;
	}

	std::ofstream fileout;
	fileout.open("input_1.txt");
	if (!fileout.is_open()) {
		std::cout << "File not created" << std::endl;
		return 3;
	}

	while (filein >> temp) {
			fileout << mst.count(temp) << "	" << temp  << std::endl;
	}

	filein.close();
	fileout.close();
	return 0;
}
