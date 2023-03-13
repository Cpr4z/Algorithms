#include<iostream>
using namespace std;
int getMax(int* arr, int n) {
	int max = arr[0];
	for (size_t i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
void countSort(int* arr, int n, int exp) {
	int* output = new int[n];
	int count[10] = { 0 };

	for (int i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;//243- остаток от деления на 10 равен 3

	for (size_t i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	for (int i = n-1; i>=0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (size_t i = 0; i < n; i++)
	{
		arr[i] = output[i];
	}
}

void radixSort(int* arr, int n) {
	int m = getMax(arr, n);
	int exp = 1;
	countSort(arr, n, exp);
	exp = 10;
	countSort(arr, n, exp);
	exp = 100;
	countSort(arr, n, exp);
}
int main() {
	int arr[] = { 12,654,324,235,6 };
	int n = sizeof(arr) / sizeof(arr[0]);
	radixSort(arr, n);
	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
	
}