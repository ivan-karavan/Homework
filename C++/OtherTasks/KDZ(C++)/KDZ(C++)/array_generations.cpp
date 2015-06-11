#include "array_generations.h"

// Измерения провести для размеров массива от 1000 до 9000, шаг 1000

// 1)случайными значениями от 0 до 7
void array_rand_0_to_7(int result[], int n)
{
	int max = 7;
	for (int i = 0; i < n; i++)
		result[i] = rand()%(max + 1);
}

// 2)случайными значениями от 0 до максимального целого (кроме сортировки подсчетом)
void array_rand_0_to_maxInt(int result[], int n)
{
	int max = INT_MAX;
	for (int i = 0; i < n; i++)
		result[i] = rand()%(max);
}

// 3)Отсортированными в требуемом порядке (по возрастанию) числами от 0 до 8000
void array_sorted_0_to_8000(int result[], int n)
{
	int max = 8000;
	for (int i = 0; i < n; i++)
		result[i] = rand()%(max + 1);
	quick_sort_middle(result, n);
}

// 4)«Почти» отсортированными в требуемом порядке числами (например, поменять местами 5 пар элементов отсортированного массива п. 3)
void array_sorted_partly(int result[], int n)
{
	int max = 8000;
	for (int i = 0; i < n; i++)
		result[i] = rand()%(max + 1);
	quick_sort_middle(result, n);
	swap(result[0], result[100]);
	swap(result[200], result[777]);
	swap(result[111], result[410]);
	swap(result[250], result[555]);
	swap(result[500], result[880]);
}

// 5)Отсортированными в обратном порядке (по убыванию) числами от 0 до 8000
void array_sorted_inverted(int result[], int n)
{
	int max = 8000;
	for (int i = 0; i < n; i++)
		result[i] = rand()%(max + 1);
	quick_sort_middle(result, n);
	for (int i = 0; i < n/2; i++)
		swap(result[i], result[n-1-i]);
}

void array_copy(int etalon[], int copy[], int n)
{
	for (int i = 0; i < n; i++)
		copy[i] = etalon[i];
}

int array_max_element(unsigned __int64 arr[], int n)
{
	__int64 max = arr[0];
	for(int i = 1; i < n; i++)
		if (max < arr[i])
			max = arr[i];
	return max;
}

int array_aver_element(unsigned __int64 arr[], int n)
{
	__int64 sum = 0;
	for (int i = 0; i < n; i++)
		sum += arr[i];
	return sum/(__int64)n;
}