#ifndef SAFEARRAY_H
#define SAFEARRAY_H

template <class T> 
class safearray {

  private:
    T *storage;
    int capacity;
  
  public:
    safearray() : storage(NULL), capacity(0) {} // default constructor
    safearray(int size) { // single param constructor
		storage = new T[size];
		capacity = size;
	}
    ~safearray(void) { // destructor
		delete [] storage;
		capacity = 0;
	}
    T& operator[] (int index) throw(out_of_range) {
		if (index < 0)
			throw out_of_range("Index is below 0");
		if (index >= capacity)
			throw out_of_range("Index is too high");
		return storage[index];
	}
	T& operator[] (int index) const throw(out_of_range) {
		if (index < 0)
			throw out_of_range("Index is below 0");
		if (index >= capacity)
			throw out_of_range("Index is too high");
		return storage[index];
	}
};

#endif