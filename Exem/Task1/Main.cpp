#include "CrosswordSolver.h"
#include <iostream>

int main() {

	setlocale(LC_ALL, "Russian");
	
	CrosswordSolver cros("");

	cros.getAllWithLen(2, "WordSize.txt");
	cros.getAllWithInit('ё', "Word.txt");
	cros.getAnagrams("ранима", "Anagramms.txt");
	
	cros.addBase("армани");
	cros.addBase("ранами");

	CrosswordSolver cros1("Lopatin_dictionary.txt");
	cros1.getAnagrams("ранима", "New_Anagramms.txt");

	return 0;
}
