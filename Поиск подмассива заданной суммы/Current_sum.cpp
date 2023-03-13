#include <iostream>

bool subArraySum(int arr[], int n, int sum) {//поиск подмассива заданной суммы в массиве
	int curr_sum = arr[0], start = 0;//start- переменная- счетчик, сколько раз мы отняли число из текущего массива
	for (int i = 1; i <= n; i++) {
		while (curr_sum > sum && start < i - 1) {//start всегда меньше на 1 чем i так как в массиве должен быть хотя бы 1 элемент
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