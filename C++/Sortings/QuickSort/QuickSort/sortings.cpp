#include "sortings.h"
#include <random>

// This is what you need to do this time.
// Implement these functions and link their invokes together.
// All (!) functions that are not described in header should 
// be used in other functions!

// You are welcome to add some functions but NOT TO CHANGE EXISTING
// FUNCTIONS SIGNATURES.


// Quick-sort is a pivot-based sort algorithm that uses O(1) ADDITIONAL SPACE
// and works in average O(n * log(n)) time complexity. O(n * n) is the worst case.
// depth - recursion depth, leaves - number of leaves in recursion tree

// Quicksort with middle element in array as pivot
void quicksort::quicksort_middle(int* arr, int n, int& depth, int& leaves) {
	// TODO: Implement this method
	recursive_call_qsort(arr, 0, n - 1, quicksort::get_middle_pivot, depth, leaves);
}

// Quicksort with last element in array as pivot
void quicksort::quicksort_last(int* arr, int n, int& depth, int& leaves) {
	// TODO: Implement this method
	recursive_call_qsort(arr, 0, n - 1, quicksort::get_last_pivot, depth, leaves);
}

// Quicksort with random pivot
void quicksort::quicksort_rand(int* arr, int n, int& depth, int& leaves) {
	// TODO: Implement this method
	recursive_call_qsort(arr, 0, n - 1, quicksort::get_rand_pivot, depth, leaves);
}

// Getting position of middle pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_middle_pivot(int from, int to) {
	// TODO: Implement this method
	return (from + to) / 2;
}

// Getting position of last pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_last_pivot(int from, int to) {
	// TODO: Implement this method
	return to;
}

// Getting position of random rot vash ebal pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int quicksort::get_rand_pivot(int from, int to) {
	// TODO: Implement this method
	return from + rand()%(to - from + 1);
}

// Rearranges values in the array using pivot in the current bounds
//
// Additional space: O(1)
// Complexity: O(n)
// RETURNS: new position of the pivot in the array.
int quicksort::recompute_with_pivot(int* arr, int from, int to, int pivot_pos) {
	// TODO: Implement this method
	return 0;
}

// Recursive call for qsort that sorts the array
// in the current bounds
//
// Additional space: O(1)
// Complexity: O(n*log(n)) - average. O(n*n) - the worst case.
void quicksort::recursive_call_qsort(int* arr, int from, int to, pivot_chooser pivot_chooser, int& depth, int& leaves) {
	// TODO: Implement this method
	depth++;

	int i = from,
		j = to;
	int x = arr[pivot_chooser(from ,to)]; //опорный элемент

	do // пока i и j не пересеклись
	{
		while (arr[i] < x) i++; // идём до элемента не из левой группы (больше разделительного)
		while (arr[j] > x) j--; // идём, пока не встретим элемент меньше разделительного

		if (i <= j)
		{
			if (arr[i] > arr[j]) // строгое для устойчивости
				swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (from < j) // рекурсивный вызов для левой части массива
	{
		depth++; //увеличиваем глубину
		recursive_call_qsort(arr, from, j, pivot_chooser, depth, leaves);
	}
	if (to > i) // рекурсивный вызов для правой части массива
	{
		depth++;
		recursive_call_qsort(arr, i, to, pivot_chooser, depth, leaves);
	}
	if (from >= j && to <= i) // если не пошли вглубь, то это лист
		leaves++;
}