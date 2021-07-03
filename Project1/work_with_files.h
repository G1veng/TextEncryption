#pragma once

#include "input_output.h"
#include "queue.h"
#include <fstream>
#include <sstream>
#include <filesystem>

namespace fs = std::filesystem;

std::string get_string_txt(void);
std::unique_ptr<StackOfStrings> input_data_from_file();
void save_data_in_file(std::shared_ptr<StackOfStrings> fullText);