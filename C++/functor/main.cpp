#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct add_x
{
	add_x():x(0) {}
	add_x(int n):x(n){}
	int operator()(int y)
	{
		return x+y;
	}
	private:
	int x;
};

struct sum
{
	sum(int *t):total(t){};
	int *total;
	void operator()(int element)
	{
		*total += element;
	}
};

class CalculateAverage
{
public:
	CalculateAverage(float p) : acc(0),n(0),p(p) {}
	void operator()(int x) { 

		acc += pow(x,p);
		++n;
		cout << "ok" << endl;
		cout << "acc: " << acc << endl;
		cout << "n: " << n << endl;
			
	}
	float getAverage() const 
	{
		cout << acc << endl;
		cout << n << endl;
		return acc/n;
	}
public:
	float acc;
	int n;
	float p;
};

int main()
{
	CalculateAverage cal(2);
	int arr[] = {0,1,2,3,4};
	CalculateAverage res = for_each(arr,arr+5,cal);
		cout << "acc: " << res.acc << endl;
		cout << "n: " << res.n << endl;
		cout << "p: " << res.p << endl;
	cout << cal.getAverage() << endl;
	return 0;
}
