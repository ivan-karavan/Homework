#include "sortings.h"
#include <ctime>

using namespace std;

// »змерени€ провести дл€ размеров массива от 1000 до 9000, шаг 1000

void array_rand_0_to_7(int result[], int n); // 1)случайными значени€ми от 0 до 7
void array_rand_0_to_maxInt(int result[], int n); // 2)случайными значени€ми от 0 до максимального целого (кроме сортировки подсчетом)
void array_sorted_0_to_8000(int result[], int n); // 3)ќтсортированными в требуемом пор€дке (по возрастанию) числами от 0 до 8000
void array_sorted_partly(int result[], int n); // 4)Ђѕочтиї отсортированными в требуемом пор€дке числами (например, помен€ть местами 5 пар элементов отсортированного массива п. 3)
void array_sorted_inverted(int result[], int n); // 5)ќтсортированными в обратном пор€дке (по убыванию) числами от 0 до 8000

void array_copy(int etalon[], int copy[], int n);
int array_max_element(unsigned __int64 arr[], int n); // поиск максимального элемента
int array_aver_element(unsigned __int64 arr[], int n); // нахождение среднего арифметического