#ifndef QUEUE_H
#define QUEUE_H

template<typename T>
class Queue
{
	int rear;
	int front;
	int capacity;
	int noofElements;
	T* data;
	void reSize(int);
public:
	Queue();
	~Queue();
	Queue(const Queue<T>&);
	Queue<T>& operator = (const Queue<T>&);
	void enQueue(T);
	T deQueue();
	T getElementAtFront();
	bool isEmpty();
	bool isFull();
	int getNoOfElements();
	int getCapacity();
};

#endif// !QUEUE_H