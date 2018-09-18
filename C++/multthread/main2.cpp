#include <iostream>
#include <thread>
#include <string>

using namespace std;

void function_1(void)
{
    cout << "hello world!" << endl;
}

class fctor
{
public:
	void operator()(std::string &msg)
    {
	    cout << msg << endl;
	    msg = "cdp";
	}
};
int main(int argc,char** argv)
{
    //fctor fct;
    string ms = "nihao";
	cout << this_thread::get_id() << endl;
    thread t1((fctor()),std::ref(ms));

    thread t2 = std::move(t1);
	cout << t2.get_id() << endl;
    t2.join();

	cout << ms << endl;
    cout << std::thread::hardware_concurrency();
    return 0;
}
