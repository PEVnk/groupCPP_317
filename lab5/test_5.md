1) неверный код
```cpp
#include<iostream>
int main() {
float a=3.14;
char *pj;
pj = (char*)&a;
std::cout << *pj << '\n';
}
```
происходит потеря данных из-за попытки вывести значение переменной типа float как char. Это приводит к некорректному отображению в памяти.
исправленный код:
```cpp
#include<iostream>
int main() {
float a=3.14;
float *pj;
pj = (float*)&a;
std::cout << *pj << '\n';
}
```
