Разместите адреса (заполните адресное пространство)(заполните следующую таблицу), для примера представленного ниже:
```cpp
#include <iostream>
#include <vector>
#include <array>
const int CONSTT{3};
int g_val{4};
int g_val1;
int main () {
int v = 3;
std::vector<int> vk;
vk.push_back(1);
vk.push_back(2);
vk.push_back(3);
std::array<int,3> ak;
std::cout << "\n1 ???? is at " << &vk;
std::cout << "\n2 ???? is at " << &vk.front();
std::cout << "\n3 ???? is at " << &vk;
std::cout << "\n4 ???? is at " << &ak.front();
std::cout << "\n5 ???? is at " << &v;
std::cout << "\n6 ???? is at " << malloc(8);
std::cout << "\n7 ???? is at " << &g_val;
std::cout << "\n8 ???? is at " << &g_val1;
std::cout << "\n9 ???? is at " << &CONSTT;
std::cout << "\n10 Text is at " << reinterpret_cast<void*>(main) << "\n";
}
```
```cpp
1 ???? is at 0x...  // стек
2 ???? is at 0x...  // куча
3 ???? is at 0x...  // стек
4 ???? is at 0x...  // стек
5 ???? is at 0x...  //стек
6 ???? is at 0x...  // куча
7 ???? is at 0x...  // data 
8 ???? is at 0x...  // bss
9 ???? is at 0x...  // text
10 Text is at 0x... // text
