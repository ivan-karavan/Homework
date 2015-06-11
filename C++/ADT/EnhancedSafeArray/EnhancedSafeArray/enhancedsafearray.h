/*
Name + Surname: Perevoshchikov Ivan
Group: 202(2)SE
Date: 06.02.2015
Task: 3
IDE: Microsoft Visual Studio 2010
*/

#include "safearray.h"

template <class T>
class EnhancedSafeArray : public SafeArray<T>
{
public:
	// constructors invokes parent constructors
	EnhancedSafeArray(void): SafeArray() {};
	EnhancedSafeArray(size_t count): SafeArray(count) {};
	// copy constructor
	EnhancedSafeArray(const EnhancedSafeArray& toCopy): SafeArray(toCopy.count) {
		//delete this
		delete [] storage;
		count = toCopy.count;
		storage = new T[toCopy.count];
		//copy
		for (size_t i = 0; i < toCopy.count; ++i)
			this->storage[i] = toCopy.storage[i];
	}

	const size_t size() {
		return this->count;
	}
	const bool operator == (EnhancedSafeArray& secondObj){
		if (this->count != secondObj.count)
			return false;
		for (size_t i = 0; i < this->count; ++i)
			if (this->storage[i] != secondObj.storage[i])
				return false;
		return true;
	}

	EnhancedSafeArray operator = (const EnhancedSafeArray& secondObj) {
		//delete this
		delete [] storage;
		count = secondObj.count;
		storage = new T[secondObj.count];
		//deep copy
		return EnhancedSafeArray(secondObj);
	}
}