#include "B.h"
#include "A.h"
#include <iostream>

B::B(void)
{

}

B::~B(void)
{

}

int B::func()
{
	cout << "This is in B" << endl;
	A a;
	return a.m_nItem;
}
