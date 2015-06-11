#include <vector>

using namespace std;

/*
	Now it's gonna be easy. You need to implement functions from template.
	If you are not going to implement a function, implement it just in a way of returning
	wrong logical answer, but compilable.

	You are welcome write any additional methods to be used. It is even expected to write them if
	you want to get the highest mark.

	You need to use vector class in this work. If you are not acquainted with it, don't be
	afraid. It is very easy. Vectors are very similar to List class in C#.
	It seems like the only functions you need are:
		- push_back(value) - inserts value in the end of the vector
		- [index] - indexer to get value at current index (just like arrays)
		- size() - number of items in current vector (needs O(n) time)
	For further information about vectors check the web - there is plenty of stuff.

	
	Good luck!
*/
class combinatorics {
public:
	/*
		Method to get number of permutations of n items

		Params:
			n - number of items to be permuted
		Returns:
			number of permutations of n items or 0 if n <= 0
	*/
	static long numberOfPermutations(int n);

	/*
		Method to get number of variations of k items in a set of n items

		Params:
			n - number of all items
			k - number of items in a single variation
		Returns:
			number of variations of k items in a set of n items or 0 if n <= 0 or k <= 0 or k > n
	*/
	static long numberOfVariations(int n, int k);

	/*
		Method to get number of combinations of k items in a set of n items

		Params:
			n - number of all items
			k - number of items in a single combination 
		Returns:
			number of combinations of k items in a set of n items or 0 if n <= 0 or k <= 0 or k > n
	*/
	static long numberOfCombinations(int n, int k);

	/*
		Method to retrieve all permutaions of n items with recursive algorithm

		Params:
			n - number of items to be permuted
		Returns:
			vector of permutations (which are represented by vectors). result.size should be equal to number of permutations of n,
			each permutation should have the same length equal to n.
	*/
	static vector<vector<int>> getAllPermutationsRecursive(int n);

	/*
		Method to retrieve all permutaions of n items with iterative algorithm

		Params:
			n - number of items to be permuted
		Returns:
			vector of permutaions (which are represented by vectors). result.size should be equal to number of permutations of n,
			each permutation should have the same length equal to n.
	*/
	static vector<vector<int>> getAllPermutationsIterative(int n);

	/*
		Method to retrieve all variations of k items in a set of n items

		Params:
			n - total number of items
			k - number of items in a single variation
		Returns:
			vector of variations (which are represented by vectors). result.size should be equal to number of variations of k in n,
			each variation should have the same length equal to k.
	*/
	static vector<vector<int>> getAllVariations(int n, int k);

	/*
		Method to retrieve all combinations of k items in a set of n items

		Params:
			n - total number of items
			k - number of items in a single combination
		Returns:
			vector of combinations (which are represented by vectors). result.size should be equal to number of combinations of k in n,
			each combination should have the same length equal to k.
	*/
	static vector<vector<int>> getAllCombinations(int n, int k);

	/*
		Method to return all vectors of summands in non-increasing order of n.

		Params:
			n - value which is sum of summands in result vectors.

		Returns:
			vector of all possible partitions to summands. Sum of summands in each vector of the result vector should be equal to n.
			Summands in each vector of the result vector should be in non-increasing order.
			Size of the result vector should be equal to number of all possible representations of n via sum of summands in non-increasing order.
	*/
	static vector<vector<int>> getAllSummands(int n);
};