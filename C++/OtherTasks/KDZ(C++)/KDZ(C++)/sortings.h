#include <iostream>
#include <Windows.h>
#include <cmath>

using namespace std;

void bubble_sort(int a[], int n); // 1)������
void bubble_iverson_1(int a[], int n); // 2)������ �������� 1
void bubble_iverson_2(int a[], int n); // 3)������ �������� 2
void insertion_sort(int a[], int n); // 4)�������� ���������
void binary_sort(int a[], int n); // 5)��������� ���������
void counting_sort(int a[], int n); // 6)��������� 
void radix_sort256(int a[], int n); // 7)�������� (256 ��)
void merge_sort(int a[], int n); // 8)��������
void heap_sort(int a[], int n); // 9)�����
void quick_sort_middle(int arr[], int n); // 10)������� �� ������� ��������� ���������
void quick_sort_last(int arr[], int n); // 11)������� � ��������� ��������� ���������
void shell_sort(int a[], int n); // 12)�����

void quicksort_middle(int arr[], int n); // 10)������� �� ������� ��������� ���������
void quicksort_last(int arr[], int n); // 11)������� � ��������� ��������� ���������