#include "knapsack.h"


//dynamic methods
int knapsack::dynamic_recursive_call(int items_to_pack, int capacity, int** matrix)
{
	if (items_to_pack < 0) // терминальное условие
		return 0;
	if (items[items_to_pack - 1].weight > capacity)
	{
		if (matrix[items_to_pack][capacity] != -1) // без вызова рекурсии, берём значения из матрицы
			return matrix[items_to_pack][capacity];
		else // с вызовом рекурсии
			return dynamic_recursive_call(items_to_pack - 1, capacity, matrix);
	}
	else // берём предмет
		return fmax(dynamic_recursive_call(items_to_pack - 1, capacity, matrix),
		dynamic_recursive_call(items_to_pack - 1, capacity - items[items_to_pack].weight, matrix) + items[items_to_pack].cost);
}

int** knapsack::make_matrix_for_dynamic(int n, int capacity)
{
	int** matrix = new int*[n + 1];
	for (int i = 0; i <= n; i++)
		matrix[i] = new int[capacity + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= capacity; j++)
		{		
		if ((i == 0) || (j == 0))
			matrix[i][j] = 0;
		else
			matrix[i][j] = -1;
		}
	return matrix;
}

int knapsack::dynamic_knapsack(item* items, int n, int capacity)
{
	int** matrix = make_matrix_for_dynamic(n, capacity);

	for (int i = 1; i <= n; i++) // по всем предметам
		for (int w = 1; w <= capacity; w++) // по всем весам
		{
		if (matrix[i][w] == -1)
			matrix[i][w] = dynamic_recursive_call(i, w, matrix);
		else
			if (items[i].weight <= w)
				matrix[i][w] = fmax(matrix[i - 1][w], matrix[i - 1][w - items[i].weight] + items[i].cost);
			else
				matrix[i][w] = matrix[i - 1][w];
		}
	int result = matrix[n][capacity];

	delete[] matrix;

	return result;
}

// backtrack methods
int knapsack::backtracking_recursive_call(int current_item, int current_weight, int current_cost, int capacity)
{
	if (current_item < 0) // терминальное условие
		return 0;
	if (current_weight > capacity) // не берём этот предмет
		return backtracking_recursive_call(current_item - 1, current_weight, current_cost, capacity);
	else // берём наилучший вариант
		return fmax(current_cost, backtracking_recursive_call(current_item - 1,
		capacity - items[current_item].weight, current_cost + items[current_item].cost, capacity));
}

int knapsack::backtrack_knapsack(item* items, int n, int capacity)
{
	return backtracking_recursive_call(n-1, items[n-1].weight, items[n-1].cost, capacity);
}

// greedy methods
void quick_sort(item* arr, int from, int to)
{
	int i = from,
		j = to;
	double x = arr[(from + to) / 2].cost / arr[(from + to) / 2].weight; //опорный элемент

	do // пока i и j не пересеклись
	{
		while ((arr[i].cost / arr[i].weight) < x) i++; // идём до элемента не из левой группы (больше разделительного)
		while ((arr[j].cost / arr[j].weight) > x) j--; // идём, пока не встретим элемент меньше разделительного

		if (i <= j)
		{
			if ((arr[i].cost / arr[i].weight) > (arr[j].cost / arr[j].weight)) // строгое для устойчивости
			{
				//swap(arr[i], arr[j]);
				int temp = arr[i].cost;
				arr[i].cost = arr[j].cost;
				arr[j].cost = temp;
				temp = arr[i].weight;
				arr[i].weight = arr[j].weight;
				arr[j].weight = temp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (from < j) // рекурсивный вызов для левой части массива
	{
		quick_sort(arr, from, j);
	}
	if (to > i) // рекурсивный вызов для правой части массива
	{
		quick_sort(arr, i, to);
	}
}

void reverse(item* arr, int n)
{
	int temp, j;
	for (int i = 0; i < n / 2; i++)
	{
		j = n - i;
		temp = arr[i].cost;
		arr[i].cost = arr[j].cost;
		arr[j].cost = temp;
		temp = arr[i].weight;
		arr[i].weight = arr[j].weight;
		arr[j].weight = temp;
	}
}

void knapsack::sort_items_by_priority(item* items, int n, int capacity)
{
	quick_sort(items, 0, n - 1);
	reverse(items, n - 1);
}

int knapsack::greedy_knapsack(item* items, int n, int capacity)
{
	int maxValueOfKnapsack = 0;
	int i = 0;
	sort_items_by_priority(items, n, capacity);
	while (capacity >= items[i].weight)
	{
		maxValueOfKnapsack += items[i].cost;
		capacity -= items[i].weight;
		i++;
	}
	return maxValueOfKnapsack;
}