#include "input_output.h"

int input_digit(void) {
	int digit = 0;
	do {
		while ((std::cin >> digit) && (std::cin.good())) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			return digit;
		}
		std::cout << "Error, please enter number" << std::endl;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (true);
}

char get_char(void) {
	char symbol = ' ';
	std::cin >> symbol;
	return symbol;
}