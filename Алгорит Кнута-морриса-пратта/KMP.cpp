#include <iostream>
#include <string>
using namespace std;
void computeLPS(string pat, int* lps) {
	int8_t j = 0;
	lps[0] = 0;
	int8_t i = 1;
	while (i < pat.size()) {
		if (pat[i] == pat[j]) {//идем по циклу, если у нас символы равны, то мы инкрементируем и j и i
			j++;
			lps[i] = j;
			i++;
		}
		else {//если у нас символы не равны, и при этом j не равно нулю, то присваиваем j
			if (j != 0) {
				j = lps[j - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}
void KMPSearch(const string& pat, const string txt) {
	int* lps = new int[pat.size()];
	computeLPS(pat, lps);
	
	int i = 0;
	int j = 0;
	while (i < txt.size()) {
		if (pat[j] == pat[i]) {
			j++;
			i++;
		}
		if (j == pat.size()) {
			cout << "Found Pattern at index" << i - j << endl;
			j = lps[j - 1];//???
		}
		else if (i < txt.size() && pat[j] != txt[i])
		{
			if (j != 0) {
				j = lps[j - 1];//???
			}
			else {
				i = i + 1;
			}
		}
	}
}
int main() {
	string txt = "ABABDABACDABABCABAB";
	string pat = "ABABDA";
	KMPSearch(txt, pat);
	return 0;
}