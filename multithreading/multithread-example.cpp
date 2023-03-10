#include <iostream>
#include <thread>

using namespace std;

void fun(int x)
{
    cout << "Thread id: " << this_thread::get_id() << " Value of x: " << x << endl;
}

int main()
{
    thread t1(fun, 1);
    thread t2(fun, 2);

    t2.join();
    t1.join();

    return 0;
}