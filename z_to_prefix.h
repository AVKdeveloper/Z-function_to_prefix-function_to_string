#ifndef Z_TO_PREFIX_H
#define Z_TO_PREFIX_H

#include <string>
#include <vector>

std::vector<int> ConvertZToPrefix(std::vector<int> z_function);

std::vector<int> ConvertZToPrefix(std::vector<int> z_function) {
	std::vector<int> prefix_function;
	prefix_function.resize(z_function.size());
	std::fill(prefix_function.begin(), prefix_function.end(), 0); 
	// made and initialize prefix-function by '0'
	for (int i = 1; i < z_function.size(); ++i) {
		for (int j = z_function[i] - 1; j >= 0; --j) {
			if (prefix_function[i + j] > 0) { // if we have already changed this prefix-function
				break;
			} else {
				prefix_function[i + j] = j + 1;
			}
		}
	}
	return prefix_function;
}

#endif // Z_TO_PREFIX_H