Задание 4.1.  
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
#include <iostream>
const int size = 5;
void Func(int array[size], const int size) {
for (int i = 0; i < size; ++i)
std::cout << array << '\n';
}
int main() {
int array[size]{1,3,5,7,9};
int *ptr = array;
Func(ptr, size);
}
```
c) неправильный код
```cpp
#include <iostream>
int main() {
short value;
short *p;
p = value;
*p = value;
*p = &value;
*p = *&value;
}
```
исправленный код
```cpp
#include <iostream>
int main() {
short value;
short *p;
p = &value;
*p = value;
*p = *&value;
}
```
d) неправильный код
```cpp
#include <iostream>
int main() {
short value;
short *p;
p = value;
*p = value;
*p = &value;
*p = *&value;
}
```
исправленный код
```cpp
#include <iostream>
int main() {
short value;
short *p;
p = &value;
*p = value;
*p = *&value;
}
```
e) неправильный код
```cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref;
const short &ref1 = value;
const short &ref2 = 78;
ref1 = 3;
*&value = 4;
const *short const p3;
}
```
исправленный код
```cpp
#include <iostream>
int main() {
short value, value1(3);
short &ref = value1;
short &ref1 = value;
const short &ref2 = 78;
ref1 = 3;
*&value = 4;
const short *const p3{nullptr};
}
```
f) ошибок в коде нет
```cpp
#include <iostream>
int main() {
short value = 13;
short value_1 = 100;
short *ptr = &value;
std::cout << &value << '\n';
std::cout << (value +=1) << '\n';
*ptr = 9;
std::cout << (value = value_1 + *ptr) << '\n';
std::cout << "Результат: " << value << '\n';
return 0;
}
```
g) неправильный код
```cpp
int main() {
int value = 45;
int *ptr = &value;
*ptr = &value;
ptr = value;
}
```
исправленный код
```cpp
#include <iostream>
int main() {
int value = 45;
int *ptr = &value;
*ptr = value;
ptr = &value;
}
```
