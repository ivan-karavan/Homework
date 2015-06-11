#include <iostream>
#include <string>
using namespace std;

/*
Name + Surname: Perevoshchikov Ivan
Group: 202(2)SE
Date: 03.11.2014
Task: 9_1
IDE: Microsoft Visual Studio 2010
*/

int allSubStrings(string str, int n, string sub, int m, int* pos);
string largestBorder (string str, int n);
string* allBorders(string str, int n);
int* vse_grany_1(string str);

//int main()
//{
//	string exit;
//	setlocale(LC_ALL, "Russian");
//
//	do 
//	{
//		string str;
//		cout << "Введите строку" << endl;
//		cin >> str;
//		int n = str.length();
//		int* br = vse_grany_1(str);
//		for (int i = 0; i < n; i++)
//			cout << br[i] << " ";
//		cout << endl;
//
//		cout << "Для выхода введите \"end\"." << endl;
//		cin >> exit;
//	}
//	while(exit != "end");
//	system("pause");
//	return 0;
//}

// 1 задание
int allSubStrings(string str, int n, string sub, int m, int* pos )
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (str[i] == sub[0]) // если текущий элемент строки совпадает с началом искомой подстроки, то заходим внутрь
			for (int k = 1; k < m; k++) // проходим по всем остальным элементам подстроки
			{
				if ((k != m-1) &&(str[i+k] == sub[k])) // если этот элемент не последний в подстроке и он совпадает, то продолжим сравнения
					continue;
				else
					if ((k == m-1) && (str[i+k] == sub[k])) // если это последний элемент подстроки и он совпадает
					{
						pos[count] = i; // то это и будет одной из подстрок
						count++;
					}
					else 
						break; // прерываем сравнение, если элементы строки и подстроки не совпадают
			}
	}
	return count;
}

// 2 задание
string largestBorder (string str, int n)
{
	int pos = 0;
	for (int i = 0; i < n-1; i++) // идём до предпоследнего элемента
	{
		for (int j = 0; j <= i; j++) // проверяем i элементов с конца
		{
			if ((j != i) && (str[j] == str[n-1-i+j])) // если не последний элемент префикса и элементы совпадают, продолжаем сравнивать
				continue;
			else
				if ((j == i) && (str[j] == str[n-1-i+j])) // если последние элементы суффикса и префикса совпадают, то нашли грань длиной i
				{
					pos = i;
				}
				else
					break; // выходим, если что-то не совпадает
		}
	}
	return str.substr(0, pos + 1);
}

// 3 задание
string* allBorders(string str, int n)
{
	string* borders = new string[n];

	for (int i = 0; i < n; i++)
		borders[i] = "";
	for (int k = 1; k <= n; k++) // для всех длин находим наибольшую границу
	{
		borders[k-1] = largestBorder(str, k);
	}

	return borders;
}

int* vse_grany_1(string str)
{
	int* length = new int[str.length()];
	length[0] = 0;

	if(str.length() > 1)
		length[1] = 0;

	for(int i = 0; i < str.length() - 1;i++)
	{
		if (str[i + 1] == str[length[i]])
			length[i + 1] = length[i] + 1;
		else {
			int t = i;
			while (t > 0)
			{
				if (length[t] != 0 && str[length[length[t] - 1]] == str[i + 1])
				{
					length[i + 1] = length[length[t] - 1] + 1;
					break;
				}
				else 
				{
					if (length[t] != 0)
						t = length[t] - 1;
					else
						t = 0;
					if (t == 0)
						length[i + 1] = 0;
				}
			}
		}
	}
	return length;
}