#include "queue.h"
#include <sstream>
#include <iostream>

StackOfStrings::StackOfStrings() {
	countOfStrings = 0;
	arrayOfCombinations = nullptr;
	countOfCombinations = 0;
	countOfCorrectedSrings = 0;
	moreThanThat = 0;
	sorted = false;
}

StackOfStrings::~StackOfStrings() {
	deleteCombinations();
	if (arrayOfCorrectedStrings.size() != 0) {
		while (arrayOfCorrectedStrings.size() != 0)
			arrayOfCorrectedStrings.pop_back();
	}
	if (arrayOfStrings.size() != 0) {
		while (arrayOfStrings.size() != 0)
			arrayOfStrings.pop_back();
	}
}

std::string StackOfStrings::popString() {
	if(arrayOfStrings.size() == 0)
		throw Exceptions::OutOfRangeException;
	std::string toReturn = "";
	std::vector<std::string> tempStrings;
	toReturn = arrayOfStrings[0];
	for (size_t i = arrayOfStrings.size() - 1; i > 1; i--) {
		tempStrings.push_back(arrayOfStrings[i]);
	}
	while (arrayOfStrings.size() != 0) {
		arrayOfStrings.pop_back();
	}
	for (size_t i = 0; i < tempStrings.size(); i++) {
		arrayOfStrings.push_back(tempStrings[i]);
	}
	while (tempStrings.size() != 0) {
		tempStrings.pop_back();
	}
	countOfStrings--;
	return toReturn;
}

void StackOfStrings::pushString(std::string someString) {
	arrayOfStrings.push_back(someString);
	countOfStrings++;
}

int StackOfStrings::getCountOfStrings() {
	return countOfStrings;
}

int StackOfStrings::getMoreThan() {
	return moreThanThat;
}

void StackOfStrings::setMoreThan(int more) {
	moreThanThat = more;
}

std::string StackOfStrings::popWord() {
	if (arrayOfStrings.size() == 0)
		throw Exceptions::OutOfRangeException;
	unsigned count = 0;
	std::string someWord = "";
	if (countOfStrings == 0) {
		throw Exceptions::OutOfRangeException;
	}
	do {
		if (arrayOfStrings[0][count] != ' ' && (arrayOfStrings[0][count] != '\r' && count != arrayOfStrings[0].length())) {
			someWord += arrayOfStrings[0][count];
			count++;
		}
		if (arrayOfStrings[0][count] == ' ') {
			std::string tempString = "";
			for (unsigned i = count + 1; i < arrayOfStrings[0].length(); i++) {
				tempString += arrayOfStrings[0][i];
			}
			arrayOfStrings[0] = tempString;
			break;
		}
		if (arrayOfStrings[0][count] == '\r' || count == arrayOfStrings[0].length())
		{
			std::vector<std::string> tempStrings;
			for (unsigned i = 1; i < (static_cast<unsigned>(countOfStrings)); i++) {
				tempStrings.push_back(arrayOfStrings[i]);
			}
			while (arrayOfStrings.size()!= 0) {
				arrayOfStrings.pop_back();
			}
			countOfStrings--;
			for (unsigned i = 0; i < tempStrings.size(); i++) {
				arrayOfStrings.push_back(tempStrings[i]);
			}
			while (tempStrings.size() != 0) {
				tempStrings.pop_back();
			}
			break;
		}
	} while (true);
	return someWord;
}

void StackOfStrings::saveCombination(std::string combination, int indexOfPrimalLetter) {
	if (arrayOfCombinations == nullptr) {
		arrayOfCombinations = new allCombinatios[1];
		arrayOfCombinations[0].CountOfPimalCombination = 0;
		arrayOfCombinations[0].combinations = combination;
		arrayOfCombinations[0].lenghtOfPimalCombination = static_cast<int>(combination.length());
		arrayOfCombinations[0].indexOfPrimalLetter = indexOfPrimalLetter;
		arrayOfCombinations[0].CountOfPimalCombination++;
		countOfCombinations++;
	}
	else {
		allCombinatios* tempCombinations = new allCombinatios[countOfCombinations];
		for (int i = 0; i < countOfCombinations; i++) {
			tempCombinations[i] = arrayOfCombinations[i];
		}
		delete[] arrayOfCombinations;
		arrayOfCombinations = new allCombinatios[countOfCombinations + 1];
		for (int i = 0; i < countOfCombinations; i++) {
			arrayOfCombinations[i] = tempCombinations[i];
		}
		delete[] tempCombinations;
		countOfCombinations++;
		arrayOfCombinations[countOfCombinations - 1].combinations = combination;
		arrayOfCombinations[countOfCombinations - 1].CountOfPimalCombination++;
		arrayOfCombinations[countOfCombinations - 1].indexOfPrimalLetter = indexOfPrimalLetter;
		arrayOfCombinations[countOfCombinations - 1].lenghtOfPimalCombination = static_cast<int>(combination.length());
	}
}

int StackOfStrings::findExsistingCombination(std::string combination) {
	for (int i = 0; i < countOfCombinations; i++) {
		if (arrayOfCombinations[i].combinations == combination)
			return i;
	}
	return -1;
}

std::string StackOfStrings::getCombination(int index, int size) {
	if (countOfCombinations == 0)
		throw Exceptions::OutOfRangeException;
	int i = 0;
	do {
		if (arrayOfCombinations[i].indexOfPrimalLetter == index
			&& arrayOfCombinations[i].lenghtOfPimalCombination == size)
			break;
		i++;
	} while (i < countOfCombinations);
	return arrayOfCombinations[i].combinations;
}

int StackOfStrings::getLenghtOfCombination(std::string combination) {
	for (int i = 0; i < countOfCombinations; i++) {
		if (arrayOfCombinations[i].combinations == combination)
			return arrayOfCombinations[i].combinations.length();
	}
	return -1;
}

int StackOfStrings::getPositionOfCombintion(int row) {
	return arrayOfCombinations[row].indexOfPrimalLetter;
}

std::string StackOfStrings::getCorrectString(std::string combination){
	bool finded = false;
	int index = 0;
	for (index = 0; !finded; index++) {
		if (arrayOfCombinations[index].combinations == combination) {
			finded = true;
		}
	}
	index--;
	std::string toReturn = "";
	std::ostringstream temp;
	std::ostringstream secondTemp;
	toReturn += "{";
	temp << arrayOfCombinations[index].indexOfPrimalLetter;
	toReturn += temp.str();
	toReturn += ", ";
	secondTemp << arrayOfCombinations[index].lenghtOfPimalCombination;
	toReturn += secondTemp.str();
	toReturn += "}";
	return toReturn;
}

void StackOfStrings::pushArrayOfCorrectedStrings(std::string partOfAnswer) {
	arrayOfCorrectedStrings.push_back(partOfAnswer);
	countOfCorrectedSrings++;
}

int StackOfStrings::getLenghtOfFirstString() {
	return arrayOfStrings[0].length() - 1;
}

std::string StackOfStrings::popCorrectedString() {
	if (arrayOfCorrectedStrings.size() == 0)
		throw Exceptions::OutOfRangeException;
	std::string toReturn = "";
	std::vector<std::string> tempStrings;
	toReturn = arrayOfCorrectedStrings[0];
	for (int i = 1; i < countOfCorrectedSrings; i++) {
		tempStrings.push_back(arrayOfCorrectedStrings[i]);
	}
	while (arrayOfCorrectedStrings.size() != 0) {
		arrayOfCorrectedStrings.pop_back();
	}
	for (size_t i = 0; i < tempStrings.size(); i++) {
		arrayOfCorrectedStrings.push_back(tempStrings[i]);
	}
	while (tempStrings.size() != 0) {
		tempStrings.pop_back();
	}
	countOfCorrectedSrings--;
	return toReturn;
}

int StackOfStrings::getCountOfCorrectedString() {
	return countOfCorrectedSrings;
}

std::string StackOfStrings::showCorrectedString(int row) {
	if (row >= countOfCorrectedSrings || row < 0)
		throw Exceptions::OutOfRangeException;
	return arrayOfCorrectedStrings[row];
}

std::string StackOfStrings::showOriginString(int row) {
	if (row >= countOfStrings || row < 0)
		throw Exceptions::OutOfRangeException;
	return arrayOfStrings[row];
}

void StackOfStrings::deleteCombinations(void) {
	if (arrayOfCombinations != nullptr) {
		delete[] arrayOfCombinations;
		countOfCombinations = 0;
		arrayOfCombinations = nullptr;
	}
}

void StackOfStrings::changeSorted(bool change) {
	sorted = change;
}

bool StackOfStrings::getSorted(void) {
	return sorted;
}

void StackOfStrings::outputOriginStrings(void) {
	std::cout << std::endl;
	for (int i = 0; i < countOfStrings; i++) {
		std::cout << arrayOfStrings[i] << std::endl;
	}
}

void StackOfStrings::outputSortedStrings(void) {
	std::cout << std::endl;
	for (int i = 0; i < countOfCorrectedSrings; i++) {
		std::cout << arrayOfCorrectedStrings[i] << std::endl;
	}
}

int StackOfStrings::getCountOfCombinations(void) {
	return countOfCombinations;
}

void StackOfStrings::process(void) {
	std::string someWord = "";
	std::string combination = "";
	std::string newWord = "";
	std::string correctSentence = "";
	bool anyChanges = false, entered = false;
	int correctIndex = 0;
	unsigned lenghtOfString = 0;
	int positionInText = 0;
	int positionInString = 0;
	do {
		int countOfStringsTemp = getCountOfStrings();
		for (int i = 0; getCountOfStrings() > 0; i++) {
			if (entered) {
				positionInText += someWord.length() + 1;
				positionInString = 0;
			}
			entered = false;
			someWord = popWord();
			if(someWord.size() == 0)
				correctSentence += " ";
			newWord.clear();
			combination.clear();
			for (unsigned k = 0; k <= someWord.length(); k++) {
				positionInString++;
				if (anyChanges) {
					correctSentence += newWord;
					k += lenghtOfString - 1;
					if (k == someWord.length()) {
						if (getCountOfStrings() == countOfStringsTemp)
							correctSentence += " ";
					}
				}
				if (!anyChanges && entered) {
					correctSentence += someWord[k - 1];
					if (k == someWord.length())
						if (getCountOfStrings() == countOfStringsTemp)
							correctSentence += " ";
				}
				entered = true;
				anyChanges = false;
				newWord.clear();
				combination.clear();
				for (unsigned j = k; j < someWord.length(); j++) {
					combination += someWord[j];
					if (getMoreThan() != 0 && combination.length() > (static_cast<unsigned>(getMoreThan()))) {
						correctIndex = findExsistingCombination(combination);
						if (correctIndex != -1) {
							anyChanges = true;
							newWord = getCorrectString(combination);
							lenghtOfString = getLenghtOfCombination(combination);
						}
						if (correctIndex == -1) {
							saveCombination(combination, positionInString + positionInText);
						}
					}
				}
			}
			if (getCountOfStrings() != countOfStringsTemp) {
				pushArrayOfCorrectedStrings(correctSentence);
				correctSentence.clear();
				countOfStringsTemp = getCountOfStrings();
			}
		}
	} while (getCountOfStrings() > 0);
	changeSorted(true);
	deleteCombinations();
}

void StackOfStrings::convertText() {
	if (getSorted()) {
		backProcess();
	}
	else {
		process();
	}
}

void StackOfStrings::backProcess(void) {
	std::string correctSentence = "";
	std::string reversedSentence = "";
	unsigned index = 0;
	std::string stringIndex = "";
	int sizeOfBorder = 0;
	int size = 0;
	std::string stringSize = "";
	do {
		reversedSentence.clear();
		correctSentence.clear();
		correctSentence = popCorrectedString();
		for (unsigned i = 0; i < correctSentence.length(); i++) {
			if (correctSentence[i] != '{') {
				reversedSentence += correctSentence[i];
			}
			else {
				sizeOfBorder = 2;
				int j = i + 1;
				stringIndex.clear();
				stringSize.clear();
				do {
					stringIndex += correctSentence[j];
					j++;
					sizeOfBorder++;
				} while (correctSentence[j] != ',');
				index = std::stoi(stringIndex);
				j += 2;
				sizeOfBorder += 2;
				do {
					stringSize += correctSentence[j];
					sizeOfBorder++;
					j++;
				} while (correctSentence[j] != '}');
				size = std::stoi(stringSize);
				int stringOfIndex = 0;
				if (getCountOfStrings() != 0) {
					while (getCountOfStrings() != stringOfIndex && index > showOriginString(stringOfIndex).size()) {
						index -= showOriginString(stringOfIndex).size();
						stringOfIndex++;
					}
				}
				for (unsigned k = index; k < index + size; k++)
					if(getCountOfStrings() != 0)
						if(getCountOfStrings() != stringOfIndex)
							reversedSentence += showOriginString(stringOfIndex)[k - 1];
						else
							reversedSentence += reversedSentence[k - 2];
					else {
						reversedSentence += reversedSentence[k-1];
					}
				i += sizeOfBorder - 1;
			}
		}
		pushString(reversedSentence);
	} while (getCountOfCorrectedString() > 0);
	changeSorted(false);
}

void StackOfStrings::setText(int lenghtOfSubstring, std::vector<std::string> someText) {
	changeSorted(false);
	setMoreThan(lenghtOfSubstring);
	for (unsigned i = 0; i < someText.size(); i++) {
		for (unsigned j = 0; j < someText[i].size(); j++) {
			if (someText[i][j] == '{')
				changeSorted(true);
		}
	}
	if (getSorted()) {
		for (unsigned i = 0; i < someText.size(); i++) {
			pushArrayOfCorrectedStrings(someText[i]);
		}
	}
	else {
		for (unsigned i = 0; i < someText.size(); i++) {
			pushString(someText[i]);
		}
	}
}

std::string StackOfStrings::showString(int row) {
	if (getSorted()) {
		return showCorrectedString(row);
	}
	else {
		return showOriginString(row);
	}
}

int StackOfStrings::getStringCount(void) {
	if (getSorted()) {
		return getCountOfCorrectedString();
	}
	else {
		return getCountOfStrings();
	}
}