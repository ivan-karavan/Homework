#include "sortings.h";

/*
Name + Surname: Перевощиков Иван
Group: 202(2)ПИ
Date: 28.09.2014
Task: Функции сортировки пузырьком
IDE: Microsoft Visual Studio 2010
*/

void main() {
	setlocale(LC_ALL,"Russian");
	int n, max, min;
	int *a;
	cout << "Введите длину массива: ";
	cin >> n;
	a = new int[n];
	cout << "Введите максимальное значение: ";
	cin >> max;
	cout << "Введите минимальное значение: ";
	cin >> min;

	array_generation(a, n, min, max);
	cout << "array before:" << endl;
	results(a, n);
	bubble_sort(a, n);
	cout << "after bubble sort:" << endl;
	results(a,n);
	cout << endl;
	
	array_generation(a, n, min, max);
	cout << "array before:" << endl;
	results(a, n);
	bubble_iverson_1(a, n);
	cout << "after bubble sort iverson 1:" << endl;
	results(a,n);
	cout << endl;

	array_generation(a, n, min, max);
	cout << "array before:" << endl;
	results(a, n);
	bubble_iverson_2(a, n);
	cout << "after bubble sort iverson 2:" << endl;
	results(a,n);

	delete [] a;
	system("pause");
	//TODO: make console application, use methods in sortings file
	/* User must have possibility to:
		1) generate array;
		2) sort array using bubble sort;
		3) sort array using bubble sort with Iverson I;
		4) sort array using bubble sort with Iverson II;
		5) output result (array before sorting and after);
		6) exit.
		P.S: while new array isn't generated, you need to sort previous generated array (which is not sorted)
	*/
}
