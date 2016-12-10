#ifndef PREFIX_TO_STRING_H
#define PREFIX_TO_STRING_H

#include <string>
#include <vector>
#include <algorithm>

std::string ConvertPrefixToString(const std::vector<int>& prefix_function);

std::string ConvertPrefixToString(const std::vector<int>& prefix_function) {
	// this code make min string by prefix function
	std::string string = "";
	// ������������ ������ ��������������� ���������, ������� ��������� �������� �� ������:
	// "����� ����������� ����� ����� ��������� �� ����� �������(���� ����� �������-������� ����� ������� ����)
	// � ������ ���������� ����� � ���������������� ���� ���������� ����� ?".
	// ��� ��������� �������� ���� ������� �� O(n) ����� �������������� O(n) ������
	std::vector<char> suppottive_elements(prefix_function.size(), '\0');
	if (prefix_function.size() > 0) {
		string += 'a'; // ������ ������� ������ ������ 'a'
					   // ���������������� ��� �� ����, ������� ��������������� ������� - ��������� �� �������� �� 'a'
		suppottive_elements[0] = 'b'; // ��������������� ������� ����� 'b'
		for (int i = 1; i < prefix_function.size(); ++i) {
			int previous = i - 1; // ������ ����������� ��������
			int predecessor = prefix_function[i] - 1; // ������ ��������������� ��� ������ �����
													  // �.�. ����� ������ �������, ����� �������� ��������� � ���� ������ (���� �������-������� 0, �� �� ���������)
			if (prefix_function[i] == 0) { // ������, ����� �������-������� ����� 0
										   // ����� ������ ����� ��� ��������������� ������� ��� ����������� 
				string += suppottive_elements[previous]; // ��������������� ������� ��� �����������
			}
			else { // ���� �� �������-������� �� ����, �� ������ ������� ������������ ����������
				string += string[predecessor]; // ����� ����� ��, ��� �������������� ������ �����
			}
			// ������ �������� ������������ � ����������� ������� ��������������� ���������
			if (predecessor >= 0) { // ���� ���� ��������������, �� �������� ���������� �� ��� ���������������� ��������
									// � �������� �� �������� ��� ���������� �� ��������������� ���������
				suppottive_elements[i] = std::max(suppottive_elements[predecessor], (char)(string[predecessor + 1] + 1));
			}
			else { // ���� ���������������� �� ����, �� ����� � �������� ���������������� ��������
				   // ������� �� �������� ��� �������� �������(�.�. ��� 'a')
				suppottive_elements[i] = 'b';
			}
		}
	}
	return string;
}

#endif // PREFIX_TO_STRING_H