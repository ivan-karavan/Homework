#include "sortings.h";
#include <string>;
#include <fstream>;

void use_sortings(int a[], int n, int min, int max);


/*
Name + Surname: Perevoshchikov Ivan
Group: 202(2)SE
Date: 12.10.2014
Task: Line sorts
IDE: Microsoft Visual Studio 2010
*/

void main() {                                  
	//TODO: make console application, use methods in sortings file
	/*
		Note: you can add your own methods and #include's in sortings, 
		but you still need to use given methods
	*/
	/*
		Write your console application here, you need to implement next features:
		
     1) read data from file "test_proekt4.txt" (which should be located in the same directory with source files);
			test_proekt4.txt file format:
				NT //first line - number of tests
                        //then NT times
				Ni //number of elements in i test' array
				X0 X1 X2 ... X(Ni-1) //Ni elements of the array
     
		2) you need to output to console:
			array before sorting
			array after sorting
			result of is_sort method to sorted array
     
		3) check out some issues in LMS which might be not mentioned here.
     
		P.S.: if (IDE != Visual Studio 2010) {
					check_if_it_works_in_studio_10();
			  }
	*/
	setlocale(LC_ALL, "Russian");
	int *a;
	string exit, choice;
	int n;//длина сортируемого массива
	int max, min;
	do{
		cout << "Для загрузки массива из файла введие \"load\"\nДля генерации вручную введите \"input\"\n";
		cin >> choice;
		if (choice == "load")//читаем массивы из файла
		{
			int lenght, numofarr;
			fstream myfile;
			myfile.open("test_proekt_4.txt", ios::in);
			myfile.seekg(0, ios::beg);
			while (!myfile.eof())
			{
				myfile >> numofarr;
				for (int j = 0; j < numofarr; j++)
				{
					myfile >> lenght;				
					int *acopy = new int[lenght];
					int *acopy1 = new int[lenght];
					a = new int[lenght];
					for (int i = 0; i < lenght; i++)
					{
						myfile >> a[i];
						acopy[i] = a[i];
						acopy1[i] = a[i];
					}
					
					//выполняем сортировки
					results(a, lenght);
					counting_sort(a, lenght);
					cout << "counting sort" << endl;
					results(a, lenght);
					cout << endl;
	
					results(acopy, lenght);
					radix_sort10(acopy, lenght);
					cout << "radix sort10" << endl;
					results(acopy, lenght);
					cout << endl;

					results(acopy1, lenght);
					radix_sort256(acopy1, lenght);
					cout << "radix sort256" << endl;
					results(acopy1, lenght);
					cout << endl;
					cout << "------------------------" << endl;
				}
			}

			myfile.close();
			delete [] a;
		}
		if (choice == "input")//вводим вручную
		{
			do{
			cout << "Введите длину массива(не более, чем 65535): ";
			cin >> n;
			}while(n > 65535);
			cout << "Введите максимальное значение элементов: ";
			cin >> max;
			do{
			cout << "Введите минимальное значение элементов(не меньше 0): ";
			cin >> min;
			}while(min < 0);
			a = new int[n];

			use_sortings(a, n, min, max);
		}
		cout << "Для выхода введите \"end\"." << endl;
		cin >> exit;
	}while(exit != "end");

	system("pause");
}

void use_sortings(int a[], int n, int min, int max)
{
	array_generation(a, n, min, max);
	results(a, n);
	cout << "counting sort" << endl;
	counting_sort(a, n);
	results(a, n);

	cout << endl;

	array_generation(a, n, min, max);
	results(a, n);
	cout << "radix sort10" << endl;
	radix_sort10(a, n);
	results(a, n);

	cout << endl;

	array_generation(a, n, min, max);
	results(a, n);
	cout << "radix sort256" << endl;
	radix_sort256(a, n);
	results(a, n);

	cout << endl;
	delete[] a;
}
