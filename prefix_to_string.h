#ifndef PREFIX_TO_STRING_H
#define PREFIX_TO_STRING_H

#include <string>
#include <vector>

std::string ConvertPrefixToString(const std::vector<int>& prefix_function);

std::string ConvertPrefixToString(const std::vector<int>& prefix_function) {
	// this code make min string by prefix function
	std::string string = "";
	if (prefix_function.size() > 0) {
		string += 'a';
		for (int i = 1; i < prefix_function.size(); ++i) {
			if (prefix_function[i] == 0) {
				// new symbol is the next in alphabet to string[prefix_function[i-1]]
				string += string[prefix_function[i - 1]] + 1;
			}
			else {
				string += string[prefix_function[i] - 1];
			}
		}
	}
	return string;
}

#endif // PREFIX_TO_STRING_H