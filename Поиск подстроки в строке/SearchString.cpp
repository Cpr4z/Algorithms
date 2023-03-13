#include <iostream>
#include <cstring>
void search(const std::string& pat, const std::string& txt) {//�������� ������ ��������� � ������
	int M = pat.size();
	int N = txt.size();
	
	for (int i = 0; i <= N - M; i++) {//N-M ������ ��� ��� ������ �������� ����� ������ ������� ������ ���������
		for ( int j=0 ; j < M; j++) {
			if (txt[i + j] != pat[j])//���� �� ������ � ���� ������� ������ �� ����� �������� ��������, �� ��������� � ���������� �������� ������,
				//���� �����, �� ����������� j �� ������� � ��������� �� ����� �� j ������� ���������.
				break;
		}
		if ( j == M)
			std::cout << "Pattern found at index" << j << '\n';
	}
}
int main() {
	std::string second = "red";//���������
	std::string first = "reddeadredemtion";//������
	search(first, second);
	 return 0;
}