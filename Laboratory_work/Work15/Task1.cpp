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
	std::set<int> st;

	int temp;
	while (filein >> temp) {
		st.insert(temp);
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
		auto it = st.find(temp);
		if (it != st.end()) {
			fileout  << "YES	" << temp << std::endl;
		}
		else {
			fileout << "NO	" << temp << std::endl;
		}
	}
	filein.close();
	fileout.close();
	return 0;
}
