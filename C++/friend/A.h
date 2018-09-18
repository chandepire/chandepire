#pragma once
#include <iostream>
using namespace std;

class A
{
    friend class B;
    public:
	~A(void);
	A();
    private:
	int m_nItem;
};


