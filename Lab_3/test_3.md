a) неправильный код
```cpp
#include <iostream>
int return 5(){
return 5;
}
int return8(){
return;
}
int main(){
std::cout << (return5() + return8() ) << std::endl;
return 0
}
```
исправленный код
```cpp
#include <iostream>
int return5(){
return 5;
}
int return8(){
return 8;
}
int main(){
std::cout << (return5() + return8() ) << std::endl;
return 0;
}
```
вывод: 13

b) неправильный код
```cpp
int return() {
return 5;
int return()
{
int k ;
k{3};
return k;
}
}
int main(){
std::cout << return() << std::endl;
std::cout << return() << std::endl;
}
```
исправленный код
```cpp
#include <iostream>

int return1() {
    return 5;
}

int return2() {
    int k{3}; 
    return k;
}

int main() {
    std::cout << return1() << std::endl; 
    std::cout << return2() << std::endl; 
    return 0;
}
```
вывод: 5 3

c) неправильный код
```cpp
#include <iostream>
void prints
()
{
std::cout << 'O_o' << std::endl;
}
int main         ()
                {
std::cout << prints() << std::endl;
return 0;
}
```
исправленный код
```cpp
#include <iostream>
void print(){
    std::cout << "O_o" << std::endl;
}
int main(){
    print();
return 0;
}

```
вывод: O_o

d)
#include <iostream>
int getNumbers()
{
return 6;
return 8;
}i
nt main()
{
std::cout << getNumbers() << std::endl;
std::cout << getNumbers() << std::endl;
std::cout << getNumbers << std::endl;
return 0;
}
e)
int main()
{
std::cout << multiply(7, 8) << std::endl;
return 0;
}
void multiply(int a)
{
return a * b
}
int main() {
int x;
std::cin >> x;
constexpr int y(x); // в дальнейшем переменная usersAge не может быть изменена
std::cout << y << std::endl;
return 0;
}
f)
#include <iostream>
#define VALUE 1
int main() {
#if (VALUE == 0)
std::cout << VALUE <<"\n";
#elif (VALUE == 1)
std::cout << VALUE <<"\n";
#else
std::cout << VALUE <<"\n";
#endif
}
g)
#include <iostream>
namespace Mix {
enum class Fruits {
LEMON,
APPLE
};
enum class Colors {
RED,
BLACK
};
}i
nt main() {
Fruits fruit = Fruits::LEMON;
std::cout << "MIX\n";
return 1;
}
h)
#include <iostream>
namespace DoMath
{
int subtract(int x, int y)
{
return x , y;
}
}
namespace DoMath
{
int add(int x, int y)
{
return x | y;
}
}i
nt main(void)
{
std::cout << DoMath::add(5, 4) << '\n';
std::cout << DoMath::subtract(5, 4) << '\n';
return 0;
}
