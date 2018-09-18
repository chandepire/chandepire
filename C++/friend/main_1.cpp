#include <iostream>
#include <cmath>
using namespace std;

class Point
{
public:
	Point(double xx,double yy)
	{
		x = xx;
		y = yy;
	}
	void GetXY();
	friend double Distance(Point &a,Point &b);
	
	friend ostream &operator << (ostream &a, Point &b);
protected:
private:
	double x,y;
};

ostream &operator <<(ostream &a, Point &b)
{
	a << "(" << b.x << "," << b.y << ")" << endl;
	return a;
}

void Point::GetXY()
{
	cout << *this;
}

double Distance(Point &a,Point &b)
{
	double length;
	length = sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
	return length;
}

int main()
{
	Point p1(3.0,4.0),p2(6.0,8.0);
	p1.GetXY();
	p2.GetXY();
	double d = Distance(p1,p2);
	cout << d << endl;
	
	return 0;
}	
