#pragma once
#include "AVLTree.h"
#include <string>
#include <fstream>
#include <set>

using namespace std;

class MySpellChecker
{
public:

	MySpellChecker()
	{
		dictionary = new AVLTree <string, less<string>>;
		words = new AVLTree <string, less<string>> ;
	}

	~MySpellChecker()
	{
		delete dictionary;
		delete words;
	}

	// чтение слов , содержащихся в словаре и построение AVL-дерева
	// с n узлами, где n - число слов в словаре
	void readDictionaryFile();

	// возвращает значение true, если построенное дерево является AVL-деревом,
	// в противном случае возвращается значение false
	bool isAVLTree();

	// получение(формирование) списка слов
	// возвращает false, если файл  открыть не удалось
	bool readDocumentFile(string fileName);

	// каждое слово документа, не обнаруженное в словаре, выводится на печать(экран)
	void compare();

private:
	AVLTree<string, less<string>>* dictionary;
	AVLTree<string, less<string>>* words;

	string alphabet = "abcdefghijklmnopqrstuvwxyz";

	set<string> suggestions(string s);

	void transposing(set<string>& suggestions, string s);

	void removal(set<string>& suggestions, string s);

	void replacement(set<string>& suggestions, string s);

	void inserting(set<string>& suggestions, string s);

	void lower(string& s);

	string strip_punct(const string& s);
};
