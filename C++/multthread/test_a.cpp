#include <ctime>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <mutex>

using namespace std;
std::mutex mymutex;

void hello()
{

  while(1)
  {
    {
      unique_lock<mutex> lock(mymutex);
    sleep(1);
    time_t t1;
    t1 = time(NULL);
    cout << "time="<<t1<<"  ";
    cout << "hello"<< endl;
    }
    usleep(10);
  }
}

void world()
{
    while(1)
    {

      {unique_lock<mutex> lock(mymutex);
      sleep(1);
      time_t t1;
      t1 = time(NULL);
      cout << "time="<<t1<<"  ";
      cout << "world"<< endl;
    }
    usleep(10);
  }
}

int main()
{
  time_t now_time;
  now_time = time(NULL);
  cout << "sysytem initial ...  t=" << now_time << endl;
  thread threadhello(hello);
  thread threadworld(world);
  now_time = time(NULL);
  cout << "threads joins ...  t=" << now_time << endl;
  threadhello.join();
  threadworld.join();
  return 0;
}
