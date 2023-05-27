#include<iostream>
using namespace std;

#include"EmptyQueue.h"

EmptyQueue::EmptyQueue():MyException()          //calls to parent class' constructor.
{ 
}
EmptyQueue::EmptyQueue(string s):MyException(s)    //calls to parent class' constructor.
{
}