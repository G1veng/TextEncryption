#include "work_with_files.h"
#include "products.h"

std::string get_string_txt(void) {
	std::string path;
	std::cout << "Enter way to folder please:" << std::endl;
	std::cin >> path;
	while (getchar() != '\n');
	return path;
}

bool is_file_ok(std::string path, bool write){
	if (!write) {
		try {
			if (!fs::exists(path)) {
				std::cout << "Error" << std::endl;
				return false;
			}
			if (fs::is_block_file(path)) {
				std::cout << "Error" << std::endl;
				return false;
			}
			if (fs::is_empty(path)) {
				std::cout << "Error" << std::endl;
				return false;
			}
			if (!fs::is_regular_file(path)) {
			}
			if (fs::is_directory(path)) {
				std::cout << "Error" << std::endl;
				return false;
			}
		}
		catch (...) {
			std::cout << "Error" << std::endl;
			return false;
		}
	}
	else {
		try {
			if (fs::is_block_file(path)) {
				std::cout << "Error" << std::endl;
				return false;
			}
			if (fs::is_directory(path)) {
				std::cout << "Error" << std::endl;
				return false;
			}
			if (!fs::is_regular_file(path)) {
			}
		}
		catch (...) {
			std::cout << "Error" << std::endl;
			return false;
		}
	}
	return true;
}

std::unique_ptr<StackOfStrings> input_data_from_file(void) {
	std::string path = { 0 };
	std::string someString = { 0 };
	std::unique_ptr<StackOfStrings> fullText = std::make_unique<StackOfStrings>(StackOfStrings());
	std::vector<std::string> someText;
	std::vector<std::string> text;
	int  lenghtOfSubstring = 0;
	do {
		path = get_string_txt();
		std::ifstream file(path, std::ios_base::in);
		bool okay = is_file_ok(path, false);
		if (!okay)
			continue;
		if (!(file.is_open())) {
			std::cout << "Error" << std::endl;
			file.close();
		}
		if ((file.is_open()) || !file.fail()) {
			file.close();
			break;
		}
	} while (true);
	std::ifstream file(path, std::ios_base::in);
	while (getline(file, someString).good()) {
		someText.push_back(someString);
	}
	std::cout << "Enter lenght of substring: ";
	lenghtOfSubstring = input_digit();
	fullText->setText(lenghtOfSubstring, someText);
	file.close();
	return fullText;
}

void save_data_in_file(std::shared_ptr<StackOfStrings> fullText) {
	std::string path = { 0 };
	std::cout << "You want to save data in file?" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "0 - no" << std::endl;
	if(input_digit()) {
		do {
			path = get_string_txt();
			std::ofstream file(path, std::ios_base::in);
			bool okay = is_file_ok(path, true);
			if (!okay)
				continue;
			if ((file.is_open())) {
				std::cout << "You want to rewrite file?" << std::endl;
				std::cout << "1 - yes" << std::endl;
				std::cout << "0 - no" << std::endl;
				if (input_digit() == 0) {
					file.close();
					continue;
				}
			}
			file.close();
			break;
		} while (true);
		std::ofstream file(path, std::ios_base::out | std::ios_base::trunc);
		for (int i = 0; i < fullText->getStringCount(); i++) {
			file << fullText->showString(i) << '\n';
		}
		std::cout << "Result saved" << std::endl;
		file.close();
	}
}