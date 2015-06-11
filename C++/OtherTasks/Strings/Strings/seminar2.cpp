#include <iostream>
#include <string>
#include <vector>

/*
Name + Surname: Perevoshchikov Ivan
Group: 202(2)SE
Date: 12.12.2014
Task: 10_1
IDE: Microsoft Visual Studio 2010
*/

using namespace std;

// задание 5
vector<int> substrings(string str, string sub)
{
	string str1 = sub + '$' + str;

	vector<int> result;

	int* length = new int[str1.length()];
	length[0] = 0;
	if (str1.length() > 1)
		length[1] = 0;
	for (int i = 0; i < str1.length() - 1; i++)
	{
		if (str1[i + 1] == str1[length[i]])
			length[i + 1] = length[i] + 1;
		else
		{
			int t = i;
			while(t > 0)
			{
				if (length[t] !=0 && str1[length[length[t] - 1]] == str1[i + 1])
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
					if(t == 0)
						length[i + 1] = 0;
				}
			}
		}
		if (length[i] == sub.length()){
			result.push_back(i - sub.length() * 2);
		}
	}
	if (length[str.length() - 1] == sub.length()){
		result.push_back(str1.length() - 1 - sub.length()*2);
	}
	delete [] length;

	return result;
}

// задание 6.1
int comparison(string str, int sub1, int sub2)
{
	int longer;
	if (sub1 > sub2)
		longer = str.length() - sub1;
	else
		longer = str.length() - sub2;
	int i = 0;
	while ((i < longer) && (str[sub1] == str[sub2]))
	{
		i++;
		sub1++;
		sub2++;
	}
	return i;
}

// задание 6.2
vector<int> allBlocs(string str)
{
	int lenght = str.length();
	vector<int> blocs;
	blocs.push_back(0);
	for (int i = 1; i < lenght; i++)
	{
		blocs.push_back(comparison(str, 0, i));
	}
	return blocs;
}

// задание 8
vector<int> subSearch(string str, string sub)
{
	string str1 = sub + "$" + str;
	vector<int> blocs = allBlocs(str1);
	int lengSub = sub.length();
	vector<int> allSubs;
	for (int i = sub.length(); i < blocs.size(); i++)
	{
		if (blocs[i] == sub.length())
		{
			allSubs.push_back(i - sub.length() - 1);
		}
	}

	return allSubs;
}

//int main()
//{
//	do {
//		string exit;
//		cout << "Write \"exit\" for end" << endl;
//		cin >> exit;
//	}
//	while(exit != "exit");
//	system("pause");
//	return 0;
//}