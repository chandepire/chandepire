#include <iostream>

#include <thread>

#include <mutex>

int dataSource;

std::mutex mtx; //互斥锁

void task1();

void task2();

int main()

{

    std::thread thread1(task1), thread2(task2);

    thread1.join();

    thread2.join();

    std::cout << "the value of dataSource is " << dataSource << std::endl;

    std::cout << "运行完毕" << std::endl;

    return 0;

}

void task1()

{

    for (int i = 0; i < 10; ++i)

    {

        mtx.lock(); //加锁

        int tmp = dataSource + 1;

        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        dataSource = tmp;

        mtx.unlock(); //解锁

        std::cout << "task1 --- " << dataSource << std::endl;

    }

}

void task2()

{

    for (int i = 0; i < 10; ++i)

    {

        mtx.lock();

        int tmp = dataSource - 1;

        std::this_thread::sleep_for(std::chrono::milliseconds(300));

        dataSource = tmp;

        mtx.unlock();

        std::cout << "task2 --- " << dataSource << std::endl;

    }

}
