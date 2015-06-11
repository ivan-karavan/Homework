/*
Perevoshchikov Ivan
202SE(2)
*/

#include "LinkedList.h"

class ListItemNotFoundException : public logic_error
{
public:
	ListItemNotFoundException(const string& what_arg) throw() :
		logic_error("Key is not found: " + what_arg) {}
};

template <class T>
class EnhancedLinkedList : public LinkedList<T>
{
public:
	T& find_first(const T& key);
	EnhancedLinkedList find_all(const T& key);
	void remove_first(const T& key);
	void remove_all(const T& key);
};

template <class T>
T& EnhancedLinkedList<T>::find_first(const T& key)
{
	if (this->empty()) {
		throw EmptyListException("find_first()");
	}
	if (this->head->getData() == key)
		return head->getData();
	Node<T>* prev = this->head;
	Node<T>* curr = prev->getNext();
	while (curr != NULL) {
		if (curr->getData() == key) {
			return curr->getData();
		}
		else {
			prev = curr;
			curr = curr->getNext();
		}
	}
	throw ListItemNotFoundException("find_first()");
}

template <class T>
EnhancedLinkedList<T> EnhancedLinkedList<T>::find_all(const T& key)
{
	EnhancedLinkedList<T> allCopies;
	if (this->empty())
		return allCopies;
	Node<T>* curr = this->head;
	while (curr != NULL) {
		if (curr->getData() == key) {
			allCopies.push_back(key);
			curr = curr->getNext();
		}
		else {
			curr = curr->getNext();
		}
	}
	return allCopies;
}

template <class T>
void EnhancedLinkedList<T>::remove_first(const T& key)
{
	if (this->empty())
		return;
	Node<T>* curr = head;
	if (curr->getData() == key) {
		head = curr->getNext();
		delete curr;
		--count;
		return;
	}
	Node<T>* prev = head;
	curr = prev->getNext();
	while (curr->getNext() != NULL) {
		if (curr->getData() == key) {
			prev = new Node<T>(prev->getData(), curr->getNext());
			curr = curr->getNext();
			--count;
			return;
		}
		else {
			prev = curr;
			curr = curr->getNext();
		}
	}
}

template <class T>
void EnhancedLinkedList<T>::remove_all(const T& key)
{
	if (this->empty())
		return;
	Node<T>* prev = head;
	while (prev->getData() == key) {
		this->head = prev->getNext();
		prev = prev->getNext();
	}
	Node<T>* curr = prev->getNext();
	while (curr != NULL) {
		if (curr->getData() == key) {
			// delete curr
			prev = new Node<T>(prev->getData(), curr->getNext());
			curr = curr->getNext();
			--count;
		}
		else {
			prev = curr;
			curr = curr->getNext();
		}
	}
}