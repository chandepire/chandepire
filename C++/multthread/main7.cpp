#include <iostream>
#include <thread>
#include <fstream>

using namespace std;

void function_al(int N,int &x)
{
	int res = 1;
	for(int i=N;i>1;i--)
	{
		res*=i;
	}
	cout << "Result is:" << res << endl;
    x = res;

	return 
}
int main()
{
	int x;
	thread t1(function_al,4,std::ref(x));
	t1.join();
	return 0;
}
