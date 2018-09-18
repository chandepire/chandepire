#include <iostream>
#include <stdlib.h>
using namespace std;

double fuc(double x,double y)
{
	if(y == 0)
		throw y;
	return x/y;
}

int main(int argc,char **argv)
{
	double res;
	try
	{
		res = fuc(2,3);
		cout << "The result of x/y is :" << res << endl;
		res =fuc(4,0);
	}
	catch(double)
	{
		cerr << "error of dividing zero.\n";
		exit(1);
	}
	return 0;
}
