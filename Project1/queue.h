#pragma once

#include <string>
#include <vector>
#include <fstream>
#include <sstream>

enum class Exceptions {
	OutOfRangeException,
};

class StackOfStrings {
private:
	int countOfStrings;
	std::vector<std::string> arrayOfCorrectedStrings;
	std::vector<std::string> arrayOfStrings;
	int moreThanThat;
	int countOfCombinations;
	int countOfCorrectedSrings;
	bool sorted;
	struct allCombinatios {
		std::string combinations = "";
		int indexOfPrimalLetter = 0;
		int CountOfPimalCombination = 0;
		int lenghtOfPimalCombination = 0;
	};
	allCombinatios* arrayOfCombinations;
	int getCountOfStrings();
	void pushString(std::string stringToAdd);
	std::string popString();
	void setMoreThan(int more);
	std::string popWord();
	void saveCombination(std::string combination, int indexOfPrimalLetter);
	int findExsistingCombination(std::string combination);
	int getLenghtOfCombination(std::string combination);
	int getPositionOfCombintion(int index);
	std::string getCorrectString(std::string combination);
	void pushArrayOfCorrectedStrings(std::string partOfAnswer);
	int getLenghtOfFirstString();
	std::string popCorrectedString();
	int getCountOfCorrectedString();
	std::string showCorrectedString(int index);
	std::string showOriginString(int row);
	std::string getCombination(int index, int size);
	void deleteCombinations();
	void changeSorted(bool change);
	bool getSorted();
	int getCountOfCombinations();
	void backProcess();
	void process();
	void outputSortedStrings();
	void outputOriginStrings();
  int getMoreThan();
public:
	StackOfStrings(std::string someString) = delete;
	StackOfStrings();
	~StackOfStrings();
	void convertText();
	void setText(int lenghtOfSubstring, std::vector<std::string> someText);
	std::string showString(int row);
	int getStringCount(void);
};