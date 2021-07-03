//#include "process.h"
//
//void process(std::shared_ptr<StackOfStrings> text){
//	std::string someWord = "";
//	std::string combination = "";
//	std::string newWord = "";
//	std::string correctSentence = "";
//	bool anyChanges = false, entered = false;
//	int correctIndex = 0;
//	unsigned lenghtOfString = 0;
//	int positionInText = 0;
//	int positionInString = 0;
//	do {
//		int countOfStrings = text->getCountOfStrings();
//		for (int i = 0; text->getCountOfStrings() > 0; i++) {
//			if (entered) {
//				positionInText += someWord.length() + 1;
//				positionInString = 0;
//			}
//			entered = false;
//			someWord = text->popWord();
//			newWord.clear();
//			combination.clear();
//			for (unsigned k = 0; k <= someWord.length(); k++) {
//				positionInString++;
//				if (anyChanges) {
//					correctSentence += newWord;
//					k += lenghtOfString - 1;
//					if (k == someWord.length()) {
//						if (text->getCountOfStrings() == countOfStrings)
//							correctSentence += " ";
//					}
//				}
//				if(!anyChanges && entered) {
//					correctSentence += someWord[k - 1];
//					if(k == someWord.length())
//						if (text->getCountOfStrings() == countOfStrings)
//							correctSentence += " ";
//				}
//				entered = true;
//				anyChanges = false;
//				newWord.clear();
//				combination.clear();
//				for (unsigned j = k; j < someWord.length(); j++) {
//					combination += someWord[j];
//					if (text->getMoreThan() != 0 && combination.length() > text->getMoreThan()) {
//						correctIndex = text->findExsistingCombination(combination);
//						if (correctIndex != -1) {
//							anyChanges = true;
//							newWord = text->getCorrectString(combination);
//							lenghtOfString = text->getLenghtOfCombination(combination);
//						}
//						if (correctIndex == -1) {
//							text->saveCombination(combination, positionInString + positionInText);
//						}
//					}
//				}
//			}
//			if (text->getCountOfStrings() != countOfStrings) {
//				text->pushArrayOfCorrectedStrings(correctSentence);
//				correctSentence.clear();
//				countOfStrings = text->getCountOfStrings();
//			}
//		}
//	}while (text->getCountOfStrings() > 0);
//	text->changeSorted(true);
//}
//
//void backProcess(std::shared_ptr<StackOfStrings> text) {
//	std::string correctSentence = "";
//	std::string reversedSentence = "";
//	int index = 0;
//	std::string stringIndex = "";
//	int sizeOfBorder = 0;
//	int size = 0;
//	std::string stringSize = "";
//	if (text->getCountOfCombinations() != 0) {
//		do {
//			reversedSentence.clear();
//			correctSentence.clear();
//			correctSentence = text->popCorrectedString();
//			for (unsigned i = 0; i < correctSentence.length(); i++) {
//				if (correctSentence[i] != '{') {
//					reversedSentence += correctSentence[i];
//				}
//				else {
//					sizeOfBorder = 2;
//					int j = i + 1;
//					stringIndex.clear();
//					stringSize.clear();
//					do {
//						stringIndex += correctSentence[j];
//						j++;
//						sizeOfBorder++;
//					} while (correctSentence[j] != ',');
//					index = std::stoi(stringIndex);
//					j += 2;
//					sizeOfBorder += 2;
//					do {
//						stringSize += correctSentence[j];
//						sizeOfBorder++;
//						j++;
//					} while (correctSentence[j] != '}');
//					size = std::stoi(stringSize);
//					reversedSentence += text->getCombination(index, size);
//					i += sizeOfBorder - 1;
//				}
//			}
//			text->pushString(reversedSentence);
//		} while (text->getCountOfCorrectedString() > 0);
//		text->deleteCombinations();
//		text->changeSorted(false);
//	}
//	else {
//		do {
//			reversedSentence.clear();
//			correctSentence.clear();
//			correctSentence = text->popCorrectedString();
//			for (unsigned i = 0; i < correctSentence.length(); i++) {
//				if (correctSentence[i] != '{') {
//					reversedSentence += correctSentence[i];
//				}
//				else {
//					sizeOfBorder = 2;
//					int j = i + 1;
//					stringIndex.clear();
//					stringSize.clear();
//					do {
//						stringIndex += correctSentence[j];
//						j++;
//						sizeOfBorder++;
//					} while (correctSentence[j] != ',');
//					index = std::stoi(stringIndex);
//					j += 2;
//					sizeOfBorder += 2;
//					do {
//						stringSize += correctSentence[j];
//						sizeOfBorder++;
//						j++;
//					} while (correctSentence[j] != '}');
//					size = std::stoi(stringSize);
//					if (index > correctSentence.size()) {
//						for(int i = 0; i < )
//					}
//					for(int k = index; k < index + size; k++)
//						reversedSentence += correctSentence[k];
//					i += sizeOfBorder - 1;
//				}
//			}
//			text->pushString(reversedSentence);
//		} while (text->getCountOfCorrectedString() > 0);
//		text->changeSorted(false);
//	}
//}