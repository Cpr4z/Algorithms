#include <iostream>
using namespace std;
void merge(int* arr, int l, int m, int r) {
	const int nl = m - l + 1;
	const int nr = r - m ;
	int left[nl], right[nr];

	for (int i = 0; i < nl; i++)
		left[i] = arr[l + i];

	for (int j = 0; j < nr; j++)
		right[j] = arr[m + j + 1];

	int i = 0, j = 0;
	int k = l;
	
	while (i < nl && j < nr) {
		if (left[i] <= right[j])
			arr[k++] = left[i++];
		else
			arr[k++] = right[j++];
	}
	while (i < nl) {
		arr[k++] = left[i++];
	}
	while (j < nr) {
		arr[k++] = right[j++];
	}
}


int main() {
	int arr[]{ 2,1,10,-5,-40,-20,0,4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	merge(arr, 0,(n-1-0)/2, n - 1);
	return 0;
}