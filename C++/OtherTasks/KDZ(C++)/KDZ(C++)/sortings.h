#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

void bubble_sort(int a[], int n); // 1)пузырёк
void bubble_iverson_1(int a[], int n); // 2)пузырёк айверсон 1
void bubble_iverson_2(int a[], int n); // 3)пузырёк айверсон 2
void insertion_sort(int a[], int n); // 4)простыми вставками
void binary_sort(int a[], int n); // 5)бинарными вставками
void counting_sort(int a[], int n); // 6)подсчётом 
void radix_sort256(int a[], int n); // 7)цифровая (256 СС)
void merge_sort(int a[], int n); // 8)слиянием
void heap_sort(int a[], int n); // 9)кучей
void quick_sort_middle(int arr[], int n); // 10)быстрая со средним барьерным элементом
void quick_sort_last(int arr[], int n); // 11)быстрая с последним барьерным элементом
void shell_sort(int a[], int n); // 12)Шелла

void quicksort_middle(int arr[], int n); // 10)быстрая со средним барьерным элементом
void quicksort_last(int arr[], int n); // 11)быстрая с последним барьерным элементом