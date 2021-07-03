#include "products.h"

std::unique_ptr<StackOfStrings> TextFromConsoleInput::get_input(void) {
	outputText see;
	std::unique_ptr<StackOfStrings> fullText = std::make_unique<StackOfStrings>();
	std::vector<std::string> someText;
	char someKey = ' ';
	std::string text = "";
	std::string tempText = "";
	int enters = 0;
	char stopSymbol = ' ';
	int lenghtOfSubString = 0;
	std::cout << "Enter plese stop symbol" << std::endl;
	stopSymbol = get_char();
	std::cout << "Enter text, only english letters please" << std::endl;
	enters++;
	do {
		if (_kbhit()) {
			someKey = static_cast<char>(_getch());
			if ((someKey < CHAR_ZERO && someKey != ENTER && someKey != ' ' && someKey != ',' && someKey != '\b') ||
				(someKey > CHAR_NINE && someKey < 'A') || (someKey > 'Z' && someKey < 'a') || (someKey > 'z' && someKey != '{' && someKey != '}')) {
				if (someKey != stopSymbol) {
				}
			}
			else {
				if (someKey != stopSymbol) {
					if (someKey != '\b') {
						std::cout << someKey;
						text += someKey;
						enters = 0;
					}
					else {
						if (text.size() != 0) {
							tempText.clear();
							for (size_t i = 0; i < text.size() - 1; i++) {
								tempText += text[i];
							}
							std::cout << '\r';
							for (size_t i = 0; i < text.size(); i++) {
								std::cout << " ";
							}
							std::cout << '\r';
							text.clear();
							text = tempText;
							std::cout << text;
						}
					}
				}
			}
		}
		if (someKey == ENTER && enters == 0) {
			someText.push_back(text);
			text.clear();
			std::cout << std::endl;
			enters++;
		}
	} while (someKey != stopSymbol);
	if (text.length() > 0) {
		someText.push_back(text);
	}
	std::cout << std::endl;
	std::cout << "Enter lenght of substring: ";
	lenghtOfSubString = input_digit();
	fullText->setText(lenghtOfSubString, someText);
	see.showText(*fullText);
	return fullText;
}

std::unique_ptr<StackOfStrings> TextFromFileInput::get_input(void) {
	outputText see;
	std::cout << "Enter please folder with data" << std::endl;
	std::unique_ptr<StackOfStrings> fullText = input_data_from_file();
	see.showText(*fullText);
	return fullText;
}

std::unique_ptr<StackOfStrings> TextFromRandomInput::get_input(void) {
	outputText see;
	srand(static_cast <unsigned> (time(NULL)));
	std::unique_ptr<StackOfStrings> fullText = std::make_unique<StackOfStrings>();
	std::vector<std::string> someText;
	int countOfStrings = 0;
	int countOfWords = 0;
	int countOfSymbols = 0;
	char symbol = ' ';
	int lenghtOfSubstring = 0;
	std::string text = "";
	countOfStrings = 1 + rand() % RAND_COUNT_OF_STRINGS;
	for (int i = 0; i < countOfStrings; i++) {
		countOfWords = 1 + rand() % RAND_COUNT_OF_WORDS;
		for (int j = 0; j < countOfWords; j++) {
			countOfSymbols = 1 + rand() % RAND_COUNT_OF_SYMBOLS;
			for (int k = 0; k < countOfSymbols; k++) {
				if (k % 2 == 0) {
					symbol = 'A' + rand() % COUNT_OF_ENGLISH_CAPITAL_SYMBOLS;
					text += symbol;
				}
				else {
					symbol = 'a' + rand() % COUNT_OF_ENGLISH_CAPITAL_SYMBOLS;
					text += symbol;
				}
			}
			text += " ";
		}
		someText.push_back(text);
		text.clear();
	}
	std::cout << "Lenght of substring: ";
	lenghtOfSubstring = (1 + rand() % RAND_OF_MORE_THAN);
	std::cout << lenghtOfSubstring << std::endl;
	fullText->setText(lenghtOfSubstring, someText);
	see.showText(*fullText);
	return fullText;
}

std::shared_ptr<Product> Container::get_input_type(type_of_inputs input) {
	switch (input) {
	case type_of_inputs::manualInput: {
		if (Container::manual == nullptr)
			manual = std::make_shared<TextFromConsoleInput>(TextFromConsoleInput());
		return manual;
	}
	case type_of_inputs::randomInput: {
		if (Container::random == nullptr)
			random = std::make_shared<TextFromRandomInput>(TextFromRandomInput());
		return random;
	}
	case type_of_inputs::fileInput: {
		if (Container::file == nullptr)
			file = std::make_shared<TextFromFileInput>(TextFromFileInput());
		return file;
	}
	}
	return nullptr;
}