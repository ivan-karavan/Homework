#include "sortings.h"
#include <ctime>

using namespace std;

// ��������� �������� ��� �������� ������� �� 1000 �� 9000, ��� 1000

void array_rand_0_to_7(int result[], int n); // 1)���������� ���������� �� 0 �� 7
void array_rand_0_to_maxInt(int result[], int n); // 2)���������� ���������� �� 0 �� ������������� ������ (����� ���������� ���������)
void array_sorted_0_to_8000(int result[], int n); // 3)���������������� � ��������� ������� (�� �����������) ������� �� 0 �� 8000
void array_sorted_partly(int result[], int n); // 4)������ ���������������� � ��������� ������� ������� (��������, �������� ������� 5 ��� ��������� ���������������� ������� �. 3)
void array_sorted_inverted(int result[], int n); // 5)���������������� � �������� ������� (�� ��������) ������� �� 0 �� 8000

void array_copy(int etalon[], int copy[], int n);
int array_max_element(unsigned __int64 arr[], int n); // ����� ������������� ��������
int array_aver_element(unsigned __int64 arr[], int n); // ���������� �������� ���������������