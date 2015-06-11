#include "sortings.h";
#include "string";
#include "fstream";

void read_from_file(int a[]);
/*
Name + Surname: Ivan Perevoshchikov
Group: 202(2)SE
Date: 03.10.2014
Task: Insertion sorts
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
		1) read data from file "test_proekt_3.txt" (which should be located in the same directory with source files);
			test_proekt_3.txt file format:
				NT //first line - number of tests
                                   // then NT times
				Ni //number of elements in i test' array   
				X1 X2 X3 ... XM //Ni elements of the array

		2) you need to output to console:
			array before sorting
			array after sorting
			result of is_sort method to sorted array

		3) check out some issues in LMS which might be not mentioned here.

		P.S.: if (IDE != Visual Studio 2010) {
					check_if_it_works_in_studio_10();
			  }
	*/
	setlocale(LC_ALL,"Russian");	
	int *a;
	string choice;
	cout << "Для загрузки массива из файла введие \"load\"\nДля генерации вручную введите \"input\"\n";
	cin >> choice;
	if (choice == "load")
	{
		int lenght, numofarr;
		fstream myfile;
		myfile.open("test_proekt_3.txt", ios::in);
		myfile.seekg(0, ios::beg);
		while (!myfile.eof())
		{
			myfile >> numofarr;
			for (int j = 0; j < numofarr; j++)
			{
				myfile >> lenght;				
				int *acopy = new int[lenght];
				a = new int[lenght];
				for (int i = 0; i < lenght; i++)
				{
					myfile >> a[i];
					acopy[i] = a[i];
				}
				cout << "array before:" << endl;
				results(a, lenght);
				insertion_sort(a, lenght);
				cout << "after insertion sort:" << endl;
				results(a, lenght);
				cout << endl;
	
				cout << "array before:" << endl;
				results(acopy, lenght);
				binary_sort(acopy, lenght);
				cout << "after binary sort:" << endl;
				results(acopy, lenght);
				cout << endl;
			}
		}

	myfile.close();
		delete [] a;
	}
    if (choice == "input")
	{
		int n, max, min;
		cout << "Введите длину массива: ";
		cin >> n;
		a = new int[n];
		cout << "Введите максимальное значение: ";
		cin >> max;
		cout << "Введите минимальное значение: ";
		cin >> min;

		array_generation(a, n, min, max);
		cout << "array before:" << endl;
		results(a, n);
		insertion_sort(a, n);
		cout << "after insertion sort:" << endl;
		results(a,n);
		cout << endl;
	
		array_generation(a, n, min, max);
		cout << "array before:" << endl;
		results(a, n);
		binary_sort(a, n);
		cout << "after binary sort:" << endl;
		results(a, n);
		cout << endl;
		delete [] a;
	}
	if (choice != "load" && choice != "input")
		cout << "Неверный ввод";


	system("pause");
}