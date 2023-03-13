#include <iostream>
using namespace std;
struct bucket {
	int count;
	int* data;

};
int get_Max(int* arr, int n) {
	int max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
int Get_Exp(int value) {
	int exp = 1;
	while (value > 10) {
		value /= 10;
		exp *= 10;
	}
	return exp;
}
void countSort(int* arr, int n)
{
    if (!n)
        return;
    int* output = new int[n];
    int max = get_Max(arr, n);
    int* count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
        count[i] = 0;

    for (int i = 0; i < n; i++)
        count[arr[i]]++;  // подсчитываем  частоту повторения элементов

    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];  // вычисляем накопленные суммы

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];  // устанавливаем элемент на корректное место 
        count[arr[i]]--; // уменьшаем частоту, так как уже записали элемент
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];

    delete[] output;
    delete[] count;
}
void bucketSort(int* arr, int n) {
    struct bucket buckets[10];
    int exp = Get_Exp(get_Max(arr, n));
    for (int i = 0; i < 10; i++)
    {
        buckets[i].count = 0;
        buckets[i].data = new int[n];
    }
    for (int i = 0; i < n; i++)
    {
        int bi = arr[i] / exp;
        buckets[bi].data[buckets[bi].count++] = arr[i];
    }
   /* for (int i = 0; i < n; i++) {
        for (int j = 1; j < buckets[i].count; j++) {
            int key =buckets[i].data[j];
            int g = j - 1;
            while (g >= 0 && key < buckets[i].data[g]) {
                buckets[i].data[g + 1] = buckets[i].data[g];
                buckets[j].data[g] = key;
                g--;

            }
        }
    }
    int CNT = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < buckets[i].count; j++) {
            arr[CNT] = buckets[i].data[j];
            CNT++;
        }
    }*/

    

    for (int i = 0; i < 10; i++) {
        countSort(buckets[i].data, buckets[i].count);
    }
    int CNT = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < buckets[i].count;j++) {
            arr[CNT] = buckets[i].data[j];
            CNT++;
        }
    }
}
int main() {
    int arr[]{ 2,5,6,34,23,0,5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucketSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;

}