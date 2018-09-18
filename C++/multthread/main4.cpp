#include <deque>
#include <functional>
#include <iostream>
#include <fstream>
#include <thread>
#include <string>
#include <mutex>
#include <future>

using namespace std;

int factorial(int N)
{
	int res = 1;
	for(int i=N;i>1;--i)
		res *= i;
	cout << "Result is: " << res << endl;
	return res;
}

int main(int argc,char** argv)
{
	std::packaged_task<int()> t(std::bind(factorial,6));
	std::future<int> res = t.get_future();//获得与package_task共享状态相关联的feature对象
	int value = res.get();//等待任务完成并获取结果
	cout << value << endl;
	return 0;
}
