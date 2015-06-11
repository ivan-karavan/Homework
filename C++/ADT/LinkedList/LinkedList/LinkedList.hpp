template <class T>
LinkedList<T>::LinkedList()
{
	//Creation of the dummy/sentinel element
	pPreHead = new Node<T>;
	pPreHead->next = 0;

	// Write your code here
	// ...
}

template <class T>
LinkedList<T>::~LinkedList()
{
	// Write your code here...


	// Delete sentinel
	delete pPreHead;
}


// Write your code here
// ...

template <typename T>
LinkedList<T>::addElementToEnd(T& value)
{

}