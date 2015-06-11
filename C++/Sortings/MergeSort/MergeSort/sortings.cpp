#include "sortings.h";

void merge(int a[], int l, int m, int r);
void divide_and_merge(int a[], int l, int r);

// Despite the incapsulation, decomposisition was made here to make it generally testable.
// (In real life, functions divide_and_merge() and merge() should be hidden (for example, private))

// Initial call of function.
// void merge_sort(int* arr, int n);

// Recursive function to divide the array and merge it in current bounds [from, to].
// void divide_and_merge(int* arr, int from, int to);

// Method to merge two sorted pieces of array to one sorted piece.
// Normally, first piece indexes are in bounds: [from, from + (to - from) / 2];
// second piece indexes are in bounds: [from + (to - from) / 2 + 1, to];
// method should make the array sorted in bounds [from, to] in O(n) time complexity.
// void merge(int* arr, int from, int to); 

void merge_sort(int a[], int n) {
	//TODO: write your merge sort
	divide_and_merge(a, 0, n-1);
}

void array_generation(int result[], int n, int min, int max) { 
	//TODO: you need to provide your array generation
	for (int i = 0; i < n; i++)
		result[i] = min + rand()%(max - min + 1);
}

void results(int a[], int n) {
	//TODO: you need to output array, use standart c++ output
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	if(is_sort(a, n))
		cout << "Массив отсортирован";
	else
		cout << "Массив не отсортирован";
	cout << endl;
}

bool is_sort(int a[], int n) {
	//TODO: you need to check out your array is sorted or not
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1])
			return false;
	return true;
}

void merge(int a[],int l, int m, int r)
{
	int *b = new int[r+1];// сохраняем старое положение чисел в этом массиве
	for (int i = l; i <= r; i++)
		b[i] = a[i];
	int p1, p2;// позиции первого и второго отсортированного массива, которые мы сливаем
	p1 = l;
	p2 = m + 1;
	for (int curPos = l; curPos <= r; curPos++)
	{
		if ((p1 > m) || (p2 > r))
			if (p1 > m) //если первый массив кончился, записываем весь оставшийся второй
			{
				a[curPos] = b[p2];
				p2++;//продвигаемся по второму массиву
			}
			else//аналогично первый записываем, если второй кончился
			{
				a[curPos] = b[p1];
				p1++;
			}
		else //выбираем наименьшее на текущих позициях
			if (b[p1] > b[p2])
			{
				a[curPos] = b[p2];
				p2++;
			}
			else
			{
				a[curPos] = b[p1];
				p1++;
			}
	}
	delete [] b;
}

void divide_and_merge(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2; //правая граница левого массива и левая-1 правого массива
		divide_and_merge(a, l , m);
		divide_and_merge(a, m + 1, r);
		merge(a, l, m, r);
	}
}