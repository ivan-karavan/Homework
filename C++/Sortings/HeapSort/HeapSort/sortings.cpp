#include "sortings.h";

void build_heap(int a[], int n);
void heapify(int a[], int i, int heap_size);

void heap_sort(int a[], int n) {
	//TODO: write your heap sort
	build_heap(a, n);//���� ���������
	int heap_size = n - 1;
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heap_size = heap_size - 1;// ��������� �� 1, �� ��������� ������� ���� ��� ������������
		heapify(a, 0, heap_size);//� ����������� ���� ������������ � �������� ��������
	}
}

void array_generation(int result[], int n, int min, int max) { 
	//TODO: you need to provide your array generation
	for (int i = 0; i < n; i++)
		result[i] = min + rand()%(max - min + 1);
}

void results(int a[], int n) {
	//TODO: you need to output array, use standart c++ output
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
	if (is_sort(a, n))
		cout << "������ ������������";
	else
		cout << "������ �� ������������";
}

bool is_sort(int a[], int n) {
	//TODO: you need to check out your array is sorted or not
	//return false or true;
	for (int i = 0; i < n; i++)
		if (a[i] < a[i-1])
			return false;
	return true;
}

int left(int i)
{
	return 2*i + 1;
}

int right(int i)
{
	return 2*i + 2;
}

void build_heap(int a[], int lenght)//���������� ����
{
	for (int i = lenght/2; i >=0; i--)//������� � ���������� �������� �������� heapify
		heapify(a, i, lenght);
}

void heapify(int a[], int i, int heap_size)//��������� ��������� �������� ���� �[parent(i)] >= a[i]
{
	int l = left(i);
	int r = right(i);
	int largest;
	if (l <= heap_size &&  a[l] > a[i])//��������� ����� ����
		largest = l;
	else
		largest = i;
	if (r <= heap_size && a[r] > a[largest])//��������� ������ ����
		largest = r;
	if (largest != i)//���� ���������� � ��������������� ������ �� � �������
	{
		swap(a[i], a[largest]);//�� ��������� ���������� � �������
		heapify(a, largest, heap_size);// � ������ ������
	}
}