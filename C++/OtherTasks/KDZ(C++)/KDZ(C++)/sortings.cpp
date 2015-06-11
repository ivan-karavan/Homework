#include "sortings.h"

// 1)пузырёк
void bubble_sort(int a[], int n)
{
	int P;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < (n - 1 - i); j++)
			if (a[j] > a[j + 1])
			{
				P = a[j];
				a[j] = a[j+1];
				a[j+1] = P;
			}
	}
}

// 2)пузырёк айверсон 1
void bubble_iverson_1(int a[], int n) 
{
	int P;
	bool T = false;
	for (int i = 0; i < (n - 1) && !T; i++)
	{
		if (T!=true)
		{
			T = true;
			for (int j = 0; j < (n - 1 - i); j++)
				if (a[j] > a[j + 1])
				{
					P = a[j];
					a[j] = a[j+1];
					a[j+1] = P;
					T = false;
				}
		}
	}
}

// 3)пузырёк айверсон 2
void bubble_iverson_2(int a[], int n) 
{
	int f,t = 0,bound = n-1;
	for(int i = 0;i < n;i++)
	{
		t = 0;
		for(int j = 0;j < bound;j++)
		{
			if(a[j] > a[j+1])
			{
				f = a[j];
				a[j] = a[j+1];
				a[j+1] = f;
				t = j;
			}
		}
		if(t == 0)
			break;
		else
			bound = t;
	}
}

// 4)простыми вставками
void insertion_sort(int a[], int n) 
{
	int b, j;
	for (int i = 1; i < n; i++)
	{
		b = a[i];
		j = i-1;
		while (b < a[j] && j >= 0)
		{
			a[j+1] = a[j];
			j = j-1;
		}
		a[j+1] = b;
	}
}

// 5)бинарными вставками
void binary_sort(int a[], int n) 
{
	int lf, rg, c;
	int k, p;
	for (int i = 1; i < n; i++)
	{
		lf = 0;
		rg = i - 1;
		c = (lf + rg) / 2;
		while (lf != c)
		{
			if (a[c] > a[i])
				rg = c-1;
			else 
				lf = c;
			c = (lf + rg)/2;
		}
		if (a[lf] < a[i])
		{
			if (a[i] > a[rg])
				lf = rg + 1;
			else
				lf = rg;
		}
		k = i;
		p = a[i];
		while (k > lf)
		{
			a[k] = a[k-1];
			k = k-1;
		}
		a[lf] = p;
	}
	
}

// 6)подсчётом
int max_search(int a[], int n)//поиск максимума в массиве
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}
void counting_sort(int a[], int n) 
{
	int max = max_search(a, n); //поиск максимума - длины массива с

	int *b = new int[n];
	for (int i = 0; i < n; i++)//инициализация массива нулями
		b[i] = 0;

	int *c = new int[max + 1];
	for (int i = 0; i <= max; i++)//инициализация массива нулями
		c[i] = 0;

	for (int i = 0; i < n; i++)//подсчёт количества элементов a[i]-ых
		c[a[i]] = c[a[i]] + 1;

	for (int j = 1; j <= max; j++)//для устойчивости
		c[j] = c[j] + c[j - 1];

	for (int i = n - 1; i >= 0; i--)//записываем числа a[i] в b на свои места
	{
		b[c[a[i]]-1] = a[i];
		c[a[i]] = c[a[i]] - 1;
	}

	for (int i = 0; i < n; i++)
		a[i] = b[i];

	delete [] b;
	delete [] c;
}

// 7)цифровая (256 СС)
union rad256
{
	int num;
	unsigned char chars[4];
};
void radix_sort256(int a[], int n) 
{
		rad256 *un_arr = new rad256[n];          
 
        for (int i = 0; i < n; i++)//записываем в каждый юнион значение элементов массива
			un_arr[i].num = a[i];
 
        for(int i = 0; i < 4; i++) 
		{ 
			int *A = new int[n];//массив разрядов
			rad256 *b = new rad256[n];               
			int *c = new int[256];
                
			for (int j = 0; j < n; j++)//чары будут разрядами числа				
				A[j] = un_arr[j].chars[i];
                
			for (int j = 0; j < 256; j++)//инициализация массива с нулями				
				c[j] = 0;
                
			for (int j = 0; j < n; j++)//заполняем массив с		
				c[A[j]] = c[A[j]] + 1;
              
			for (int j = 1; j < 256; j++)//для устойчивости
				c[j] = c[j] + c[j - 1];
              
			for (int j = n - 1; j >= 0; j--)
                {                        
					b[c[A[j]] - 1] = un_arr[j];                        
					c[A[j]] = c[A[j]] - 1;
                }
                
			for (int j = 0; j < n; j++)					
				un_arr[j] = b[j];
               
			delete [] A;              
			delete [] b;               
			delete [] c;
        }
 
        for (int i = 0; i < n; i++)
			a[i] = un_arr[i].num;

        delete [] un_arr;
}

// 8)слиянием
void merge(int a[],int l, int m, int r)
{
	int *b = new int[r+1];// сохраняем старое положение чисел в этом массиве
	for (int i = l; i <= r; i++)
		b[i] = a[i];
	int p1, p2;// позиции первого и второго отсортированного массива, которые мы сливаем
	p1 = l;
	p2 = m + 1;
	for (int curPos = l; curPos <= r; curPos++)
	{
		if ((p1 > m) || (p2 > r))
			if (p1 > m) //если первый массив кончился, записываем весь оставшийся второй
			{
				a[curPos] = b[p2];
				p2++;//продвигаемся по второму массиву
			}
			else//аналогично первый записываем, если второй кончился
			{
				a[curPos] = b[p1];
				p1++;
			}
		else //выбираем наименьшее на текущих позициях
			if (b[p1] > b[p2])
			{
				a[curPos] = b[p2];
				p2++;
			}
			else
			{
				a[curPos] = b[p1];
				p1++;
			}
	}
	delete [] b;
}
void divide_and_merge(int a[], int l, int r)
{
	if (l < r)
	{
		int m = (l + r) / 2; //правая граница левого массива и левая-1 правого массива
		divide_and_merge(a, l , m);
		divide_and_merge(a, m + 1, r);
		merge(a, l, m, r);
	}
}
void merge_sort(int a[], int n) 
{
	divide_and_merge(a, 0, n-1);
}

// 9) кучей
void heapify(int a[], int i, int heap_size)//поддержка основного свойства кучи а[parent(i)] >= a[i]
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int largest;
	if (l <= heap_size &&  a[l] > a[i])//проверяем левый лист
		largest = l;
	else
		largest = i;
	if (r <= heap_size && a[r] > a[largest])//проверяем правый лист
		largest = r;
	if (largest != i)//если наибольшее в рассматриваемом дереве не в вершине
	{
		swap(a[i], a[largest]);//то поднимаем наибольшее в вершину
		heapify(a, largest, heap_size);// и уходим вглубь
	}
}
void build_heap(int a[], int lenght)//построение кучи
{
	for (int i = lenght/2; i >=0; i--)//начиная с последнего родителя вызываем heapify
		heapify(a, i, lenght);
}
void heap_sort(int a[], int n) {
	//TODO: write your heap sort
	build_heap(a, n);//куча построена
	int heap_size = n - 1;
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heap_size = heap_size - 1;// уменьшаем на 1, тк последний элемент кучи уже отсортирован
		heapify(a, 0, heap_size);//в построенной куче поддерживаем её основное свойство
	}
}

// 10)быстрая со средним барьерным элементом
typedef int(*pivot_chooser) (int from, int to);/*
void recursive_call_qsort(int arr[], int from, int to, pivot_chooser pivot_chooser) 
{
	int i = from,
		j = to;
	int x = arr[pivot_chooser(from ,to)]; //опорный элемент

	do // пока i и j не пересеклись
	{
		while (arr[i] < x) i++; // идём до элемента не из левой группы (больше разделительного)
		while (arr[j] > x) j--; // идём, пока не встретим элемент меньше разделительного

		if (i <= j)
		{
			if (arr[i] > arr[j]) // строгое для устойчивости
				swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (from < j) // рекурсивный вызов для левой части массива
	{
		recursive_call_qsort(arr, from, j, pivot_chooser);
	}
	if (to > i) // рекурсивный вызов для правой части массива
	{
		recursive_call_qsort(arr, i, to, pivot_chooser);
	}
}
int get_middle_pivot(int from, int to) 
{
	return (from + to) / 2;
}
void quick_sort_middle(int arr[], int n) 
{
	recursive_call_qsort(arr, 0, n - 1, get_middle_pivot);
}
*/
#pragma region qsort
int recompute_with_pivot(int* arr, int from, int to, int pivot_pos);
void recursive_call_qsort(int* arr, int from, int to, pivot_chooser pivot_chooser);
int get_last_pivot(int from, int to) ;
int get_middle_pivot(int from, int to) ;
void quicksort_middle(int* arr, int n) 
{
	recursive_call_qsort(arr, 0, n - 1, get_middle_pivot); 
}

// Quicksort with last element in array as pivot
void quicksort_last(int* arr, int n)
{
recursive_call_qsort(arr, 0, n - 1, get_last_pivot); 
}

// Getting position of middle pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int get_middle_pivot(int from, int to) 
{
return (from + to) / 2;
}

// Getting position of last pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)
int get_last_pivot(int from, int to) 
{
return to;
}

// Getting position of random pivot in array in the current bounds
//
// Additional space: O(1)
// Complexity: O(1)


// Rearranges values in the array using pivot in the current bounds
//
// Additional space: O(1)
// Complexity: O(n)
// RETURNS: new position of the pivot in the array.
int recompute_with_pivot(int* arr, int from, int to, int pivot_pos) {
int pred ;
pred = from - 1;
int pivByPS ;
pivByPS= arr[pivot_pos];//element in arr by pivot_pos position
int flag;//change arr[to] and arr[pivot_pos]
flag=arr[to];//change arr[to] and arr[pivot_pos]
arr[to]=arr[pivot_pos];//change arr[to] and arr[pivot_pos]
arr[pivot_pos]=flag;//change arr[to] and arr[pivot_pos]
for (int i = from; i <= to - 1; i++) 
{
if(pivByPS >= arr[i])
{
++pred;
flag=arr[i];//change arr[i] and arr[pred]
arr[i]= arr[pred];//change arr[i] and arr[pred]
arr[pred]=flag;//change arr[i] and arr[pred]
}
}
flag=arr[to];//change arr[to] and arr[pred + 1];
arr[to]=arr[pred + 1];//change arr[to] and arr[pred + 1];
arr[pred + 1]=flag;//change arr[to] and arr[pred + 1];
return ++pred;
}
// Recursive call for qsort that sorts the array
// in the current bounds
//
// Additional space: O(1)
// Complexity: O(n*log(n)) - srArifm. O(n*n) - the worst case.
void recursive_call_qsort(int* arr, int from, int to, pivot_chooser pivot_chooser) {
//++depth;//increase current depth
if (to <= from) 
{
} 
else
{ 
int nextPivosPosition ;//pivos
nextPivosPosition = recompute_with_pivot(arr, from, to, pivot_chooser(from, to));//pivos
if((nextPivosPosition - 1)<=from && to<=(nextPivosPosition +1)){
//++leaves;//increase leaves
//if (mDepth<depth) //compare maximum depth with current 
//{
// mDepth=depth;//if depth more than max depth,change their
//}
}else{
recursive_call_qsort(arr, from, nextPivosPosition - 1, pivot_chooser);//recursion
recursive_call_qsort(arr, nextPivosPosition + 1, to, pivot_chooser);//recursion
}
}
//--depth;//decrease depth
//if(depth==0) //see whether it is the end
//{
// depth=mDepth;//if yes make depth equals maximum depth
//}
}
#pragma endregion


/*
// 11)быстрая с последним барьерным элементом
int get_last_pivot(int from, int to) 
{
	return to;
}
void quick_sort_last(int arr[], int n) 
{
	recursive_call_qsort(arr, 0, n - 1, get_last_pivot);
}*/

// 12)Шелла
int increment(int inc[], int n) {
// inc[] массив, в который заносятся инкременты
// size размерность этого массива
 int p1, p2, p3, s;
 
  p1 = p2 = p3 = 1;
  s = -1;
  do {// заполняем массив элементов по формуле Роберта Седжвика
    if (++s % 2) {
      inc[s] = 8*p1 - 6*p2 + 1;
    } else {
      inc[s] = 9*p1 - 9*p3 + 1;
      p2 *= 2;
      p3 *= 2;
    }
	p1 *= 2;
// заполняем массив, пока текущая инкремента хотя бы в 3 раза меньше количества элементов в массиве
  } while(3*inc[s] < n);
 
  return s > 0 ? --s : 0;// возвращаем количество элементов в массиве
}
void shell_sort(int a[], int n)
{
	// inc инкремент, расстояние между элементами сравнения
// i и j стандартные переменные цикла
// seq[40] массив, в котором хранятся инкременты
  int inc, i, j, seq[40];
  int s;//количество элементов в массиве seq[40]
 
  // вычисление последовательности приращений
  s = increment(seq, n);
  while (s >= 0) {
	//извлекаем из массива очередную инкременту
	inc = seq[s--];
// сортировка вставками с инкрементами inc
    for (i = inc; i < n; i++) {
      int temp = a[i];
// сдвигаем элементы до тех пор, пока не дойдем до конца или не упорядочим в нужном порядке
      for (j = i-inc; (j >= 0) && (a[j] > temp); j -= inc)
        a[j+inc] = a[j];
// после всех сдвигов ставим на место j+inc элемент, который находился на i месте
      a[j+inc] = temp;
    }
  }
}