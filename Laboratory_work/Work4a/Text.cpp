#include "Text.h"

void Text::recovery(int word_number, std::string name)
{
	std::ifstream filein(name);
	if (!filein.is_open()) {
		std::cout << "File not found!" << std::endl;
		return;	
	}

	std::string tmp;
	while (filein >> tmp) { // обработка строки
		++size;
	}
	filein.clear();
	filein.seekg(0);

	if (word_number < size || word_number > -1) size = word_number;

	str = new std::string[size];
	for (size_t i = 0; i < size; ++i) {
		filein >> tmp;
		str[i] = tmp;
		if (str[i].length() > MAX_len) {
			MAX_len = str[i].length();
			MAX_word = str[i];
		}
	}
	filein.close();
}

Text::Text()
{
	recovery(-1, "test_text.txt");
}

Text::Text(int word)
{
	recovery(word, "test_text.txt");
}

Text::Text(std::string name)
{
	recovery(-1, name);
}

Text::Text(std::string name, int word)
{
	recovery(word, name);
}

Text::Text(const Text& myObj): size(myObj.size)
{
	str = new std::string [size];
	for (size_t i = 0; i < size; ++i) {
		str[i] = myObj.str[i];
	}
}

Text::Text(Text&& myObj): str(myObj.str), size(myObj.size)
{
	str = nullptr;
	size = 0;
}

size_t Text::get_max_len() const
{
	return MAX_len;
}

std::string Text::get_max_word() const
{
	return MAX_word;
}
