1) неверный код
```cpp
std::mutex g_lock;
void threadFunction() {
std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
g_lock.unlock();
}
int main() {
srand((unsigned int)time(0));
std::thread t1(threadFunction);
std::thread t2(threadFunction);
std::thread t3();
return 0;
}
```

исправленный код:
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <cstdlib>
#include <ctime>

std::mutex g_lock;
void threadFunction() {
    g_lock.lock();
    std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(rand()%10));
    std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
    g_lock.unlock();    
}
int main() {
    srand((unsigned int)time(0));
    std::thread t1(threadFunction);
    std::thread t2(threadFunction);
    std::thread t3(threadFunction);
    t1.join();  
    t2.join();
    t3.join();
    return 0;
}
```

2) неверный код
```cpp
using namespace std;
int main() {
try {
domain_error("Your domain is in error!");
}
(const exception& e) {
cerr << "Caught: " << e.what() << endl;
cerr << "Type: " << typeid(e).name() << endl;
}
}
```

исправленный код:
```cpp
#include <iostream>
#include <stdexcept>  
#include <typeinfo>  

using namespace std;
int main() {
  try {
    throw domain_error("Your domain is in error!");
    }
  catch (const exception& e) {
    cerr << "Caught: " << e.what() << endl;
    cerr << "Type: " << typeid(e).name() << endl;
  }

return 0;
}
```

3) 
```cpp
#include <iostream>
#include <thread>
#include <chrono>

void f(int seconds) {
    std::cout << "Run f()\n";
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
    std::cout << seconds << " sec\n";
}

int main() {
    int user_seconds;
    std::cout << "Enter time in seconds for thread t: ";
    std::cin >> user_seconds;

    std::cout << "Main program thread\n";
    
    std::thread t(f, user_seconds);
    std::cout << "Run some other tasks\n";
    
    std::cout << "Waiting for t\n";
    t.join();
    
    return 0;
}
```

4) 
```cpp
#include <iostream>
#include <thread>
#include <chrono>

void thread_task(int id, int wait_time) {
    std::cout << "t" << id << " thread\n";
    std::cout << "task" << id << "\n";
    std::this_thread::sleep_for(std::chrono::seconds(wait_time));
    std::cout << "Wait for t=" << wait_time << "c\n";
}

int main() {
    std::cout << "Main program thread\n";

    // Создаем три потока 
    std::thread t1(thread_task, 1, 10); // t1 ждет 10 секунд
    std::thread t2(thread_task, 2, 3);  // t2 ждет 3 секунды
    std::thread t3(thread_task, 3, 5);  // t3 ждет 5 секунды

    // Ожидаем завершения всех потоков
    std::cout << "task_1-3 join()\n";
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
```

5)  неверный код
```cpp
void task1(string msg) {
cout << "task1 says: " << msg;
}
int main() {
thread t1(task1);
}
```
исправленный код:
```cpp
#include <iostream>
#include <thread>
#include <string>

using namespace std;
void task1(string msg) {
    cout << "task1 says: " << msg<< endl;
}
int main() {
    thread t1(task1, "Hello from thread!");
    t1.join(); 
return 0;
}
```

6)  неверный код
```cpp
static const int num_threads = 10;
//This function will be called from a thread
void call_from_thread(int tid) {
std::cout << "Launched by thread " << tid << std::endl;
}
int main() {
std::thread t[num_threads];
//Launch a group of threads
for (int i = 0; i < num_threads; ++i) {
t[i] = std::thread();
}
std::cout << "Launched from the main\n";
//Join the threads with the main thread
for (int i = 0; i < ; ++i) {
t[i].join();
}
}
```
исправленный код:
```cpp
#include <iostream>
#include <thread>

static const int num_threads = 10;
//This function will be called from a thread
void call_from_thread(int tid) {
std::cout << "Launched by thread " << tid << std::endl;
}
int main() {
std::thread t[num_threads];
//Launch a group of threads
for (int i = 0; i < num_threads; ++i) {
t[i] = std::thread(call_from_thread, i);
}
std::cout << "Launched from the main\n";
//Join the threads with the main thread
for (int i = 0; i < num_threads; ++i) {
if (t[i].joinable()) {
t[i].join();
}
}
return 0;
}
```

7)  неверный код
```cpp
constexpr int COUNT_DATA{15};
// a global variable
static int myList[COUNT_DATA];
// a global instance of std::mutex to protect global variable
std::mutex myMutex;
void addToList(int max, int interval) {
// the access to this function is mutually exclusive
std::lock_guard guard(myMutex);
for (int i = 0; i < max; i++) {
if( (i % interval) == 0) myList[i] = i;
}
}
void printList() {
// the access to this function is mutually exclusive
std::lock_guard<> (myMutex);
for (auto itr{0}; itr < COUNT_DATA; ++itr ) {
cout << myList[itr] << ", ";
}
}
int main() {
int max = 100;
std::thread t1(addToList, max);
std::thread t2(addToList, max);
std::thread t3(printList);
}
```
исправленный код:
```cpp
#include <iostream>
#include <thread>
#include <mutex> 

constexpr int COUNT_DATA{15};
// a global variable
static int myList[COUNT_DATA] = {0};
// a global instance of std::mutex to protect global variable
std::mutex myMutex;
void addToList(int max, int interval) {
// the access to this function is mutually exclusive
std::lock_guard<std::mutex>  guard(myMutex);
for (int i = 0; i < max; i++) {
if( (i % interval) == 0) myList[i] = i;
}
}
void printList() {
// the access to this function is mutually exclusive
std::lock_guard<std::mutex> guard(myMutex);
for (auto itr{0}; itr < COUNT_DATA; ++itr ) {
std::cout << myList[itr] << ", ";
}
}
int main() {
int max = 100;
std::thread t1(addToList, max,2);
std::thread t2(addToList, max,3);
std::thread t3(printList);

return 0;
}
```

8)  неверный код
```cpp
// Global mutex to protect shared_data
mutex mtx;
// Shared data variable
int shared_data = 0;
// Function to increment shared_data
void increment_data() {
// Create a unique_lock object, but defer locking the mutex
unique_lock<> (mtx, defer_lock);
// Critical section: safely modify shared_data
shared_data += 2;
}
int main() {
// Create two threads that run the increment_data function
thread t1();
thread t2();
// Wait for both threads to finish
t1.join();
// Output the value of shared_data
cout << "Value of shared variable: " << shared_data;
}
```
исправленный код:
```cpp
#include <iostream>
#include <thread>
#include <mutex> 

// Global mutex to protect shared_data
std::mutex mtx;
// Shared data variable
int shared_data = 0;
// Function to increment shared_data
void increment_data() {
// Create a unique_lock object, but defer locking the mutex
std::unique_lock <std::mutex> lock(mtx, std::defer_lock);
// Critical section: safely modify shared_data
lock.lock();
shared_data += 2;
}
int main() {
// Create two threads that run the increment_data function
std::thread t1(increment_data);
std::thread t2(increment_data);
// Wait for both threads to finish
t1.join();
t2.join();
// Output the value of shared_data
std::cout << "Value of shared variable: " << shared_data<< std::endl;

return 0;
}
```

9)  неверный код
```cpp
std::mutex m;
int a,b;
void f1() {
lock_guard lock(m);
a = 1;
try {
int * ptr = new int[10];
}catch(...) {
cout <<"new faild"<<endl;
}
// still locked
std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //2s
b = 2;
}
void f2() {
lock_guard<> (m);
cout << a <<" : "<<b <<endl;
}
int main() {
std::thread T1(f1);
std::thread T2(f2);
}
```
исправленный код:
```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono> 

std::mutex m;
int a,b;
void f1() {

std::lock_guard lock(m);
a = 1;
try {
int *ptr = new int[10];
}catch(...) {

std::cout <<"new faild"<<std::endl;
}
// still locked
std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //2s
b = 2;
}
void f2() {
std::lock_guard<std::mutex> guard(m);

std::cout << a <<" : "<<b <<std::endl;
}
int main() {
std::thread T1(f1);
std::thread T2(f2);

return 0;
}
```
