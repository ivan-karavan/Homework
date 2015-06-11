#include "sortings.h";

void bubble_sort(int a[], int n) {
   //TODO: write your bubble sort 
	int P;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
			if (a[j] > a[j + 1])
			{
				P = a[j];
				a[j] = a[j+1];
				a[j+1] = P;
			}
	}
}

void bubble_iverson_1(int a[], int n) {
	//TODO: write your bubble sort with Iverson I
	int P;
	bool T = false;
	for (int i = 0; i < (n - 1) && !T; i++)
	{
		if (T!=true)
		{
			T = true;
			for (int j = 0; j < (n - 1 - i); j++)
				if (a[j] > a[j + 1])
				{
					P = a[j];
					a[j] = a[j+1];
					a[j+1] = P;
					T = false;
				}
		}
	}
}

void bubble_iverson_2(int a[], int n) {
	//TODO: write your bubble sort with Iverson II
	int P, t = 0;
	int Bound = n - 1;
	//for (int i = 0; i < n - 1; i++)
	int i = 0;
	do
	{
		for (int j = 0; j < Bound; j++)
			if (a[j] > a[j + 1])
			{
				P = a[j];
				a[j] = a[j+1];
				a[j+1] = P;
				t = j;
			}
		if (!(t == 0))
			Bound = t;
	i++;
	}while (i < n - 1);//(Bound!=0);
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

bool is_sorted(int a[], int n) {
	//TODO: you need to check if array sorted or not
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