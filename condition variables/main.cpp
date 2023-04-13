#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

// conditional variables are use for two things
// 1. Notify other thread  -- using notify_one() and notify_all()
// 2. waiting for some conditions

using namespace std;

std::condition_variable cv;
std::mutex m;

long balance = 0;

int main(int argc, char *argv[])
{
  cout << "hello from conditional varibales" << endl;
  return 0;
}