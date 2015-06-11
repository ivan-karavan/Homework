#ifndef  _DICTIONARY_H_ 
#define  _DICTIONARY_H_

#include  <iostream>
#include  <vector>
#include  <list>
#include  <algorithm>
#include  <string>
#include  <set>

#include  "hashset.h"
#include  "hashset.cpp"

using namespace std;

class hash_function
{
public:
    hash_function() {}

    unsigned int operator()( const string& s )  const {
		
        // Complete definition

    }
};

class equality
{
public:
    equality() {}
    bool  operator()( const string& A, const string& B )  const {
		return  (A == B);
    }
};

class Dictionary: public HashSet<string, hash_function, equality> {
	// TODO
public:
	Dictionary(string word_list){
		ifstream inf(word_list);
		string current_string;
		while (inf)
		{
			string s;
			getline(inf, s);
			insert(s);
		}
		inf.close();
	}

	set<string> suggestions(string s){
		set<string> suggs;
		transposing(suggs, s);
		removal(suggs, s);
		replacement(suggs, s);
		inserting(suggs, s);
		return suggs;
	}

private:
	void transposing(set<string>& suggestions, string s){
		for (int i = 1; i < s.size(); i++)
		{
			string attempt = s;
			swap(attempt[i - 1], attempt[i]);
			if (search(attempt))
			{
				suggestions.insert(attempt);
			}
		}
	}

	void removal(set<string>& suggestions, string s){
		for (int i = 0; i < s.size() - 1; i++)
		{
			string attempt = s;
			attempt.erase(i, 1);
			if (search(attempt))
			{
				suggestions.insert(attempt);
			}
		}
	}

	void replacement(set<string>& suggestions, string s){
		string alphabet = "abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < s.size(); i++)
		{
			for (string::iterator letter = alphabet.begin(); letter != alphabet.end(); ++letter) {
				string attempt = s;
				attempt[i] = *letter;
				if (search(attempt))
				{
					suggestions.insert(attempt);
				}
			}
		}
	}

	void inserting(set<string>& suggestions, string s){
		string alphabet = "abcdefghijklmnopqrstuvwxyz";
		for (int i = 0; i < s.size(); i++)
		{
			for (string::iterator letter = alphabet.begin(); letter != alphabet.end(); ++letter) {
				string attempt = s;
				attempt.insert(i, 1, *letter);
				if (search(attempt))
				{
					suggestions.insert(attempt);
				}
			}
		}
	}
	// end TODO
};

#endif
