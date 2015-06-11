/*
student: Perevoshchikov Ivan
group: 202SE
IDE: Visual Studio 2013
*/

#include "AVLTree.h"
#include <string>
#include "MySpellChecker.h"

using namespace std;


class StringComparator
{
public:
	StringComparator(){}

	int operator()(std::string& a, std::string& b){
		return a.compare(b);
	}
};

class Comparator
{
public:
	Comparator() {}

	int operator() (int a, int b) {
		if (a == b)
			return 0;
		if (a > b)
			return 1;
		else
			return -1;
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");

	string fileName;
	MySpellChecker* spell_cheker = new MySpellChecker();
	cout << "Reading Dictionary file, please wait\n";
	spell_cheker->readDictionaryFile();
	cout << "Write name of file to read:\n";
	cin >> fileName;
	while (!spell_cheker->readDocumentFile(fileName))
	{
		cin >> fileName;
	}
	if (spell_cheker->isAVLTree())
	{
		cout << "Builded trees are AVLTree\n";
	}
	spell_cheker->compare();

	system("pause");
	delete spell_cheker;

	return 0;
}