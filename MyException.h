#ifndef MY_EXCEPTION_H
#define MY_EXCEPTION_H

class MyException:public exception       //inherit built in exception class
{
	string msg;
public:
	MyException();
	MyException(string);
	virtual void operator+=(string s);
	const char* what() const override;
};

#endif // !MY_EXCEPTION_H