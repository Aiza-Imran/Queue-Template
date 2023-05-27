#include<iostream>
using namespace std;

#include"MyException.h"

MyException::MyException()
{
}
MyException::MyException(string s):msg(s)   //store received string in msg using member initializer list.
{
}
void MyException::operator+=(string s)     //concatenates msg
{
	msg += s;
}
const char* MyException::what() const      //returns what msg/exception msg was passed.
{
	return msg.c_str();
}