#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

thread_local int counter = 0;

void worker(int id)
{
    counter++;
    cout << "Thread " << id << " counter = " << counter << endl; 
}

int main()
{
    thread t1(worker, 1);
    t1.join();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    thread t2(worker, 2);
    t2.join();
    return 0;
}
