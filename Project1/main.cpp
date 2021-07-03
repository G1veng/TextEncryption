#include "process.h"
#include "products.h"
#include "test.h"

int main(void) {
	Container typesOfInputs;
	type_of_inputs userChoice;
	outputText see;
	std::cout << "Welcome. Laborator work number 4, option 6, by student of 403 group: Shishko Daniil Yerevich" << std::endl;
	std::cout << "Aim of program: Find in text all repeated strings longer than user choose, change these strings";
	std::cout << " on signature : {index of first symbol of first string, lenght of string}"<< std::endl;
	do {
		std::cout << "1 - to console input" << std::endl;
		std::cout << "2 - to random input" << std::endl;
		std::cout << "3 - to file input" << std::endl;
		std::cout << "4 - to test" << std::endl;
		std::cout << "5 - to end the program" << std::endl;
		userChoice = static_cast<type_of_inputs>(input_digit());
		if (userChoice < type_of_inputs::endTheProgram && userChoice >= type_of_inputs::manualInput && userChoice != type_of_inputs::testOfProgram) {
			std::shared_ptr<StackOfStrings> allText = typesOfInputs.get_input_type(userChoice)->get_input();
			if(userChoice != type_of_inputs::fileInput)
				save_data_in_file(allText);
			do {
				std::cout << "You want to convert text?" << std::endl;
				std::cout << "1 - yes" << std::endl;
				std::cout << "0 - no" << std::endl;
				if (input_digit()) {
					allText->convertText();
					see.showText(*allText);
					save_data_in_file(allText);
				}
				else
					break;
			} while (true);
		}
		if (userChoice == type_of_inputs::testOfProgram) {
			test();
		}
		if (userChoice > type_of_inputs::endTheProgram || userChoice < type_of_inputs::manualInput) {
			std::cout << "Wrong enter" << std::endl;
		}
	} while (userChoice != type_of_inputs::endTheProgram);
	return 0;
}