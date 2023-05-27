#ifndef EMPTY_QUEUE_H
#define EMPTY_QUEUE_H

#include"MyException.h"

class EmptyQueue:public MyException
{
public:
	//" using MyException::MyException " A way to inherit non-default constructors of parent class.
	EmptyQueue();
	EmptyQueue(string);
};
#endif // !EMPTY_QUEUE_H

