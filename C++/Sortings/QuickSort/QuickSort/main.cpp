#include "sortings.h";

int main()
{
	int arr[] = {9,8,7,6,5,5,5,5,9,9};
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	cout << endl;
	int depth, leaves;
	quicksort::quicksort_middle(arr, 10, depth, leaves);
	for (int i = 0; i < 10; i++)
		cout << arr[i] << " ";
	system("pause");
	return 0;
}