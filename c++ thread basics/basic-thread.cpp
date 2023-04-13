// find the addition of all odd number from 1 to 10000000 and even number from 1 to 10000000.
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace std::chrono;

typedef unsigned long long ull;

ull oddSum = 0;
ull evenSum = 0;

void findOdd(ull start, ull end)
{
  for (ull i = start; i < end; i++)
  {
    if ((i & 1) == 1)
    {
      oddSum += i;
      cout << "odd" << endl;
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
}

// auto findOdd = [](ull start, ull end)
// {
//   for (ull i = start; i < end; i++)
//   {
//     if ((i & 1) == 1)
//     {
//       oddSum += i;
//       cout << "ODD" << endl;
//     }
//   }
// };

// class findOdd
// {
// public:
//   void operator()(ull start, ull end)
//   {
//     for (ull i = start; i < end; i++)
//     {
//       if ((i & 1) == 1)
//       {
//         oddSum += i;
//       }
//     }
//   }
// };

// void findEven(ull start, ull end)
// {
//   for (ull i = 0; i < end; i++)
//   {
//     if ((i & 1) == 0)
//     {
//       oddSum += i;
//       cout << "EVEN" << endl;
//     }
//   }
// }

auto findEven = [](ull start, ull end)
{
  for (ull i = 0; i < end; i++)
  {
    if ((i & 1) == 0)
    {
      evenSum += i;
      cout << "Even" << endl;
      this_thread::sleep_for(chrono::seconds(1));
    }
  }
};

// class findEven
// {
// public:
//   void run(ull start, ull end)
//   {
//     for (ull i = 0; i < end; i++)
//     {
//       if ((i & 1) == 0)
//       {
//         oddSum += i;
//         cout << "EVEN" << endl;
//       }
//     }
//   }
// };

int main(int argc, char *argv[])
{
  auto startTime = steady_clock::now();
  ull start = 0;
  ull end = 4;

  thread t1(findEven, start, end);
  thread t2(findOdd, start, end);

  t1.join();
  t2.join();

  // findOdd(start, end);
  // findEven(start, end);

  cout << "odd sum:" << oddSum << endl;
  cout << "even sum:" << evenSum << endl;

  auto endTime = steady_clock::now();
  auto duration = duration_cast<milliseconds>(endTime - startTime);
  cout << "Duration: " << duration.count() << " miliseconds" << endl;

  return 0;
}