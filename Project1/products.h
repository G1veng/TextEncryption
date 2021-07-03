#pragma once

#include <memory>
#include "input_output.h"
#include "work_with_files.h"
#include <time.h>
#include <cstdlib>
#include <string>
#include "queue.h"
#include "output_text.h"

const int ENTER = 13;
const int RAND_COUNT_OF_STRINGS = 5;
const int RAND_COUNT_OF_WORDS = 5;
const int RAND_COUNT_OF_SYMBOLS = 7;
const int COUNT_OF_ENGLISH_CAPITAL_SYMBOLS = 26;
const int RAND_OF_MORE_THAN = 5;

enum class type_of_inputs {
	manualInput = 1,
	randomInput,
	fileInput,
	testOfProgram,
	endTheProgram
};

class Product {
public:
	virtual ~Product() = default;
	virtual std::unique_ptr<StackOfStrings> get_input() = 0;
};

class TextFromConsoleInput final : public Product {
public:
	virtual ~TextFromConsoleInput() = default;
	TextFromConsoleInput() = default;
	std::unique_ptr<StackOfStrings> get_input() override;
};

class TextFromFileInput final : public Product {
public:
	virtual ~TextFromFileInput() = default;
	TextFromFileInput() = default;
	std::unique_ptr<StackOfStrings> get_input() override;
};

class TextFromRandomInput final : public Product {
public:
	virtual ~TextFromRandomInput() = default;
	TextFromRandomInput() = default;
	std::unique_ptr<StackOfStrings> get_input() override;
};

class Container final {
public:
	Container() = default;
	~Container() = default;
	std::shared_ptr<Product> get_input_type(type_of_inputs input);
private:
	std::shared_ptr<Product> manual;
	std::shared_ptr<Product> random;
	std::shared_ptr<Product> file;
};