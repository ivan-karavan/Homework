#include <iostream> //all necessary libraries
#include <ctime>
#include <Windows.h>

using namespace std; //standart c++ namespace

void insertion_sort(int a[], int n); //methods prototypes
void binary_sort(int a[], int n);

void array_generation(int result[], int n, int min, int max); //methods prototypes for main()
void results(int a[], int n);
bool is_sort(int a[], int n);