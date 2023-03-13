#include <iostream>

int uniq()
{
    int array[] = { 1, 2, 1, 7, 8, 9, 8, 1 }; // ������� ������
    const int arr_size = sizeof(array) / sizeof(int);
    int uniq_counts[arr_size]; // ���������� ������� ��������
    int uniq_elements[arr_size]; // ������ ���������� ���������
    int uniq_counter = 0; // ������� ���������� ���������
    // ������ ����� ���������, ���� ���������� ���������� ��� �������
    // ����������� ��������
    for (int i = 0; i < arr_size; i++)
    {
        int existing_index = -1; // ���������� ��� �����������
        // ������� ���������� ��������
        for (int j = 0; j < uniq_counter; j++)
        {
            // ����� i-��� �������� ����� ��� ������������ ���������
            if (uniq_elements[j] == array[i])
            {
                existing_index = j;
                uniq_counts[j]++; // ��������� ���������� ���������� �� 1
                break;
            }
        }
        if (existing_index == -1)
        {
            // ���� ������� ��� �� ����������, �������� ���
            uniq_elements[uniq_counter] = array[i];
            uniq_counts[uniq_counter] = 1;
            uniq_counter++;
        }
    }
    int max_uniq_count_index = 0;
    int max_uniq_count = uniq_counts[0];
    // ������ ����� ��������� ,����� ����������� ���������� ���� ������������
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