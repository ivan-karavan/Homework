#include "bracket_sequence.h"
#include "stack.h"

/*
Name + Surname: Perevoshchikov Ivan
Group: 202SE(2)
Date: 19.01.2015
Task: Correct bracket sequence
IDE: Microsoft Visual Studio 2010
*/

/*
Finds correct bracket sequence, using three type of brackets: (), [], {}
Finds its length and fills the corresponding function parameter

Returns true if the current string is a complete correct bracket sequence, false otherwise
Precondition : str is not NULL and contains only three type of brackets, length = 0
Ñomplexity : O(n)
Memory: O(n)
*/

char myParse(char sym);

bool find_sequence(const string & str, int & prefix_length) {

	// Write your code here
	size_t input = 0;
	stack sequence = stack();
	int i = 0;
	char cur_el;
	for (; i < str.length(); ++i)
	{
		cur_el = str[i];
		// if symbol is not bracket
		if (!(str[i] == ')' || str[i] == '(' || str[i] == '}' ||
			str[i] == '{' || str[i] == ']' || str[i] == '['))
			cur_el = myParse(str[i]);

		if (cur_el == '(')
		{
			sequence.push('(');
			++prefix_length;
		}
		if (cur_el == '{')
		{
			sequence.push('{');
			++prefix_length;
		}
		if (cur_el == '[')
		{
			sequence.push('[');
			++prefix_length;
		}
		
		if (cur_el == ')')
		{
			// if str[i] is the second part of pair, we pop the first element of pair
			if (sequence.what_is_top() == '(')
			{
				sequence.pop();
				++prefix_length;
			}
			// another situations are incorrect
			else
			{
				return false;
			}
		}
		if (cur_el == '}')
		{
			if (sequence.what_is_top() == '{')
			{
				sequence.pop();
				++prefix_length;
			}
			else
			{
				return false;
			}
		}
		if (cur_el == ']')
		{
			if (sequence.what_is_top() == '[')
			{
				sequence.pop();
				++prefix_length;
			}
			else
			{
				return false;
			}
		}
	}

	return true;
}

char myParse(char sym)
{
	switch (sym % 6)
	{
	case 0 :
		return '(';
	case 1 :
		return ')';
	case 2 :
		return '{';
	case 3 :
		return '}';
	case 4 :
		return '[';
	case 5 :
		return ']';
	}
}