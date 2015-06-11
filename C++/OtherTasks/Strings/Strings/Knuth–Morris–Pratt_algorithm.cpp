#include <iostream>
#include <string>
#include <vector>

using namespace std;
int* allBorders(string str);

// KnuthЦMorrisЦPratt_algorithm
vector<int> KMP(string str, string sub/*, int* br, vector<int> priklad, vector<int> sravn*/)
{
	int* br = allBorders(sub);
	vector<int> substrings;

	int curEl;
	int shift; // сдвиг
	int i = 0;
	int j = 0;
	//for (int i = 0; i < str.length() - sub.length() + 1; i++) 

	while (i < str.length() - sub.length() + 1) { // идЄм до такого элемента строки, что длина суффикса строки >= длины подстроки
		//if (str[i] != sub[j]) { // если первые провер€емые элементы не совпадают, то идЄм по строке дальше
		//	//++i;
		//	j = 0;
		//}
		//else {
			curEl = i;

			//if (str[i] == sub[j]) {
			//do { // идЄм, пока не остановимс€ на несовпадающем элементе
			//	++j;
			//	++i;
			//} while (str[i] == sub[j] && j < sub.length() - 1);
			//}

			while (str[i] == sub[j] && j < sub.length()) // идЄм, пока не остановимс€ на несовпадающем элементе
			{
				++i;
				++j;
				if (j == sub.length())
					break;
			}

			// остановились на j-ом элементе
			if (j == sub.length()) { 
				substrings.push_back(curEl); // успешно достигли конца подстроки - записываем в результат
			}
			shift = j - br[j - 1]; // сдвигаем подстроку на эту величину
			// и начинЄм сравнение с br[j]-ого элемента подстроки
			//++i;//i = curEl + shift;
			j = j - shift;//j = br[j]; // j = shift - 1
		//}
	}
	delete [] br;
	return substrings;
}

int* allBorders(string str)
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


int main()
{
	string exit;
	setlocale(LC_ALL, "Russian");

	do 
	{
		string str, sub;
		cout << "¬ведите строку" << endl;
		cin >> str;
		cout << "¬ведите искомую подстроку строку" << endl;
		cin >> sub;

		vector<int> prikl, sravn;
		//int* br;
		vector<int> subs = KMP(str, sub/*,br,prikl,sravn*/);
		//// 1
		//for (int i = 0; i < sub.length(); i++)
		//	cout << sub[i] << " ";
		//cout << endl;
		//// 2
		//for (int i = 0; i < prikl.size(); i++)
		//	cout << prikl[i] << " ";
		//cout << endl;
		//// 3
		//for (int i = 0; i < sravn.size(); i++)
		//	cout << sravn[i] << " ";
		//cout << endl;
		// 4
		for (int i = 0; i < subs.size(); i++)
			cout << subs[i] << " ";
		cout << endl;

		//delete br;
		cout << "ƒл€ выхода введите \"end\"." << endl;
		cin >> exit;
	}while(exit != "end");

	system("pause");
	return 0;
}