#include "sortings.h";
#include <cmath>;


union rad256
{
	int num;
	unsigned char chars[4];
};

int max_search(int a[], int n);
int digit(int num, int i);

void counting_sort(int a[], int n) {
	//TODO: write your stable counting sort here (only positive numbers)
	int max = max_search(a, n); //поиск максимума - длины массива с

	int *b = new int[n];
	for (int i = 0; i < n; i++)//инициализация массива нулями
		b[i] = 0;

	int *c = new int[max + 1];
	for (int i = 0; i <= max; i++)//инициализация массива нулями
		c[i] = 0;

	for (int i = 0; i < n; i++)//подсчёт количества элементов a[i]-ых
		c[a[i]] = c[a[i]] + 1;

	for (int j = 1; j <= max; j++)//для устойчивости
		c[j] = c[j] + c[j - 1];

	for (int i = n - 1; i >= 0; i--)//записываем числа a[i] в b на свои места
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}

	for (int i = 0; i < n; i++)
		a[i] = b[i];

	delete [] b;
	delete [] c;
}

void radix_sort10(int a[], int n) {
	//TODO: write your radix sort here (10 number system, only positive numbers)
	int max = max_search(a, n);
	int count = 0;
	while(max > 0)//количество разрядов в числах
	{
		max /= 10;
		count++;
	}
	int d;//текущее значение разряда
	for (int i = 0; i < count; i++)//проходим по всем разрядам
	{
		int *b = new int[n];
		for (int i = 0; i < n; i++)//инициализация массива нулями
			b[i] = 0;

		int *c = new int[10];
		for (int j = 0; j < 10; j++)//инициализация массива нулями
			c[j] = 0;

		for (int j = 0; j < n; j++)//заполняем массив с только для одного разряда
		{
			d = digit(a[j], i);
			c[d]++;
		}

		for (int j = 1; j < 10; j++)//для устойчивости
			c[j] = c[j] + c[j-1];
		
		for (int j = n - 1; j >= 0; j--)
		{
			d = digit(a[j], i);
			b[c[d] - 1] = a[j];
			c[d]--;
		}

		for (int j = 0; j < n; j++)
			a[j] = b[j];

		delete [] b;
		delete [] c;
	}
}

void radix_sort256(int a[], int n) {
	//TODO: write your radix sort here (256 number system, only positive numbers)
		rad256 *un_arr = new rad256[n];          
 
        for (int i = 0; i < n; i++)//записываем в каждый юнион значение элементов массива
			un_arr[i].num = a[i];
 
        for(int i = 0; i < 4; i++) 
		{ 
			int *A = new int[n];//массив разрядов
			rad256 *b = new rad256[n];               
			int *c = new int[256];
                
			for (int j = 0; j < n; j++)//чары будут разрядами числа				
				A[j] = un_arr[j].chars[i];
                
			for (int j = 0; j < 256; j++)//инициализация массива с нулями				
				c[j] = 0;
                
			for (int j = 0; j < n; j++)//заполняем массив с		
				c[A[j]] = c[A[j]] + 1;
              
			for (int j = 1; j < 256; j++)//для устойчивости
				c[j] = c[j] + c[j - 1];
              
			for (int j = n - 1; j >= 0; j--)
                {                        
					b[c[A[j]] - 1] = un_arr[j];                        
					c[A[j]] = c[A[j]] - 1;
                }
                
			for (int j = 0; j < n; j++)					
				un_arr[j] = b[j];
               
			delete [] A;              
			delete [] b;               
			delete [] c;
        }
 
        for (int i = 0; i < n; i++)
			a[i] = un_arr[i].num;

        delete [] un_arr;
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
	if(is_sort(a, n))
		cout << "Массив отсортирован";
	else
		cout << "Массив не отсортирован";
	cout << endl;
}

bool is_sort(int a[], int n) {
	//TODO: you need to check out your array is sorted or not
	//return false or true;
	for (int i = 1; i < n; i++)
		if (a[i] < a[i - 1])
		{
			return false;
		}
	return true;
}

int max_search(int a[], int n)//поиск максимума в массиве
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int digit(int num, int i)//возвращает i-ый разряд(начиная с 0) числа num
{
	for(; i>0 ; i--)
		num /= 10;
	num = num % 10;
	return num;
}