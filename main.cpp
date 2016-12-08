// This program make min string using z-function of this string
// We use z-function to prefix-function transformation and then prefix-function to string transformation
// Time O(string.size()).  Memory O(string.size())

#include <fstream>
#include <vector>
#include <string>
#include "prefix_to_string.h"
#include "z_to_prefix.h"

int main() {
	std::fstream file;
	file.open("input.txt", std::fstream::in);
	std::vector<int> z_function;
	int  new_z_function_value;
	while (file >> new_z_function_value) {
		z_function.push_back(new_z_function_value);
	}
	file.close();
	std::vector<int> prefix_function(ConvertZToPrefix(z_function));
	std::string string(ConvertPrefixToString(prefix_function));
	file.open("output.txt", std::fstream::out);
	file << string;
	file.close();
	return 0;
}
