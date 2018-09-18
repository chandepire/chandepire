#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mu;

using namespace std;

std::vector<int> bounds(int parts, int mem) {
    std::vector<int>bnd;
    int delta = mem / parts;
    int reminder = mem % parts;
    int N1 = 0, N2 = 0;
    bnd.push_back(N1);
    for (int i = 0; i < parts; ++i) {
        N2 = N1 + delta;
        if (i == parts - 1)
            N2 += reminder;
        bnd.push_back(N2);
        N1 = N2;
    }
    return bnd;
}

void dot_product(const vector<int> &v1,const vector<int> &v2,int &result,int L,int R)
{
	int temp = 0;
	for(int i=L;i<R;i++)
	{
		temp += v1[i]*v2[i];
	}
	//std::lock_guard<mutex> locker(mu);
	result += temp;
}

int main()
{
	int nr_elements = 100000;
	int nr_threads  = 2;
	int result = 0;
	vector<thread> threads;
	vector<int> v1(nr_elements,1),v2(nr_elements,2);
	vector<int> limits = bounds(nr_threads, nr_elements);
	for(int i=0;i<nr_threads;++i)
		threads.push_back(thread(dot_product,std::ref(v1),std::ref(v2),std::ref(result),limits[i],limits[i+1]));

	for(auto &t:threads)
	{
		t.join();
	}
	cout << result << endl;
	return 0;
}
