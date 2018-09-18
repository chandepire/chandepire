#include <iostream>

using namespace std;

template <typename T>
bool equivalent(const T &a,const T &b)
{
	return !(a<b)&&!(b<a);
}

template <typename T=int>
class bignumber
{
	T _v;
public:
	bignumber(T a):_v(a){}
	inline bool operator<(const bignumber &b) const;
};

template <typename T>
bool bignumber<T>::operator<(const bignumber &b) const
{
	return _v < b._v;
}

template <typename T1,typename T2>
class theSameType
{
	public: enum {ret = false};};
}

template <typename T>
class theSameType<T,T>
{
	public: enum {ret = true};};
}

template<typename T,int i>
class aTMP{};



int main()
{
	bignumber<> a(1),b(1);
	cout << equivalent(a,b) << endl; //函数模板参数自动推导
	cout << equivalent<double>(1,2) << endl;
	return 0;
}
