#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

// mutex -- mutual condition
using namespace std;
using namespace std::chrono;

// common data   -- might have race condition
int myAmount = 0;

mutex m;

void addMoney()
{
  m.lock();
  ++myAmount;
  m.unlock();
}

int main(int argc, char *argv[])
{
  thread t1(addMoney);
  thread t2(addMoney);

  t1.join();
  t2.join();

  cout << myAmount << endl;

  return 0;
}