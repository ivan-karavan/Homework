#include "sortings.h";

void insertion_sort(int a[], int n) {
	//TODO: write your insertion sort
	if (is_sort(a, n) == true)
		return;
	int b, j;
	for (int i = 1; i < n; i++)
	{
		b = a[i];
		j = i-1;
		while (b < a[j] && j >= 0)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = b;
	}
}

void binary_sort(int a[], int n) {
	//TODO: write your binary insertion sort
	if (is_sort(a, n) == true)
	{
		cout << "Массив отсортирован";
		return;
	}
	int lf, rg, c;
	int k, p;
	for (int i = 1; i < n; i++)
	{
		lf = 0;
		rg = i - 1;
		c = (lf + rg) / 2;
		while (lf != c)
		{
			if (a[c] > a[i])
				rg = c-1;
			else 
				lf = c;
			c = (lf + rg)/2;
		}
		if (a[lf] < a[i])
		{
			if (a[i] > a[rg])
				lf = rg + 1;
			else
				lf = rg;
		}
		k = i;
		p = a[i];
		while (k > lf)
		{
			a[k] = a[k-1];
			k = k-1;
		}
		a[lf] = p;
	}
	
}


void array_generation(int result[], int n, int min, int max) { 
	//TODO: you need to provide your array generation
	srand(time(0));
	for (int i = 0; i < n; i++)
		result[i] = min + rand()%(max - min + 1);
}

void results(int a[], int n) {
	//TODO: you need to output array, use standart c++ output
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

bool is_sort(int a[], int n) {
	//TODO: you need to check out your array is sorted or not
	//return false or true;
	bool check = true;
	for (int i = 1; i < n; i++)
	{
		if (a[i] < a[i-1])
		{
			check = false;
			break;
		}
	}
	return check;
}