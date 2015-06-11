#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <cctype>

#include "dictionary.h"

using namespace std;

void lower(string& s);
string strip_punct(const string& s);
void check_spelling(ifstream& in, Dictionary& dict);


int main(int argc, char* argv[]) {

	// Output usage message if improper command line args were given.
	if (argc != 3) {
		cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
		return EXIT_FAILURE;
	}

	ifstream inf(argv[2]);
	if (! inf) {
		cerr << "Could not open " << argv[2] << "\n";
		return EXIT_FAILURE;
	}

	// Read dictionary, but let user know what we are working on.
	cout << "Loading dictionary, this may take awhile...\n";

	Dictionary d(argv[1]);

	check_spelling(inf, d);

	inf.close();

	return EXIT_SUCCESS;
}

void check_spelling(ifstream& in, Dictionary& dict) {

	int line_number = 0;

	while (in) {

		line_number++;

		string line;
		getline(in, line);

  	    stringstream ss (stringstream::in | stringstream::out);
		ss << line;

		string word;
		while (ss >> word) {
			
            // TODO: Complete the spell check of each word
			word = strip_punct(word);
			lower(word);
			if (!dict.search(word)){
				cout << "line " << line_number << ": \'" << word << "\'\n";
				set<string> suggestions = dict.suggestions(word);
				if (suggestions.size() == 0)
				{
					cout << "\tno suggestions\n";
				}
				else
				{
					cout << "\tsuggestions:\n";
					for (set<string>::iterator suggestion = suggestions.begin(); suggestion != suggestions.end(); ++suggestion)
					{
						cout << "\t\t" << *suggestion << "\n";
					}
				}
			}
			// end TODO
		}

	}

}

void lower(string& s) {

    // Ensures that a word is lowercase
	for (int i = 0; i < s.length(); i++) {
		s[i] = tolower(s[i]);
	}
}

string strip_punct(const string& s) {

	// Remove any single trailing
	// punctuation character from a word.  
	if (ispunct(s[s.length() - 1]) ) {
		return s.substr (0, s.length() - 1);
	}
	else {
		return s;
	}
}
