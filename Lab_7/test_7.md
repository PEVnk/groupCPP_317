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

5) 
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

6) 
```cpp
