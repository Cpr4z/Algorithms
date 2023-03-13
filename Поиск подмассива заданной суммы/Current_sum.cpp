#include <iostream>

bool subArraySum(int arr[], int n, int sum) {//����� ���������� �������� ����� � �������
	int curr_sum = arr[0], start = 0;//start- ����������- �������, ������� ��� �� ������ ����� �� �������� �������
	for (int i = 1; i <= n; i++) {
		while (curr_sum > sum && start < i - 1) {//start ������ ������ �� 1 ��� i ��� ��� � ������� ������ ���� ���� �� 1 �������
			curr_sum = curr_sum - arr[start];
			start++;
		}
		if (curr_sum == sum) {
			std::cout << start << " " << i - 1 << std::endl;
			return true;
		}
		if (i < n)
			curr_sum = curr_sum + arr[i];
	}
	std::cout << "-1" << std::endl;
	return false;
}
int main() {
	int array[]{ 8,4,2,3,5 };
	int n = sizeof(array)/sizeof(int);
	int summa = 5;
	subArraySum(array, n, summa);

}