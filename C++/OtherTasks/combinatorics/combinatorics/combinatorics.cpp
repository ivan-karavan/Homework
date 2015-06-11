#include "combinatorics.h"

/*
Name + Surname: Perevoshchikov Ivan
Group: 202(2)SE
Date: 19.12.2014
Task: Combinatorics
IDE: Microsoft Visual Studio 2010
*/
long combinatorics::numberOfPermutations(int n)
{
	long result = 1;
	if (n > 0) {
		result = 1;
		for (int i = 1; i <= n; i++) {
			result *= i;
		}
	}
	else {
		result = 0;
	}
	return result;
}

long combinatorics::numberOfVariations(int n, int k)
{
	long result = 1;
	if ((n == 0) || (k == 0) || (k > n)) {
		result = 0;
	}
	else 
	{
		for (int i = n; i > n - k; i--) {
			result *= i;
		}
	}
	return result;
}

long combinatorics::numberOfCombinations(int n, int k)
{
	long result;
	if ((n == 0) || (k == 0) || (k > n)) {
		result = 0;
	}
	else {
		result = numberOfVariations(n, k) / numberOfPermutations(k);
	}
	return result;
}

vector<vector<int>> combinatorics::getAllPermutationsRecursive(int n)
{
	vector<vector<int>> a;
	return a;
}

vector<vector<int>> combinatorics::getAllPermutationsIterative(int n)
{	
	vector<vector<int>> a;
	return a;
}

vector<vector<int>> combinatorics::getAllVariations(int n, int k)
{
	vector<vector<int>> a;
	return a;
}

vector<vector<int>> combinatorics::getAllCombinations(int n, int k)
{
	vector<vector<int>> a;
	return a;
}

vector<vector<int>> combinatorics::getAllSummands(int n)
{	
	vector<vector<int>> a;
	return a;
}