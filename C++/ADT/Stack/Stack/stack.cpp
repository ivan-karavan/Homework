#include "stack.h"

bool stack::push(char ch){
	// Write your code here
	if (isfull())
		return false;
	our_stack[cur_size] = ch;
	++cur_size;
	return true;
}

bool stack::pop(){
	// Write your code here
	if (isempty())
		return false;
	--cur_size;
	return true;
}

bool stack::isempty() const{
	// Write your code here	
	if (cur_size == 0)
		return true;
	return false;
}

bool stack::isfull() const{
	// Write your code here	
	if (cur_size == size)
		return true;
	return false;
}

char stack::what_is_top() const{
	// Write your code here	
	if (cur_size != 0)
		return our_stack[cur_size - 1];
	return NULL;
}


