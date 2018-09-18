#include <thread>
#include <iostream>
#include <string>
#include <mutex>
#include <unistd.h>
#include <fstream>

using namespace std;

class Logfile
{
public:
	Logfile(){
		
	}
	void shared_print(std::string msg,int id)
	{
		/*{
			std::unique_lock<std::mutex> locker(mu_mu_open,std::defer_lock);
		        if(!f.is_open())
			{	
				f.open("log.txt");
			}
		}*/
		std::call_once(m_flag, [&](){f.open("log.txt");});//确保一个线程只打开一次文件
		std::unique_lock<std::mutex> locker(mu,std::defer_lock);
		cout << msg << id << endl;
	}
	
private:
	std::mutex mu;
	//std::mutex mu_open;
	std::once_flag m_flag;
	std::ofstream f;
};
void function_1(Logfile& log)
{
    for(int i=0;i>-10;--i)
    {
	sleep(1);
	log.shared_print( "from t1: " , i );
    }
}

int main(int argc, char** argv)
{
    Logfile log;
    std::thread t1(function_1,std::ref(log));
    for(int i=0;i<10;++i)
    {	
	sleep(1);
	log.shared_print("from main: ",i);
    }
    t1.join();
    return 0;
}
