#include "MySpellChecker.h"
#include <set>



void MySpellChecker::readDictionaryFile()
{
	string word;
	fstream myfile;
	myfile.open("wordlist.txt", ios::in);
	myfile.seekg(0, ios::beg);
	while (myfile >> word)
	{
		dictionary->insert(word);
	}
	myfile.close();
}

bool MySpellChecker::isAVLTree()
{
	return dictionary->isAVLTree() && words->isAVLTree();
}

bool MySpellChecker::readDocumentFile(string fileName)
{
	string word;
	fstream myfile;
	myfile.open(fileName, ios::in);
	if (myfile) 
	{
		myfile.seekg(0, ios::beg);
		while (myfile >> word)
		{
			lower(word);
			word = strip_punct(word);
			words->insert(word);
		}
		myfile.close();
		return true;
	} 
	else
	{
		cout << "Name of file is incorrect, try again\n";
		return false;
	}
}

void MySpellChecker::compare()
{
	AVLTree<string, less<string>>::Iterator* iterator = words->iterator();
	AVLTree<string, less<string>>::Node* next_node = iterator->next();
	cout << "Possibly incorrect words:\n";
	while (next_node)
	{
		if (!dictionary->exists(next_node->key))
		{
			cout << next_node->key << endl;
			set<string> suggests = suggestions(next_node->key);
			if (suggests.size() == 0)
			{
				cout << "\tno suggestions\n";
			}
			else
			{
				cout << "\tsuggestions:\n";
				for (set<string>::iterator suggestion = suggests.begin(); suggestion != suggests.end(); ++suggestion)
				{
					cout << "\t\t" << *suggestion << "\n";
				}
			}
		}
		next_node = iterator->next();
	}
}

void MySpellChecker::lower(string& s) 
{
	for (size_t i = 0; i < s.length(); i++) 
	{
		s[i] = tolower(s[i]);
	}
}

string MySpellChecker::strip_punct(const string& s) 
{
	string a = s;
	while (ispunct(a[a.length() - 1]))
	{
		a = a.substr(0, a.length() - 1);
	}
	return a;
}

set<string> MySpellChecker::suggestions(string s)
{
	set<string> suggests;
	transposing(suggests, s);
	removal(suggests, s);
	replacement(suggests, s);
	inserting(suggests, s);
	return suggests;
}

void MySpellChecker::transposing(set<string>& suggestions, string s)
{
	string attempt;
	for (size_t i = 1; i < s.size(); i++)
	{
		attempt = s;
		swap(attempt[i - 1], attempt[i]);
		if (dictionary->exists(attempt))
		{
			suggestions.insert(attempt);
		}
	}
}

void MySpellChecker::removal(set<string>& suggestions, string s)
{
	string attempt;
	for (size_t i = 0; i < s.size() - 1; ++i)
	{
		attempt = s;
		attempt.erase(i, 1);
		if (dictionary->exists(attempt))
		{
			suggestions.insert(attempt);
		}
	}
}

void MySpellChecker::replacement(set<string>& suggestions, string s)
{
	string attempt;
	for (size_t i = 0; i < s.size(); i++)
	{
		for (string::iterator letter = alphabet.begin(); letter != alphabet.end(); ++letter) 
		{
			attempt = s;
			attempt[i] = *letter;
			if (dictionary->exists(attempt))
			{
				suggestions.insert(attempt);
			}
		}
	}
}

void MySpellChecker::inserting(set<string>& suggestions, string s)
{
	string attempt;
	for (size_t i = 0; i < s.size(); i++)
	{
		for (string::iterator letter = alphabet.begin(); letter != alphabet.end(); ++letter) 
		{
			attempt = s;
			attempt.insert(i, 1, *letter);
			if (dictionary->exists(attempt))
			{
				suggestions.insert(attempt);
			}
		}
	}
}