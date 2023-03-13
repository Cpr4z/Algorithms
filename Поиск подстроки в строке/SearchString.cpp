#include <iostream>
#include <cstring>
void search(const std::string& pat, const std::string& txt) {//алгоритм поиска подстроки в строке
	int M = pat.size();
	int N = txt.size();
	
	for (int i = 0; i <= N - M; i++) {//N-M потому что нет смысла смотреть часть строки которая меньше подстроки
		for ( int j=0 ; j < M; j++) {
			if (txt[i + j] != pat[j])//идем по строке и если элемент строки не равен элементу подстоки, то переходим к следующему элементу строки,
				//если равен, то увеличиваем j на единицу и проверяем не равно ли j размеру подстроки.
				break;
		}
		if ( j == M)
			std::cout << "Pattern found at index" << j << '\n';
	}
}
int main() {
	std::string second = "red";//подстрока
	std::string first = "reddeadredemtion";//строка
	search(first, second);
	 return 0;
}