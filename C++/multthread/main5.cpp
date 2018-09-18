#include <iostream>
#include <thread>
#include <mutex>
#include <fstream>
std::mutex mu;

using namespace std;
class LogFile
{
	std::once_flag m_flag;
	std::mutex m_mutex;
	std::ofstream f;
public:
	LogFile()
	{
		f.open("log.txt");
	}
	void shared_print(std::string id,int value)
	{
		std::call_once(m_flag,[&](){f.open("log.txt");});
		std::unique_lock<std::mutex> locker(mu,std::defer_lock);
		f << "From " << id << ":" << value << endl;
	}
};

void function_1(LogFile& log)
{
	for(int i=0;i>-100;i--)
		log.shared_print(std::string("From t1"),i);
}

int main()
{
	LogFile log;
	std::thread t1(function_1, std::ref(log));
	for(int i=0;i<100;++i)
		log.shared_print(std::string("From main"),i);
	t1.join();
	return 0;
}

