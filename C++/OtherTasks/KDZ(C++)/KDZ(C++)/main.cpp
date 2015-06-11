#include "array_generations.h"
#include <intrin.h>
#include <fstream>
#include <string>
#pragma intrinsic(__rdtsc)

typedef	void (*any_sort)(int* arr, int n);
typedef void (*type_of_arr)(int* arr, int n);

void test_arrays(int* copy, int n, int* etalon, unsigned __int64* timesOfTests);
void test_sorting(int* copy, int n, any_sort any_sort, int* etalon, unsigned __int64* timesOfTests, string nameOfSort);

// ��������� ��� ������ ���������� ���������� � ������� �����
void save_results(unsigned __int64 max, unsigned __int64 average, string nameOfSort)
{
	ofstream fOut;
	fOut.open("results_of_sortings.txt", ios::app);

	fOut << nameOfSort << "\n";
	fOut << max << "  max\n" << average << "  average\n";
	
	fOut.close();
}

// ��������� ���������� ������ ��������
void file_dividing_results(string typeOfArr,int size)
{
	ofstream fOut;
	fOut.open("results_of_sortings.txt", ios::app);

	fOut << "------------------------\n" << typeOfArr << " | " << size << "\n";

	fOut.close();
}

// ������ ������� ��� ������ �� ��������
void test_array_sizes(int* copy, int* etalon, unsigned __int64* timesOfTests, string typeOfArr, type_of_arr type_of_arr)
{
	for (int n = 1000; n <= 9000; n+=1000)
	{
		type_of_arr(etalon, n); // ���������� ������-������
		file_dividing_results(typeOfArr, n);
		test_arrays(copy, n, etalon, timesOfTests);
	}
}

// ��� ���������� ���������
void test_arrays_to_maxInt(int* copy, int n, int* etalon, unsigned __int64* timesOfTests)
{
	cout << "bubble sort" << endl;
	test_sorting(copy, n, bubble_sort, etalon, timesOfTests, "bubble sort");
	cout << "bubble iverson 1" << endl;
	test_sorting(copy, n, bubble_iverson_1, etalon, timesOfTests, "bubble iverson 1");
	cout << "bubble iverson 2" << endl;
	test_sorting(copy, n, bubble_iverson_2, etalon, timesOfTests, "bubble iverson 2");
	cout << "inserion sort" << endl;
	test_sorting(copy, n, insertion_sort, etalon, timesOfTests, "insertion sort");
	cout << "binary sort" << endl;
	test_sorting(copy, n, binary_sort, etalon, timesOfTests, "binary sort");
	cout << "radix256 sort" << endl;
	test_sorting(copy, n, radix_sort256, etalon, timesOfTests, "radix256 sort");
	cout << "merge sort" << endl;
	test_sorting(copy, n, merge_sort, etalon, timesOfTests, "merge sort");
	cout << "heap sort" << endl;
	test_sorting(copy, n, heap_sort, etalon, timesOfTests, "heap sort");
	cout << "quick sort middle" << endl;
	test_sorting(copy, n, quick_sort_middle, etalon, timesOfTests, "quick sort middle");
	cout << "quick sort last" << endl;
	test_sorting(copy, n, quick_sort_last, etalon, timesOfTests, "quick sort last");
	cout << "shell sort" << endl;
	test_sorting(copy, n, shell_sort, etalon, timesOfTests, "shell sort");
}

// ��� ���������� ���������
void test_array_sizes_to_maxInt(int* copy, int* etalon, unsigned __int64* timesOfTests, string typeOfArr, type_of_arr type_of_arr)
{
	for (int n = 1000; n <= 9000; n+=1000)
	{
		type_of_arr(etalon, n); // ���������� ������-������
		file_dividing_results(typeOfArr, n);
		test_arrays_to_maxInt(copy, n, etalon, timesOfTests);
	}
}

// ��������� ������ �o�������� 50 ��� � ��������� ���������� � ����
void test_sorting(int* copy, int n, any_sort any_sort, int* etalon, unsigned __int64* timesOfTests, string nameOfSort)
{
	unsigned __int64 curTime;
	for (int i = 0; i < 50; i++)
	{
		array_copy(etalon, copy, n);
		curTime = __rdtsc();
		any_sort(copy, n);
		timesOfTests[i] = __rdtsc() - curTime;
	}

	cout << array_max_element(timesOfTests, 50) << endl;
	cout << array_aver_element(timesOfTests, 50) << endl;

	save_results(array_max_element(timesOfTests, 50), array_aver_element(timesOfTests, 50), nameOfSort);
}

// ������ ��� ���� �������� �� ������ �����������
void test_arrays(int* copy, int n, int* etalon, unsigned __int64* timesOfTests)
{
	cout << "bubble sort" << endl;
	test_sorting(copy, n, bubble_sort, etalon, timesOfTests, "bubble sort");
	cout << "bubble iverson 1" << endl;
	test_sorting(copy, n, bubble_iverson_1, etalon, timesOfTests, "bubble iverson 1");
	cout << "bubble iverson 2" << endl;
	test_sorting(copy, n, bubble_iverson_2, etalon, timesOfTests, "bubble iverson 2");
	cout << "inserion sort" << endl;
	test_sorting(copy, n, insertion_sort, etalon, timesOfTests, "insertion sort");
	cout << "binary sort" << endl;
	test_sorting(copy, n, binary_sort, etalon, timesOfTests, "binary sort");
	cout << "counting sort" << endl;
	test_sorting(copy, n, counting_sort, etalon, timesOfTests, "counting sort");
	cout << "radix256 sort" << endl;
	test_sorting(copy, n, radix_sort256, etalon, timesOfTests, "radix256 sort");
	cout << "merge sort" << endl;
	test_sorting(copy, n, merge_sort, etalon, timesOfTests, "merge sort");
	cout << "heap sort" << endl;
	test_sorting(copy, n, heap_sort, etalon, timesOfTests, "heap sort");
	cout << "quick sort middle" << endl;
	test_sorting(copy, n, quicksort_middle, etalon, timesOfTests, "quick sort middle");
	cout << "quick sort last" << endl;
	test_sorting(copy, n, quicksort_last, etalon, timesOfTests, "quick sort last");
	cout << "shell sort" << endl;
	test_sorting(copy, n, shell_sort, etalon, timesOfTests, "shell sort");
}


int main()
{
	unsigned __int64 timesOfTests[50];
	int* etalon = new int[9000]; // ������-������
	int* copy = new int[9000]; // ����� �������


	// 1 ��� ������� | complete
	test_array_sizes(copy, etalon, timesOfTests, "��������� �������� �� 0 �� 7", array_rand_0_to_7);

	// 2 ��� �������
	//test_array_sizes_to_maxInt(copy, etalon, timesOfTests, "��������� �������� �� 0 �� maxInt", array_rand_0_to_maxInt);

	// 3 ��� �������
	//test_array_sizes(copy, etalon, timesOfTests, "���������������, �� 0 �� 8000", array_sorted_0_to_8000);

	// 4 ��� �������
	//test_array_sizes(copy, etalon, timesOfTests, "����� ���������������, �� 0 �� 8000", array_sorted_partly);

	// 5 ��� �������
	//test_array_sizes(copy, etalon, timesOfTests, "������� �������������, �� 0 �� 8000", array_sorted_inverted);

	delete [] copy;

	delete [] etalon;
	system("pause");
	return 0;
}