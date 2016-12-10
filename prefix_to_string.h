#ifndef PREFIX_TO_STRING_H
#define PREFIX_TO_STRING_H

#include <string>
#include <vector>
#include <algorithm>

std::string ConvertPrefixToString(const std::vector<int>& prefix_function);

std::string ConvertPrefixToString(const std::vector<int>& prefix_function) {
	// this code make min string by prefix function
	std::string string = "";
	// Поддерживаем массив вспомогательных элементов, который позволяет ответить на вопрос:
	// "Какую минимальную букву можно поставить на новую позицию(если вдруг префикс-функция новой позиции ноль)
	// с учетом предыдущей буквы и предшественников этой предыдущей буквы ?".
	// Это позволяет работать этой функции за O(n) ценой дополнительных O(n) памяти
	std::vector<char> suppottive_elements(prefix_function.size(), '\0');
	if (prefix_function.size() > 0) {
		string += 'a'; // первый элемент строки всегда 'a'
					   // Предшественников еще не было, поэтому вспомогательный элемент - следующий по алфавиту за 'a'
		suppottive_elements[0] = 'b'; // вспомогательный элемент равен 'b'
		for (int i = 1; i < prefix_function.size(); ++i) {
			int previous = i - 1; // индекс предыдущего элемента
			int predecessor = prefix_function[i] - 1; // индекс предшественника для данной буквы
													  // т.е. ранее идущий элемент, буква которого совпадает с этой буквой (если префикс-функция 0, то не определен)
			if (prefix_function[i] == 0) { // случай, когда префикс-функция равна 0
										   // Новый символ берем как вспомогательный элемент для предыдущего 
				string += suppottive_elements[previous]; // вспомогательный элемент для предыдущего
			}
			else { // если же префикс-функция не ноль, то данный элемент определяется однозначно
				string += string[predecessor]; // буква такая же, как предшественник данной буквы
			}
			// Теперь осталось позаботиться о поддержании массива вспомогательных элементов
			if (predecessor >= 0) { // если есть предшественник, то выбираем наибольшее из его вспомогательного элемента
									// и большего по алфавиту для следующего за вспомогательным элементом
				suppottive_elements[i] = std::max(suppottive_elements[predecessor], (char)(string[predecessor + 1] + 1));
			}
			else { // если предшественников не было, то берем в качестве вспомогательного элемента
				   // больший по алфавиту для нулевого символа(т.е. для 'a')
				suppottive_elements[i] = 'b';
			}
		}
	}
	return string;
}

#endif // PREFIX_TO_STRING_H