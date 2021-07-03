#include "test.h"
#include "work_with_files.h"
#include "process.h"

void test(void) {
	std::string nameOfFolderWithString = "test";
	std::string nameOfFolderWithAnswers = "answerToTest";
	std::string buffer = { 0 }, someString = { 0 };
	std::vector<std::string> someText;
	int lenghtOfSubstring = 0;
	bool* errors = new bool[COUNT_OF_TESTS];
	for (int i = 0; i < COUNT_OF_TESTS; i++) {
		errors[i] = false;
	}
	for (int i = 0; i < COUNT_OF_TESTS; i++) {
		std::shared_ptr<StackOfStrings> fullText = std::make_shared<StackOfStrings>(StackOfStrings());
		std::ifstream strings(nameOfFolderWithString + std::to_string(i) + ".txt", std::ios_base::in);
		if(getline(strings, someString).good())
			lenghtOfSubstring = std::stoi(someString);
		std::ifstream answers(nameOfFolderWithAnswers + std::to_string(i) + ".txt", std::ios_base::in);
		while (getline(strings, someString).good()) {
			someText.push_back(someString);
		}
		fullText->setText(lenghtOfSubstring, someText);
		fullText->convertText();
		int k = 0;
		while (getline(answers, someString).good()) {
			if (fullText->showString(k) != someString)
				errors[i] = true;
			k++;
		}
		strings.close();
		answers.close();
		someText.clear();
	}
	for (int i = 0; i < COUNT_OF_TESTS; i++) {
		if (errors[i]) {
			std::cout << "Error in " << i << " test" << std::endl;
		}
	}
	std::cout << "Tests are over, if you see nothing thats mean what all test succeeded" << std::endl;
}