#include <iostream>

int uniq()
{
    int array[] = { 1, 2, 1, 7, 8, 9, 8, 1 }; // входной массив
    const int arr_size = sizeof(array) / sizeof(int);
    int uniq_counts[arr_size]; // количества каждого элемента
    int uniq_elements[arr_size]; // массив уникальных элементов
    int uniq_counter = 0; // счётчик уникальных элементов
    // первая часть алгоритма, ищем количества повторений для каждого
    // уникального элемента
    for (int i = 0; i < arr_size; i++)
    {
        int existing_index = -1; // переменная для запоминания
        // индекса найденного элемента
        for (int j = 0; j < uniq_counter; j++)
        {
            // поиск i-ого элемента среди уже обработанных элементов
            if (uniq_elements[j] == array[i])
            {
                existing_index = j;
                uniq_counts[j]++; // увеличили количество повторений на 1
                break;
            }
        }
        if (existing_index == -1)
        {
            // если элемент ещё не встречался, запомним его
            uniq_elements[uniq_counter] = array[i];
            uniq_counts[uniq_counter] = 1;
            uniq_counter++;
        }
    }
    int max_uniq_count_index = 0;
    int max_uniq_count = uniq_counts[0];
    // вторая часть алгоритма ,среди посчитанных повторений ищем максимальное
    for (int i = 0; i < uniq_counter; i++)
    {
        if (max_uniq_count < uniq_counts[i])
            max_uniq_count_index = i;
    }

    return uniq_elements[max_uniq_count_index];
}
int main() {
    std::cout << uniq() << std::endl;
}