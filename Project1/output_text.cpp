#include "output_text.h"

void outputText::showText(StackOfStrings fullText) {
	for (int i = 0; i < fullText.getStringCount(); i++) {
		std::cout << fullText.showString(i) << std::endl;
	}
}