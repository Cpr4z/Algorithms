#include <iostream>
using namespace std;
int binarySearch(int arr[], int l, int r, int x) {
	if (r >= l) {
		int mid = l + (r - l) / 2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);

	}
	return -1;
}
int main() {
	int arr[]{ 1,3,6,12,23,34,43,65,98,123 };
	cout<<binarySearch(arr, 0, 9, 114);
}