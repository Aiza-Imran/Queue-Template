#include<iostream>
using namespace std;

#include"Queue.h"

int main()
{
	Queue<int> q1;
	q1.enQueue(16);
	q1.enQueue(78);
	q1.enQueue(25);
	q1.enQueue(87);
	q1.enQueue(23);
	q1.enQueue(63);
	q1.enQueue(293);
	q1.enQueue(51);

	q1.deQueue();   //removes the element from front of queue(which was enqueued very first) -> FIFO(First In First Out)


	cout << q1.getElementAtFront() << '\n';    //78
	cout << q1.getNoOfElements() << '\n';      //7
	cout << q1.getCapacity() << '\n';          //8

	return 0;
}