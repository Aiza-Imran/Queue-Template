#include <iostream>     //for input/output 
using namespace std;

#include"Queue.h"         
#include"EmptyQueue.h"    //for user-defined exception class 



//resizes queue to given capacity
template<typename T>
void Queue<T>::reSize(int newCapacity)
{
	T * temp = new T[newCapacity];
	int i = 0, j = front;
	while (i < noofElements)
	{
		temp[i] = data[j];
		i++;
		j = (j + 1) % capacity;    //because queue is implemented in a circular way.
	}
	int noe = noofElements;
	this->~Queue();
	data = temp;
	capacity = newCapacity;
	noofElements = noe;
	rear = noe;
	front = 0;
}


//default constructor for queue implemented in circular way
template<typename T>
Queue<T>::Queue()
{
	rear = 0;
	front = 0;
	capacity = 0;
	noofElements = 0;
	data = nullptr;
}


//destructor. Frees the space occupied by queue
template<typename T>
Queue<T>::~Queue()
{
	if (data)
		delete[] data;
	data = nullptr;
	capacity = noofElements = rear = front = 0;
}


//Copy constructor. It uses copy assignment operator (overloaded in class) to copy the contents of passed object
template<typename T>
Queue<T>::Queue(const Queue<T>& ref):Queue()
{
	*this = ref;
}


//Copy assignment.Deeply copies an object's contents into another object
template<typename T>
Queue<T>& Queue<T>::operator = (const Queue<T>& ref)
{
	if (this == &ref)
		return *this;
	this->~Queue();
	if (!ref.data)
		return *this;
	
	int i = 0, j = ref.front;
	while (i < ref.noofElements)
	{
		data[i] = ref.data[j];
		i++;
		j = (j + 1) % capacity;
	}
	front = 0;
	noofElements = ref.noofElements;
	rear = noofElements;
	
	capacity = ref.capacity;

	return *this;

}


//Inserts element into end(rear) of queue
template<typename T>
void Queue<T>::enQueue(T element)
{
	if (isFull())
		reSize(capacity == 0 ? 1 : capacity * 2);
	data[rear] = element;
	rear = (rear + 1) % capacity;    //increments rear data member so that next element is added on next position.
	noofElements++;
}


//deletes element from the start(front) of queue
template<typename T>
T Queue<T>::deQueue()
{
	if (isEmpty())     //checks if queue is empty, then throws user-defined EmptyQueue exception.
	{
		throw EmptyQueue("Queue is Empty.\n");
	}
	T val = data[front];
	front = (front + 1) % capacity;
	noofElements--;

	if (noofElements > 0 && noofElements == capacity / 4)    //to shrink queue if unused positions are more than 3/4 of total
		reSize(capacity / 2);

	return val;
}


//returns the element at front(which will be removed if deque is called)
template<typename T>
T Queue<T>::getElementAtFront()
{
	return data[front];
}


//returns true if queue is empty, otherwise false
template<typename T>
bool Queue<T>::isEmpty()
{
	return noofElements == 0;
}


//returns true if queue is full and no space is vacant
template<typename T>
bool Queue<T>::isFull()
{
	return noofElements == capacity;
}


//returns total number of elements stored in queue
template<typename T>
int Queue<T>::getNoOfElements()
{
	return noofElements;
}

//returns the total capacity of queue to store elements.
template<typename T>
int Queue<T>::getCapacity()
{
	return capacity;
}