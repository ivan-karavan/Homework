#include "sortings.h";
#include <string>;
#include <fstream>;

/*
Name + Surname: Perevoshchikov Ivan
Group: 202(2)SE
Date: 24.10.2014
Task: Heap sort
IDE: Microsoft Visual Studio 2010
*/

void program();
void use_sorting(int a[], int lenght);
void load_or_write();
void clear_file(string file_name);

void main() {
	//TODO: make console application, use methods in sortings file
	/*
		Note: you can add your own methods and #include's in sortings, 
		but you still need to use given methods
        DON'T CHANGE HEADER FILE
	*/
	/*
		Write your console application here, you need to implement next features:
		1) read data from file "test_proekt_6.txt" (which should be located in the same directory with source files);
			test_proekt_6.txt file format:
				NT //first line - number of tests
                                   // then NT times
				Ni //number of elements in i test' array   
				X1 X2 X3 ... XM //Ni elements of the array

		2) you need to output to console and to file output_proekt_6.txt:
			array before sorting
			array after sorting
			result of is_sort method to sorted array

		3) check out some issues in LMS which might be not mentioned here.

		P.S.: if (IDE != Visual Studio 2010) {
					check_if_it_works_in_studio_10();
			  }
	*/
	program();
}

void program()
{
	setlocale(LC_ALL, "Russian");
	string exit;
	clear_file("output_proekt_6.txt");//очистка файла перед использованием
	do 
	{
		//methods		
		load_or_write();
		cout << "Для выхода введите \"end\"." << endl;
		cin >> exit;
	}while(exit != "end");
	
	system("pause");
}

void load_arr()//загружаем массивы из файла
{
	int lenght, numofarr;			
	fstream myfile;			
	myfile.open("test_proekt_6.txt", ios::in);
	myfile.seekg(0, ios::beg);
	while (!myfile.eof())
	{
		myfile >> numofarr;
		for (int j = 0; j < numofarr; j++)//количество тестов
		{
			myfile >> lenght;
			int *a = new int[lenght];
			for (int i = 0; i < lenght; i++)
				myfile >> a[i];
			use_sorting(a, lenght);
			cout << endl;
		}
	}
	fstream.close();
}

void writed_arr()//если вводим вручную
{
	int lenght, min, max;
	cout << "Введите длину массива: ";
	cin >> lenght;
	cout << "Введите максимальное значение элементов: ";
	cin >> max;
	cout << "Введите минимальное значение элементов: ";
	cin >> min;
	int *a = new int[lenght];
	array_generation(a, lenght, min, max);
	use_sorting(a, lenght);
	cout << endl;
}

void load_or_write()
{
	string choice;
	cout << "Для загрузки массива из файла введие \"load\"\nДля генерации вручную введите \"write\"\n";
		cin >> choice;
	if (choice == "load")
		load_arr();
	if (choice == "write")
		writed_arr();
	if (choice != "load" && choice != "write")
		cout << "Неверный ввод\n";
}

void clear_file(string file_name)
{
	fstream(file_name, fstream::out);
}

void save_results(int a[], int lenght)
{
	ofstream fOut;
	fOut.open("output_proekt_6.txt", ios::app);
	
	for (int i = 0; i < lenght; i++)
		fOut << a[i] << " ";
	fOut << "\n";
	
	fOut.close();
}

void use_sorting(int a[], int lenght)
{
	results(a, lenght);
	save_results(a, lenght);//сохраняем исходный массив в файле
	cout << "\nheap sort" << endl;
	heap_sort(a, lenght);
	results(a, lenght);//вывод на экран
	//сохранение в файл
	save_results(a, lenght);//сохраняем отсортированный массив
	delete [] a;
}
