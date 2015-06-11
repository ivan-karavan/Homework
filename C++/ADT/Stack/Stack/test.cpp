#include <fstream>
#include <vector>
#include <iostream>
#include "bracket_sequence.h"

using namespace std;

int main(int argc, char *argv[]) {
	 //if (argc != 2) {
		// cout << "Invalid argument count " << argc;
		// return -1;
	 //}
	 //fstream fin(argv[1], fstream::in);
	 //string line;
	 //if (fin.good() && getline(fin,line)){
		// int perfix_size = 0;
		// if (find_sequence(line ,perfix_size)) cout << "CORRECT";
		// else if (perfix_size > 0) cout << perfix_size;
		// else cout << "INCORRECT";
	 //}
	 //else{
		// cout << "File not found";
	 //}
	 //fin.close();
	int len = 0;
	cout << find_sequence("[((a){()()[[]]}]", len) << endl;
	cout << len;

	system("pause");
	 return 0;
}
