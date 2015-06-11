#ifndef STACK_ALGO_H
#define STACK_ALGO_H
#include <stddef.h>

using namespace std;

const size_t size = 50;

struct stack {

	// Write your code here

	size_t cur_size;
	char our_stack[size];
	stack()
	{	
		cur_size = 0;
	}

	bool push(char ch);
	bool pop();
	bool isempty() const;
	bool isfull() const;
	char what_is_top() const;

	// Write your code here

};

#endif
