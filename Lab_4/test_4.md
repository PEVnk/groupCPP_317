Задание 3.1.  
a) неправильный код
```cpp
#include <iostream>
int main() {
short array[5]{1,3,5,7,9};
short *ptr = array;
*ptr = 111;
for (int i = 0; i < sizeof(array); ++i)
std::cout << array[i] << '\n';
```
исправленный код
```cpp
#include <iostream>
int main() {
short array[5]{1,3,5,7,9};
short *ptr = array;
*ptr = 111;
for (int i = 0; i < 5; ++i)
std::cout << array[i] << '\n';
}
```
b) неправильный код
```cpp
#include <iostream>
const int size = 5;
void Func(int *ptr, int size) {
for (int i = 0; i < size; ++i)
std::cout << *ptr[i] << '\n';
}
int main() {
int array[size]{1,3,5,7,9};
Func(&array, size);
}
```
исправленный код
```cpp
