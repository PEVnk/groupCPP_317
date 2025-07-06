Разместите адреса (заполните адресное пространство)(заполните следующую таблицу), для примера представленного ниже:
```
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
