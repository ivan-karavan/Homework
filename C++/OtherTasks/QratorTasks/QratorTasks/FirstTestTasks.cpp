#include <iostream>
#include <vector>

using namespace std;

int local_minimum(const vector<int>& a);
int local_minimum_ternary(const vector<int>& a);
int n_swaps(const vector<int>& a);

int main()
{
	return 0;
}

// O(n), linear search
// array can include more than one local minimum
// we will find the first one
int local_minimum(const vector<int>& a)
{
	if (a.size() <= 1)
		return 0;
	if (a[0] < a[1])
		return 0;
	if (a.back() < a[a.size() - 2])
		return a.size() - 1;
	if (a.size() == 3)
		return 1;

	int min = 1;
	while (min < a.size() - 1 && !(a[min] < a[min - 1] && a[min] < a[min + 1]))
		++min;
	return min;
}

// O(log n), ternary search
// We must find one local minimum,
// so we can suggest that array includes only one local minimum
int local_minimum_ternary(const vector<int>& arr)
{
	if (arr.size() <= 1)
		return 0;
	if (arr[0] < arr[1])
		return 0;
	if (arr.back() < arr[arr.size() - 2])
		return arr.size() - 1;
	if (arr.size() == 3)
		return 1;

	size_t left = 0;
	size_t right = arr.size() - 1;
	int eps = 3;
	size_t a, b;

	while (right - left > eps)
	{
		a = left + (right - left) / 3;
		b = left + 2 * (right - left) / 3;
		if (arr[a] < arr[b])
			right = b;
		else
			left = a;
	}

	int min = left;
	for (size_t i = left + 1; i <= right; ++i)
		if (arr[i] < arr[min])
			min = i;

	return min;
}

// O(n^2), greedy
int n_swaps(const vector<int>& a)
{
	vector<int> arr = vector<int>(a);
	int swaps = 0;
	int temp;
	int cur_max;
	size_t end = arr.size() - 1;
	size_t begin = 0;
	size_t size = arr.size();
	size_t i;

	while (size > 2)
	{
		// search maximum
		i = begin;
		temp = i;
		cur_max = arr[begin];
		for (; i < end; ++i)
		{
			if (arr[i] > cur_max)
			{
				cur_max = arr[i];
				temp = i;
			}
		}
		i = temp;
		// going to the closest end 
		if (i - begin < size / 2)
		{
			while (i > begin)
			{
				temp = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				--i;
				++swaps;
			}
			// changing borders
			++begin;
			--size;
		}
		else
		{
			while (i < end)
			{
				temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				++i;
				++swaps;
			}
			// changing borders
			--end;
			--size;
		}
	}
	return swaps;
}