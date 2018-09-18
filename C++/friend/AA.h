
#pragma once 
#include "BB.h"
class A
{
	friend int B::func(A xx);
public:
	A(void):mx(20),my(30){}
	~A(void){}
private:
	int mx;
	int my;
};
